#pragma once
#include "Headers/User.hpp"
#include "Headers/Helper.hpp"

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

void User::choosePost()
{
    bool valid = 1;
    std::string choice;
    Post* selectedPost = 0;

    while (1)
    {
        system("clear");
        showPosts(1);
        if (valid)
            std::cout << "\nPlease enter the ID of the post (Enter -1 to exit): ";
        else
            std::cout << "\nPlease enter a valid ID (Enter -1 to exit): ";

        std::cin >> choice;
        if (choice == "-1")
            return;

        if (!isInt(choice))
        {
            valid = 0;
            continue;
        }

        valid = 0;

        for (auto &user : friends)
            for (auto &post : user->getPosts())
                if (stoi(choice) == post->getId())
                {
                    selectedPost = post;
                    valid = 1;
                    break;
                }

        for (auto &page : likedPages)
            for (auto &post : page->getPosts())
                if (stoi(choice) == post->getId())
                {
                    selectedPost = post;
                    valid = 1;
                    break;
                }

        if(valid) break;
    }

    selectedPost->detailedView();
}

void User::showFriends()
{
    char choice;
    bool valid = 1;
    while (1)
    {
        system("clear");
        std::cout << "Press 'q' to go back.\n";
        std::cout << "Press 'f' to view a friend's profile.\n\n";
        std::cout << "Friend's list for " << getName() << "\n\n";

        for (auto &buddy : getFriends())
        {
            if (choice == 'f')
                std::cout << buddy->getId() << " - ";
            std::cout << buddy->getName() << "\n";
        }

        if (choice == 'q')
            break;

        User *buddyAccount = 0;

        if (choice == 'f')
        {
            std::string friendID;
            if (valid)
                std::cout << "\nPlease enter the ID of the friend (-1 to exit): ";
            else
                std::cout << "\nPlease enter a valid ID (-1 to exit): ";

            std::cin >> friendID;

            if (friendID == "-1")
            {
                choice = 'a';
            }

            if (!isInt(friendID))
            {
                valid = 0;
                continue;
            }

            valid = 1;
            for (auto &buddy : getFriends())
            {
                if (std::stoi(friendID) == buddy->getId())
                {
                    buddyAccount = buddy;
                    choice = 'a';
                    valid = 1;
                    break;
                }
                valid = 0;
            }
        }

        else
        {
            choice = getch();
        }

        if (valid && buddyAccount != 0)
        {
            buddyAccount->showProfile();
        }
    }
}

void User::showPages()
{
}

void User::printHome()
{
    system("clear");
    std::cout << "Welcome, " << getName() << "\n\n";
    std::cout << "u: View profile\nf: View friends\nd: View a post in detail\np: View a page\n\n";
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