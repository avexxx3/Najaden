#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <unordered_map>

#include "User.hpp"
#include "Post.hpp"
#include "Comment.hpp"
#include "Page.hpp"
#include "Helper.hpp"

class User;
class Post;
class Comment;
class Page;

class App
{
    std::vector<User> listOfUsers;

    User addUser(std::string fullLine)
    {
        std::vector<std::string> splitString = split(fullLine, ';');
        return User(std::stoi(splitString[0]), splitString[1], split(splitString[2], ','));
    }

    void initalizeUsers()
    {
        std::ifstream usersFile;
        usersFile.open("Database/Users.txt");
        std::string line;

        while (getline(usersFile, line))
        {
            listOfUsers.emplace_back(addUser(line));
        }

    }

    void initalizeFriends() {
        std::unordered_map<int, User*> userMap; 

        for(auto&user: listOfUsers) {
            userMap.insert({user.getId(), &user});
        }

        for(auto &OGuser: listOfUsers) {
            for(auto &friendId: OGuser.getTempFriends()) {
                if(userMap.count(std::stoi(friendId))) {
                    OGuser.addFriend(userMap.at(std::stoi(friendId)));
                }
            }
        }
    }

public:
    void run()
    {
        initalizeUsers();
        initalizeFriends();
    }
};