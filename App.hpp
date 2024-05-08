#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

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

    void addUser(std::string fullLine)
    {
        std::vector<std::string> splitString = split(fullLine, ';');

        int id = std::stoi(splitString[0]);
        std::string name = splitString[1];
        std::vector<std::string> tempFriends = split(splitString[2], ',');
        listOfUsers.emplace_back(User(id, name, tempFriends));
    }

    void initalizeUsers()
    {
        std::ifstream usersFile;
        usersFile.open("Database/Users.txt");
        std::string line;
        while (getline(usersFile, line))
        {
            addUser(line);
        }
    }

public:
    void run()
    {
        initalizeUsers();
    }
};