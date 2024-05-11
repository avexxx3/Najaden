#pragma once
#include "Headers/App.hpp"
#include "Headers/Comment.hpp"
#include "Headers/Helper.hpp"
#include "Headers/Object.hpp"
#include "Headers/Page.hpp"
#include "Headers/Post.hpp"
#include "Headers/User.hpp"
#include <math.h>

User *App::addUser(std::string fullLine)
{
    std::vector<std::string> splitString = split(fullLine, ';');
    std::vector<std::string> splitFriends;

    if (splitString.size() <= 1)
        return new User(0);

    int id = std::stoi(splitString[0]);
    std::string name = splitString[1];
    std::string username = splitString[2];
    std::string password = splitString[3];

    if (splitString.size() == 5)
        splitFriends = split(splitString[4], ',');

    loginMap.insert({username, Login(id, password)});
    return new User(id, name, username, splitFriends);
}

void App::initalizeUsers()
{
    std::ifstream usersFile;
    usersFile.open("Database/Users.txt");
    std::string line;

    getline(usersFile, line);

    while (getline(usersFile, line))
    {
        User *newUser = addUser(line);
        userMap.insert({newUser->getId(), newUser});
    }
}

void App::initalizeFriends()
{
    for (auto &OGuser : userMap)
    {
        for (auto &friendId : OGuser.second->getTempFriends())
        {
            if (userMap.count(std::stoi(friendId)))
            {
                OGuser.second->addFriend(userMap.at(std::stoi(friendId)));
            }
        }
    }
}

void App::addPost(std::string fullLine, bool isPage)
{
    std::vector<std::string> splitString = split(fullLine, ';');

    int id = std::stoi(splitString[0]);

    int owner = std::stoi(splitString[1]);
    if ((!userMap.count(owner) && !isPage) && (!pageMap.count(owner) && isPage))
        return; // When a comment exists but it's parent user doesn't exist

    Entity *author;

    if (isPage)
        author = pageMap.at(owner);
    else
        author = userMap.at(owner);

    std::string text = splitString[2];
    std::string date = splitString[3];
    std::vector<std::string> likedBy = split(splitString[4], ','); // Get the uID of all post likers
    int actType = 0;
    std::string actValue = "";

    // Not all posts contain activities
    if (splitString.size() == 7)
    {
        actType = std::stoi(splitString[5]);
        actValue = splitString[6];
    }

    // If the uID of the user liking the post exists, it is added to the list
    std::vector<User *> likedByUsers;
    for (auto &uID : likedBy)
    {
        if (userMap.count(std::stoi(uID)))
            likedByUsers.emplace_back(userMap.at(std::stoi(uID)));
    }

    Post *newPost = new Post(id, text, likedByUsers.size(), author, likedByUsers, date, actType, actValue);

    postMap.insert({newPost->getId(), newPost});
    if (isPage)
        pageMap.at(owner)->postPost(newPost);
    else
        userMap.at(owner)->postPost(newPost);
}

void App::initalizePosts()
{
    std::ifstream postsFile;
    postsFile.open("Database/Posts.txt");
    std::string line;

    getline(postsFile, line); // To not parse the first line, which contains the format of data

    bool isPage = false;

    // Each post (contained in a single line) is divided into parts and created accordingly
    while (getline(postsFile, line))
    {
        if (line == "")
            continue;
        if (line == "PAGES")
        {
            isPage = true;
            continue;
        }
        addPost(line, isPage);
    }
}

void App::addComment(std::string fullLine, bool isPage)
{
    std::vector<std::string> splitString = split(fullLine, ';');

    int id = std::stoi(splitString[0]);

    int postID = std::stoi(splitString[1]);

    if (!postMap.count(postID))
        return;

    int userID = std::stoi(splitString[2]);

    if ((!userMap.count(userID) && !isPage) || (!pageMap.count(userID) && isPage))
        return;

    std::string text = splitString[3];

    Comment *newComment = new Comment(id, text, userMap.at(userID));

    postMap.at(postID)->addComment(newComment);
    commentMap.insert({id, newComment});
}

void App::initalizeComments()
{
    std::ifstream commentsFile;
    commentsFile.open("Database/Comments.txt");
    std::string line;

    getline(commentsFile, line); // To not parse the first line, which contains the format of data

    bool isPage = false;

    // Each post (contained in a single line) is divided into parts and created accordingly
    while (getline(commentsFile, line))
    {
        if (line == "")
            continue;
        if (line == "PAGES")
        {
            isPage = true;
            continue;
        }
        addComment(line, isPage);
    }
}

void App::comeSailAway()
{
    najaden = new std::string[29]{
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⣤⡼⣷⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠛⠿⠳⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣤⣤⣤⣿⣾⣿⣷⣶⣶⣶⣶⣶⣦⠀⠀⣶⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣿⠀⠀⠀⠀⠹⣏⠉⠉⠉⠙⢛⣛⡛⠛⢋⡙⢷⣄⢈⣿⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣀⣀⣸⣿⣄⣀⣀⣀⣠⡿⣦⠀⠀⠀⠈⢻⡇⠀⠸⣿⠽⢯⠭⠽⠿⠭⠿⠿⢿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠛⢻⡟⠛⠛⠛⠿⣿⠒⠒⠚⣿⣇⣿⣠⣇⣀⣀⣈⣁⠀⠀⠈⣧⣀⣄⡀⠀⠀⠀⠀⠀⣿⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⢸⡄⡀⠀⠸⢦⣤⣴⣿⣿⣿⡯⣿⣿⣿⣭⡭⠿⠽⣶⣧⣼⣼⣹⠀⠀⠀⠀⠀⣸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⢸⡇⡇⣠⠀⠀⠙⢿⡉⠉⠉⠙⢹⠉⠉⠙⢋⣉⣿⣿⣿⣿⣿⣿⣿⣶⣶⣶⣦⣿⣿⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣼⣣⣿⣴⣷⣿⣤⠤⠤⣼⣧⢠⡀⠀⠈⠀⠀⠀⠘⠻⣿⠛⠛⠛⠛⠛⠛⠛⢛⢿⣟⠛⢿⣿⣧⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠶⣿⠿⠿⠭⠭⠯⠿⠿⠽⠭⢽⣿⢸⠇⡖⢀⡄⠀⠀⠀⠀⢸⣗⣄⡀⠀⠀⠀⠀⠘⡆⢿⣷⣌⢿⣧⠙⢧⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠻⡆⡀⠀⠀⠀⠀⠀⠀⠀⣼⣣⣾⣴⣧⣾⣤⣤⣤⣤⣄⣸⢣⡇⣽⠀⠀⠀⠀⠀⠁⠀⢿⡝⢿⣿⡆⠸⡿⣦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣷⢹⠀⣤⠀⠀⢀⣴⣾⡯⠭⢥⣤⣤⣼⣧⣾⣤⣤⣿⣷⣿⣿⣷⣶⣶⡶⠦⢤⣀⣀⠘⣷⠀⢹⣿⡀⠈⢿⣷⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⢸⠆⣿⢸⡆⠀⠙⢿⡍⠉⠉⠉⠉⠉⠉⢹⣿⣿⣿⣿⣿⣿⣿⣿⣷⣷⣶⣶⣶⣿⣿⣿⡞⢦⣹⣷⣤⣹⣿⢿⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣼⢇⣾⣰⣿⣾⣥⡤⠤⢤⣿⠀⠀⠀⠀⠀⠀⠀⠈⢻⡄⠀⠀⠀⠀⠀⢹⡀⠀⠀⠀⢠⡀⠙⣿⡀⠙⢿⣿⣿⡛⠻⠿⣿⣦⡀⠀⠀⡀⠀⠀⠀⠀",
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣿⠀⡇⠀⠀⠀⠀⠀⢰⠄⢿⠀⠀⠀⠀⠀⠀⠁⠀⠀⠀⠀⠁⠀⠹⠷⢶⠾⣯⣿⣿⣦⡀⠈⠙⣷⣤⣾⠇⠀⠀⠀⠀",
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⣧⣀⡀⠀⠀⠀⠀⠀⠀⢀⡟⣰⡇⣾⢀⡄⠀⠀⠈⠀⣸⠈⡇⢀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⡇⢸⡇⠀⠀⠉⠙⣿⣴⣾⣿⡿⠃⠀⠀⠀⠀⠀",
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⣾⡆⣆⠀⠀⠀⠀⣰⣿⣱⣿⣴⡿⣾⣷⡶⣶⠦⢤⡟⣸⠃⡼⢠⡆⢀⠀⢀⡀⠀⣰⠇⣠⡟⢀⡿⠁⠀⢀⣠⣾⣿⣿⠟⠉⠀⠀⠀⠀⠀⠀⠀",
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⣻⠃⡾⠀⠠⢶⣿⠿⠿⠿⠿⠿⢿⣿⣿⣿⣿⣿⣿⣴⣿⣿⣷⣿⣦⣿⣦⣾⣷⣾⣣⡼⣋⣤⡞⠀⣠⣴⣻⣷⠟⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣼⣿⣟⣚⣛⣋⣿⣿⣏⣉⣉⣙⣛⣦⣼⠋⢹⡿⣿⠿⠿⠿⠿⠿⠿⠿⢿⡿⣿⢿⣿⠿⣿⣿⣿⣿⣷⠾⣿⡿⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⠻⠛⠛⠛⠛⠛⠛⣿⠻⡟⠛⠛⠛⠛⠛⠛⠃⢸⠇⢸⠀⠀⠀⠀⢰⣷⣶⣾⣶⣿⠟⣿⣠⡿⢷⣟⡟⢹⡟⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⣦⣤⣀⡀⠀⣿⠀⡇⠀⠀⠀⠀⠀⠀⠀⢸⡄⢸⠀⠀⠀⠀⢀⣸⣿⣿⡿⠿⠛⣿⣁⣴⠾⣻⡇⣾⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢷⣄⣹⣉⠙⠛⢾⠷⠶⠶⣶⣤⣤⣤⣴⣾⣷⠾⠶⠶⠾⣿⠿⣽⣽⣿⣶⡾⠟⠋⠡⠴⠚⣻⣿⠇⣀⣀⣠⢶⣶⢦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢻⣎⣙⡛⠛⠿⠷⢶⣶⣶⣿⣶⣾⣾⣿⣿⣶⡾⠿⣿⡟⠛⣻⣿⣿⢿⣦⣄⡀⣀⣠⢴⣿⣿⡟⠙⢯⣻⣶⢿⡿⣧⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠛⣯⠉⠓⣒⡆⠀⠉⠙⣿⡛⠛⠛⣛⣛⣻⣀⠀⠉⢰⢟⣟⠛⣻⣦⣤⣍⠻⣆⣠⣿⣿⠏⣠⣤⣼⡿⠋⣶⣷⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        "⠀⠀⠀⠀⠀⠀⣠⣄⠀⠀⢀⣤⠖⠀⠀⣈⣳⣄⠉⠉⣹⣤⠞⠉⠛⠶⣬⣭⣭⣭⣽⡟⢶⣼⣿⣽⠆⣿⣿⣍⡍⠀⠽⠿⠛⢡⠞⢫⣽⣝⣿⡆⠻⣯⠾⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        "⢀⠀⣀⣠⠴⠚⠁⠈⠻⠿⢯⣤⣤⠄⠀⠈⠉⠉⠉⠉⠉⠀⠀⠀⢀⣀⣀⣠⡴⠟⠉⠀⠀⠈⠉⠛⠶⠾⠿⠿⠷⠀⠀⠀⠀⠉⠀⠐⣶⣿⣿⡇⠀⠑⠶⣤⣠⣴⠶⠟⠿⠶⢤⣤⡶",
        "⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣀⣀⡼⣦⣀⡀⠀⠀⠀⠀⠀⣰⣆⠀⠀⠀⠀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠛⠛⠛⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠀⠀⠀⠀⠙⠦⠤⠤⠴⠛⠁⠙⠷⠤⠴⠞⠋⠛⠦⠤⠴⠆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣾⣦⡀⠀⠀⠀⢠⣄⠀⠀⠀⠀⠀⠀",
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠒⠒⠒⠛⠉⠀⠉⣟⣓⣶⡶⠛⠙⠳⠦⣤⠄⠀⠀"};
}

void App::printNajaden(int index, std::string message, int substring, int offset)
{
    if (index == -1)
    {
        system("clear");
        std::cout << "\n\n\n";
        for (int i = 0; i < 29; i++)
        {
            for (int j = 0; j < offset; j++)
                std::cout << ' ';
            if (offset < 103)
                std::cout << najaden[i].substr(substring) << '\n';
            else
                std::cout << najaden[i].substr(0, najaden[i].size() - (offset - 106) * 3 - 12) << '\n';
        }
        return;
    }

    std::cout << najaden[index] << '\t' << message;
    switch (index)
    {
    case 12:
    {
        if (status[1] != "")
            std::cout << "\t\t\t\t\t" << status[0];
        break;
    }

    case 13:
    {
        if (status[1] == "")
            std::cout << "\t\t\t\t\t" << status[0];
        std::cout << "\t\t\t\t\t" << status[1];
        break;
    }

    case 14:
    {
        if (isPasswording || isLogging)
            std::cout << "\t\t\t\t\t" << "Login: " << userLogin;
        break;
    }

    case 15:
    {
        if (isPasswording)
        {
            std::cout << "\t\t\t\t\t" << "Password: ";
            for (int i = 0; i < userPassword.size(); i++)
                std::cout << '*';
        }
    }
    }

    std::cout << '\n';
}

void App::printLogin(int logoOffset)
{
    int index = 0;

    std::string logo[] = {
        "\t\t\t.   .                .          ",
        "\t\t\t|\\  |      o         |          ",
        "\t\t\t| \\ | .-.  . .-.  .-.| .-. .--. ",
        "\t\t\t|  \\|(   ) |(   )(   |(.-' |  | ",
        "\t\t\t'   ' `-'`-| `-'`-`-'`-`--''  `-",
        "\t\t\t-----------;--------------------",
        "\t\t\t        `-'  "};

    system("clear");
    std::cout << "\n\n\n";
    for (int i = 0; i < logoOffset; i++)
    {
        printNajaden(index++, logo[i]);
    }

    if (logoOffset == 7)
    {
        printNajaden(index++);
        printNajaden(index++);
        printNajaden(index++, "ID\tUsername");
        printNajaden(index++, "--\t--------");

        for (auto &user : userMap)
        {
            std::string temp = std::to_string(user.second->getId()) + "\t" + user.second->getUsername();
            printNajaden(index++, temp);
        }
    }

    while (index < 29)
        printNajaden(index++);
}

Page *App::addPage(std::string newLine)
{
    std::vector<std::string> splitString = split(newLine, ';');

    int pageID = std::stoi(splitString[0]);
    int uID = std::stoi(splitString[1]);
    if (!userMap.count(uID))
        return new Page;

    std::string text = splitString[2];

    return new Page(pageID, userMap.at(uID), text);
}

void App::initalizePages()
{
    std::ifstream pagesFile;
    pagesFile.open("Database/Pages.txt");
    std::string line;

    getline(pagesFile, line);

    while (getline(pagesFile, line))
    {
        Page *newPage = addPage(line);
        pageMap.insert({newPage->getId(), newPage});
    }
}

void App::startupAnimation()
{
    for (int i = 192; i >= 0; i = i - 18)
    {
        system("clear");
        printNajaden(-1, "", i);
        system("sleep 0.3");
    }

    for (int i = 0; i < 7; i += 2)
    {
        printLogin(i);
        system("sleep 0.3");
    }

    isLogging = true;
}

bool App::promptCreate()
{
    char choice;
    while (1)
    {
        status[0] = "Account not found.";
        status[1] = "Would you like to create one? (y/n)";
        printLogin();
        choice = getch();
        switch (tolower(choice))
        {
        case 'y':
        {
            status[0] = status[1] = "";
            return 1;
        }
        case 'n':
        {
            status[0] = status[1] = "";
            return 0;
        }
        }
    }
}

void App::loginUser()
{
    char choice;
    while (1)
    {
        while (isLogging)
        {
            printLogin();
            choice = getch();
            switch (tolower(choice))
            {
            case 'a' ... 'z':
            case '0' ... '9':
            {
                userLogin += choice;
                break;
            }

            case 127:
            {
                userLogin = userLogin.substr(0, userLogin.size() - 1);
                break;
            }

            case 10:
            {
                if (loginMap.count(userLogin))
                {
                    isLogging = false;
                    isPasswording = true;
                    status[0] = "";
                }
                else if (promptCreate())
                {
                    return;
                }

                break;
            }
            }
        }

        while (isPasswording)
        {
            printLogin();
            choice = getch();
            switch (tolower(choice))
            {
            case 'a' ... 'z':
            case '0' ... '9':
            {
                userPassword += choice;
                break;
            }

            case 127:
            {
                if (userPassword.size() == 0)
                {
                    isPasswording = false;
                    isLogging = true;
                    status[0] = "";
                }
                userPassword = userPassword.substr(0, userPassword.size() - 1);
                break;
            }

            case 10:
            {
                if (loginMap.at(userLogin).password == userPassword)
                {
                    currentUser = userMap.at(loginMap.at(userLogin).id);
                    isLogging = false;
                    isPasswording = false;
                    status[0] = "Logged in successfully.";
                    status[1] = "You will be redirected shortly..";
                    printLogin();
                    system("sleep 1");
                    return;
                }
                else
                    status[0] = "Invalid password.";
                break;
            }
            }
        }
    }
}

void App::loginAnimation()
{
    for (int i = 0; i < 168; i += 16)
    {
        printNajaden(-1, "", 0, i);
        system("sleep 0.4");
    }
    system("clear");
}

void App::appLoop()
{
    while (1)
    {
        currentUser->printHome();
        char choice = getch();

        switch (choice)
        {
        case 'u':
        {
            currentUser->showProfile();
            break;
        }

        case 'f':
        {
            currentUser->showFriends();
            break;
        }

        case 'd':
        {
            currentUser->choosePost();
            break;
        }

        case 'p':
        {
            currentUser->showPages();
            break;
        }
        default:
            break;
        }
    }
}

App::App()
{
}

void App::run()
{
    initalizeUsers(); // Create users and store the IDs of their friends
    initalizePages();
    initalizeFriends();  // Use the IDs to get pointer to friend's user
    initalizePosts();    // Store all the relevant information of posts
    initalizeComments(); // Stores every comment with their respective owner and post

    comeSailAway();
    // startupAnimation();
    // loginUser();
    // loginAnimation();
    currentUser = userMap[2];
    appLoop();
}

App::~App()
{
    for (auto &user : userMap)
        delete user.second;
    for (auto &post : postMap)
        delete post.second;
    for (auto &page : pageMap)
        delete page.second;
    delete najaden;
}