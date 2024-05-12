#pragma once
#include "Headers/User.hpp"
#include "Headers/Helper.hpp"
#include "Headers/App.hpp"
#include <algorithm>

User::User(int id, std::string name, std::string username, std::vector<std::string> temporaryFriends) : Entity(id, name), temporaryFriends(temporaryFriends), username(username) {}

void User::addFriend(User *newFriend)
{
    friends.emplace_back(newFriend);
}

void User::likePage(Page *newPage)
{
    likedPages.emplace_back(newPage);
}

void User::showPosts(bool showId)
{
    for (auto &user : friends)
        for (auto &post : user->getPosts())
            post->printPost(showId);

    for (auto &page : likedPages)
        for (auto &post : page->getPosts())
            post->printPost(showId);
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
            if(user.second->getId() == getId()) continue;
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
            if(user.second->getId() == getId()) continue;
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
            if(friends.size() != App::userMap.size()) std::cout << "Press 'N' to add a new friend.\n";
            if (friends.size() != 0)
            {
                std::cout << "Press 'R' to remove a friend.\n";
                std::cout << "Press 'F' to view a friend's profile.\n\n";
                std::cout << "Friend's list for " << getName() << "\n";
            }
            else {
                std::cout << "\nFriendless :(\n";
            }
        }

        std::cout << '\n';

        for (auto &buddy : getFriends())
        {
            if(buddy->getId() == getId()) continue;
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
                if(buddy->getId() == getId()) continue;
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

void User::dislikePagesMenu() {
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

void User::likePagesMenu() {
    std::string choice = "";
    std::string status = "";
    while (1)
    {
        system("clear");
        std::cout << "Press ESC to go back\n\n";
        for (auto &user : App::pageMap)
        {
            if(user.second->getId() == getId()) continue;
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
            if(user.second->getId() == getId()) continue;
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
            if(likedPages.size() != App::pageMap.size()) std::cout << "Press 'N' to like a new page.\n";
            if (likedPages.size() != 0)
            {
                std::cout << "Press 'R' to dislike a page.\n";
                std::cout << "Press 'F' to view a page's posts.\n\n";
                std::cout << "Liked page's list for " << getName() << "\n";
            }
            else {
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

        if (choice == 'r' && friends.size() != 0)
        {
            dislikePagesMenu();
            choice = 'a';
            continue;
        }

        if (choice == 'n' && friends.size() != App::userMap.size())
        {
            likePagesMenu();
            choice = 'a';
            continue;
        }

        if (choice == 'f' && friends.size() != 0)
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

            for (auto &page: likedPages)
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
    std::cout << "Press 'U' to view profile.\nPress 'F' to view friends.\nPress 'D' to view a post in detail.\nPress 'P' to view pages\n\n";
    showPosts();
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