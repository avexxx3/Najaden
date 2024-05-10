#pragma once
#include "Headers/User.hpp"

User::User(int id, std::string name, std::vector<std::string> temporaryFriends) : Entity(id, name), temporaryFriends(temporaryFriends) {}

void User::addFriend(User *newFriend)
{
    friends.emplace_back(newFriend);
}

void User::likePage(Page *newPage)
{
    likedPages.emplace_back(newPage);
}

void User::printHome()
{
    for (auto &user : friends)
    {
        for (auto &post : user->getPosts())
        {
            post->printPost();
        }
    }
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