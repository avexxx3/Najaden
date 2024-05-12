#pragma once
#include "Headers/App.hpp"
#include "Headers/Comment.hpp"
#include "Headers/Helper.hpp"
#include "Headers/Object.hpp"
#include "Headers/Page.hpp"
#include "Headers/Post.hpp"
#include "Headers/User.hpp"
#include "Login.cpp"
#include "Headers/Login.hpp"
#include <math.h>

void App::initalizeUsers()
{
    std::ifstream usersFile;
    usersFile.open("Database/Users.txt");
    std::string line;

    getline(usersFile, line);

    while (getline(usersFile, line))
    {
        addUser(line);
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

void App::initalizePages()
{
    std::ifstream pagesFile;
    pagesFile.open("Database/Pages.txt");
    std::string line;

    getline(pagesFile, line);

    while (getline(pagesFile, line))
    {
        addPage(line);
    }
}

void App::addUser(std::string fullLine)
{
    std::vector<std::string> splitString = Helper::getInstance()->split(fullLine, ';');
    std::vector<std::string> splitFriends;

    if (splitString.size() <= 1)
        return;

    int id = std::stoi(splitString[0]);
    std::string name = splitString[1];
    std::string username = splitString[2];
    std::string password = splitString[3];

    if (splitString.size() == 5)
        splitFriends = Helper::getInstance()->split(splitString[4], ',');

    loginMap.insert({username, LoginData(id, password)});

    User *newUser = new User(id, name, username, splitFriends);
    userMap.insert({newUser->getId(), newUser});
}

void App::addPost(std::string fullLine, bool isPage)
{
    std::vector<std::string> splitString = Helper::getInstance()->split(fullLine, ';');

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
    bool isMemory;
    if(splitString[3] == "0") isMemory = 0; else isMemory = 1; 
    std::string dateText = splitString[4];
    std::vector<std::string> likedBy = Helper::getInstance()->split(splitString[5], ','); // Get the uID of all post likers
    int actType = 0;
    std::string actValue = "";

    // Not all posts contain activities
    if (splitString.size() == 8)
    {
        actType = std::stoi(splitString[6]);
        actValue = splitString[7];
    }

    // If the uID of the user liking the post exists, it is added to the list
    std::vector<User *> likedByUsers;
    for (auto &uID : likedBy)
    {
        if (userMap.count(std::stoi(uID)))
            likedByUsers.emplace_back(userMap.at(std::stoi(uID)));
    }

    Date* date = new Date(stoi(dateText.substr(0, 2)), stoi(dateText.substr(2, 2)), stoi(dateText.substr(4, 2)), stoi(dateText.substr(6, 2)), stoi(dateText.substr(8, 2)));

    Post *newPost = new Post(id, text, likedByUsers.size(), author, likedByUsers, date, actType, actValue, isMemory);

    postMap.insert({newPost->getId(), newPost});
    if (isPage)
        pageMap.at(owner)->addPost(newPost);
    else
        userMap.at(owner)->addPost(newPost);
}

void App::addComment(std::string fullLine, bool isPage)
{
    std::vector<std::string> splitString = Helper::getInstance()->split(fullLine, ';');

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

void App::addPage(std::string newLine)
{
    std::vector<std::string> splitString = Helper::getInstance()->split(newLine, ';');

    int pageID = std::stoi(splitString[0]);
    int uID = std::stoi(splitString[1]);
    if (!userMap.count(uID))
        return;

    std::string text = splitString[2];
    std::vector<std::string> likedBy = Helper::getInstance()->split(splitString[3], ',');

    Page *newPage = new Page(pageID, userMap.at(uID), text, likedBy.size());

    for (auto &liker : likedBy)
    {
        if (userMap.count(stoi(liker)))
            userMap.at(stoi(liker))->likePage(newPage);
    }

    pageMap.insert({newPage->getId(), newPage});
}

void App::cacheData()
{
    initalizeUsers();
    initalizeFriends();
    initalizePages();
    initalizePosts();
    initalizeComments();
}

void App::appLoop()
{
    while (1)
    {
        currentUser->printHome();
        char choice = tolower(Helper::getInstance()->getch());

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
            currentUser->chooseDetailedPost();
            break;
        }

        case 27: {
            Helper::getInstance()->writeData();
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

void App::run()
{
    cacheData();
    currentUser = userMap.at(2);
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
    for (auto &comment : commentMap)
        delete comment.second;
}