#pragma once
#include "Headers/User.hpp"
#include "Headers/Helper.hpp"
#include "Headers/App.hpp"
#include <algorithm>

User::User(int id, std::string name, std::string username, std::vector<std::string> temporaryFriends)
    : Entity(id, name, "User"), temporaryFriends(temporaryFriends), username(username) {}

void User::addFriend(User *newFriend)
{
    friends.emplace_back(newFriend);
}

void User::likePage(Page *newPage)
{
    likedPages.emplace_back(newPage);
}

void User::showPosts(bool showId, bool timeSensitive)
{

    for (auto &user : friends)
        for (auto &post : user->getPosts())
            if (((timeSensitive && post->getDate()->is24h()) || !timeSensitive) && !post->getMemory())
                post->printPost(showId);

    for (auto &page : likedPages)
        for (auto &post : page->getPosts())
            if (((timeSensitive && post->getDate()->is24h()) || !timeSensitive) && !post->getMemory())
                post->printPost(showId);

    for (auto &post : getPosts())
        if (((timeSensitive && post->getDate()->is24h()) || !timeSensitive) && !post->getMemory())
            post->printPost(showId, 1);
}

void User::chooseDetailedPost()
{
    std::string choice = "";
    Post *selectedPost = 0;

    while (1)
    {
        system("clear");
        std::cout << "Press ESC to go back\n\n";
        showPosts(1);

        std::cout << "\nPlease enter the ID of the post: " << choice;

        char tempInput;
        tempInput = Helper::getInstance()->getch();

        switch (tempInput)
        {
        case 27:
            return;

        case 127:
            choice = choice.substr(0, choice.size() - 1);
            continue;
            break;

        case '0' ... '9':
            choice += tempInput;
            continue;
            break;

        default:
            if (tempInput != 10 || choice.size() == 0)
                continue;
        }

        for (auto &post : getPosts())
            if (stoi(choice) == post->getId())
            {
                post->showDetailedView();
                break;
            }

        for (auto &user : friends)
            for (auto &post : user->getPosts())
                if (stoi(choice) == post->getId())
                {
                    post->showDetailedView();
                    break;
                }

        for (auto &page : likedPages)
            for (auto &post : page->getPosts())
                if (stoi(choice) == post->getId())
                {
                    post->showDetailedView();
                    break;
                }

        choice = "";
    }
}

void User::addFriendsMenu()
{
    std::string choice = "";
    std::string status = "";
    while (1)
    {
        system("clear");
        std::cout << "Press ESC to go back\n\n";
        for (auto &user : App::userMap)
        {
            if (user.second->getId() == getId())
                continue;
            bool present = 0;
            for (auto &realFriend : App::currentUser->getFriends())
                if (realFriend->getId() == user.second->getId())
                {
                    present = 1;
                    break;
                }

            if (!present)
                std::cout << user.first << "\t-\t" << user.second->getName() << '\n';
        }

        std::cout << "\n\nPlease enter the ID of the friend you want to add: " << choice;

        char tempInput = Helper::getInstance()->getch();

        switch (tempInput)
        {
        case 27:
            return;

        case 127:
            choice = choice.substr(0, choice.size() - 1);
            continue;
            break;

        case '0' ... '9':
            choice += tempInput;
            continue;
            break;

        default:
            if (tempInput != 10 || choice.size() == 0)
                continue;
        }

        for (auto &user : App::userMap)
        {
            if (user.second->getId() == getId())
                continue;
            if (stoi(choice) == user.second->getId())
            {
                status = "";
                for (auto &existingFriend : App::currentUser->getFriends())
                {
                    if (existingFriend->getId() == user.second->getId())
                    {
                        status = "The user is already a friend.\n";
                        break;
                    }
                }

                choice = "";
                if (status == "The user is already a friend.\n")
                    break;

                App::currentUser->addFriend(user.second);
                return;
            }

            status = "User doesn't exist";
        }

        if (status == "User doesn't exist")
            choice = "";
    }
}

void User::removeFriendsMenu()
{
    std::string choice = "";
    std::string status = "";
    while (1)
    {
        system("clear");
        std::cout << "Press ESC to go back\n\n";

        for (auto &realFriend : friends)
        {
            std::cout << realFriend->getId() << "\t-\t" << realFriend->getName() << '\n';
        }

        std::cout << "\n\nPlease enter the ID of the friend you want to remove: " << choice;

        char tempInput = Helper::getInstance()->getch();

        switch (tempInput)
        {
        case 27:
            return;

        case 127:
            choice = choice.substr(0, choice.size() - 1);
            continue;
            break;

        case '0' ... '9':
            choice += tempInput;
            continue;
            break;

        default:
            if (tempInput != 10 || choice.size() == 0)
                continue;
        }

        for (auto &realFriend : friends)
        {
            if (realFriend->getId() == stoi(choice))
            {
                friends.erase(std::find(friends.begin(), friends.end(), realFriend));
                return;
            }
        }

        choice = "";
    }
}

void User::showFriends()
{
    char choice;
    bool valid = 1;
    std::string friendID = "";
    while (1)
    {
        system("clear");
        std::cout << "Press ESC to go back.\n";
        if (choice != 'f' || friends.size() == 0)
        {
            if (friends.size() != App::userMap.size())
                std::cout << "Press 'N' to add a new friend.\n";
            if (friends.size() != 0)
            {
                std::cout << "Press 'R' to remove a friend.\n";
                std::cout << "Press 'F' to view a friend's profile.\n\n";
                std::cout << "Friend's list for " << getName() << "\n";
            }
            else
            {
                std::cout << "\nFriendless :(\n";
            }
        }

        std::cout << '\n';

        for (auto &buddy : getFriends())
        {
            if (buddy->getId() == getId())
                continue;
            if (choice == 'f')
                std::cout << buddy->getId() << " - ";
            std::cout << buddy->getName() << "\n";
        }

        if (choice == 27)
            break;

        if (choice == 'r' && friends.size() != 0)
        {
            removeFriendsMenu();
            choice = 'a';
            continue;
        }

        if (choice == 'n' && friends.size() != App::userMap.size())
        {
            addFriendsMenu();
            choice = 'a';
            continue;
        }

        if (choice == 'f' && friends.size() != 0)
        {
            std::cout << "\nPlease enter the ID of the friend you want to view: " << friendID;

            char tempInput;
            tempInput = Helper::getInstance()->getch();

            switch (tempInput)
            {
            case 27:
                choice = 'a';
                continue;

            case 127:
                friendID = friendID.substr(0, friendID.size() - 1);
                continue;
                break;

            case '0' ... '9':
                friendID += tempInput;
                continue;
                break;

            default:
                if (tempInput != 10 || friendID.size() == 0)
                    continue;
            }

            for (auto &buddy : getFriends())
            {
                if (buddy->getId() == getId())
                    continue;
                if (std::stoi(friendID) == buddy->getId())
                {
                    buddy->showProfile();
                    choice = 'a';
                    break;
                }
            }

            friendID = "";
        }

        else
        {
            choice = tolower(Helper::getInstance()->getch());
        }
    }
}

void User::dislikePagesMenu()
{
    std::string choice = "";
    std::string status = "";
    while (1)
    {
        system("clear");
        std::cout << "Press ESC to go back\n\n";

        for (auto &realFriend : likedPages)
        {
            std::cout << realFriend->getId() << "\t-\t" << realFriend->getName() << '\n';
        }

        std::cout << "\n\nPlease enter the ID of the page you want to dislike: " << choice;

        char tempInput = Helper::getInstance()->getch();

        switch (tempInput)
        {
        case 27:
            return;

        case 127:
            choice = choice.substr(0, choice.size() - 1);
            continue;
            break;

        case '0' ... '9':
            choice += tempInput;
            continue;
            break;

        default:
            if (tempInput != 10 || choice.size() == 0)
                continue;
        }

        for (auto &realFriend : likedPages)
        {
            if (realFriend->getId() == stoi(choice))
            {
                likedPages.erase(std::find(likedPages.begin(), likedPages.end(), realFriend));
                return;
            }
        }

        choice = "";
    }
}

void User::showProfile()
{
    while (1)
    {
        system("clear");
        std::cout << "Press ESC to go back.\nPress 'P' to create a new post.\nPress 'M' to share a post as a memory\n\n\n";
        std::cout << getName() << "'s Profile\n\n\nPOSTS:\n\n";

        for (auto &post : getPosts())
        {
            if (!post->getMemory())
                post->printPost();
        }

        std::cout << "MEMORIES:\n\n";

        for (auto &post : getPosts())
        {
            if (post->getMemory())
                post->printPost();
        }

        char choice = tolower(Helper::getInstance()->getch());
        if (choice == 27)
            break;
        if (choice == 'p')
        {
            std::string text = "";
            char newChoice = ' ';
            char tempInput;
            while (1)
            {
                if (choice != 'p')
                    break;

                system("clear");
                std::cout << "Press ESC to go back.\n\nPlease enter the text for the post:\n"
                          << text;
                if (newChoice == ' ')
                    tempInput = Helper::getInstance()->getch();
                switch (tempInput)
                {

                case 27:
                    choice = ' ';
                    continue;

                case 127:
                    text = text.substr(0, text.size() - 1);
                    continue;

                case 10:
                    if (text.size() == 0)
                        continue;
                    break;

                default:
                    text += tempInput;
                    continue;
                }

                if (newChoice == 27)
                {
                    choice = ' ';
                    continue;
                }

                if (newChoice != 'y' && newChoice != 'n')
                {
                    std::cout << "\n\nPress 'Y' if you want to enter an activity. If not, press 'N'\n";
                    newChoice = tolower(Helper::getInstance()->getch());
                    continue;
                }

                int activityType = 0;
                if (newChoice == 'y')
                {
                    std::cout << "\n\nPlease enter the type of activity.\n1. Feeling\n2. Thinking about\n3. Making\n4. Celebrating\n";
                    char newerChoice = Helper::getInstance()->getch();
                    switch (newerChoice)
                    {
                    case 27:
                        choice = ' ';
                        continue;
                    case '1':
                        activityType = 1;
                        break;
                    case '2':
                        activityType = 2;
                        break;
                    case '3':
                        activityType = 3;
                        break;
                    case '4':
                        activityType = 4;
                        break;
                    default:
                        continue;
                    }
                }

                std::string activityValue = "";
                if (activityType != 0 && newChoice == 'y')
                {
                    std::cout << "Please enter the value you want associated with the activity: ";
                    getline(std::cin, activityValue);
                }

                int i = 1;
                while (App::postMap.count(i))
                    i++;
                Post *newPost = new Post(i, text, 0, this, {}, Helper::getInstance()->getCurrentDate(), activityType, activityValue);
                App::postMap.insert({i, newPost});
                addPost(newPost);
                break;
            }
            choice = 'a';
        }

        if (choice == 'm')
        {
            std::string ID = "";
            Post *selectedPost = 0;

            while (1)
            {
                system("clear");
                std::cout << "Press ESC to go back\n\n";

                for (auto &post : getPosts())
                    post->printPost(1);

                std::cout << "\nPlease enter the ID of the post: " << ID;

                char tempInput;
                tempInput = Helper::getInstance()->getch();

                switch (tempInput)
                {
                case 27:
                    return;

                case 127:
                    ID = ID.substr(0, ID.size() - 1);
                    continue;
                    break;

                case '0' ... '9':
                    ID += tempInput;
                    continue;
                    break;

                default:
                    if (tempInput != 10 || ID.size() == 0)
                        continue;
                }

                bool valid = 0;
                for (auto &post : getPosts())
                {
                    if (post->getId() == stoi(ID))
                    {
                        post->setMemory();
                        valid = 1;
                    }
                }
                if (valid)
                    break;
            }

            choice = ' ';
        }
    }
}

void newPost()
{
}

void User::likePagesMenu()
{
    std::string choice = "";
    std::string status = "";
    while (1)
    {
        system("clear");
        std::cout << "Press ESC to go back\n\n";
        for (auto &user : App::pageMap)
        {
            if (user.second->getId() == getId())
                continue;
            bool present = 0;
            for (auto &realFriend : likedPages)
                if (realFriend->getId() == user.second->getId())
                {
                    present = 1;
                    break;
                }

            if (!present)
                std::cout << user.first << "\t-\t" << user.second->getName() << '\n';
        }

        std::cout << "\n\nPlease enter the ID of the page you want to like: " << choice;

        char tempInput = Helper::getInstance()->getch();

        switch (tempInput)
        {
        case 27:
            return;

        case 127:
            choice = choice.substr(0, choice.size() - 1);
            continue;
            break;

        case '0' ... '9':
            choice += tempInput;
            continue;
            break;

        default:
            if (tempInput != 10 || choice.size() == 0)
                continue;
        }

        for (auto &user : App::pageMap)
        {
            if (user.second->getId() == getId())
                continue;
            if (stoi(choice) == user.second->getId())
            {
                status = "";
                for (auto &existingFriend : likedPages)
                {
                    if (existingFriend->getId() == user.second->getId())
                    {
                        status = "The user is already a friend.\n";
                        break;
                    }
                }

                choice = "";
                if (status == "The user is already a friend.\n")
                    break;

                likePage(user.second);
                return;
            }

            status = "User doesn't exist";
        }

        if (status == "User doesn't exist")
            choice = "";
    }
}

void User::showPages()
{
    char choice;
    bool valid = 1;
    std::string pageID = "";
    while (1)
    {
        system("clear");
        std::cout << "Press ESC to go back.\n";
        if (choice != 'f' || likedPages.size() == 0)
        {
            if (likedPages.size() != App::pageMap.size())
                std::cout << "Press 'N' to like a new page.\n";
            if (likedPages.size() != 0)
            {
                std::cout << "Press 'R' to dislike a page.\n";
                std::cout << "Press 'F' to view a page's posts.\n\n";
                std::cout << "Liked page's list for " << getName() << "\n";
            }
            else
            {
                std::cout << "\nSocially inept :(\n";
            }
        }

        std::cout << '\n';

        for (auto &page : likedPages)
        {
            if (choice == 'f')
                std::cout << page->getId() << " - ";
            std::cout << page->getName() << ": Owned by " << page->getOwner()->getName() << '\n';
        }

        if (choice == 27)
            break;

        if (choice == 'r' && likedPages.size() != 0)
        {
            dislikePagesMenu();
            choice = 'a';
            continue;
        }

        if (choice == 'n' && likedPages.size() != App::pageMap.size())
        {
            likePagesMenu();
            choice = 'a';
            continue;
        }

        if (choice == 'f' && likedPages.size() != 0)
        {
            std::cout << "\nPlease enter the ID of the page you want to view: " << pageID;

            char tempInput;
            tempInput = Helper::getInstance()->getch();

            switch (tempInput)
            {
            case 27:
                choice = 'a';
                continue;

            case 127:
                pageID = pageID.substr(0, pageID.size() - 1);
                continue;
                break;

            case '0' ... '9':
                pageID += tempInput;
                continue;
                break;

            default:
                if (tempInput != 10 || pageID.size() == 0)
                    continue;
            }

            for (auto &page : likedPages)
            {
                if (std::stoi(pageID) == page->getId())
                {
                    page->showProfile();
                    choice = 'a';
                    break;
                }
            }

            pageID = "";
        }

        else
        {
            choice = tolower(Helper::getInstance()->getch());
        }
    }
}

void User::printHome()
{
    system("clear");
    std::cout << "Welcome, " << getName() << "\n\n";
    std::cout << "Press ESC to save any and all changes.\nPress 'U' to view profile.\nPress 'F' to view friends.\nPress 'D' to view a post in detail.\nPress 'P' to view pages\n\n";
    showPosts(0, 1);
}

std::vector<User *> User::getFriends() const
{
    return friends;
}

std::vector<Page *> User::getLikedPages() const
{
    return likedPages;
}

std::vector<std::string> User::getTempFriends() const
{
    return temporaryFriends;
}

std::string User::getUsername() const
{
    return username;
}