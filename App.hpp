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
    std::unordered_map<int, User*> userMap; 


    User addUser(std::string fullLine)
    {
        std::vector<std::string> splitString = split(fullLine, ';');
        std::vector<std::string> splitFriends;

        if(splitString.size() <= 1) 
            return User(0);

        int id = std::stoi(splitString[0]);
        std::string name = splitString[1];

        if(splitString.size() == 3) splitFriends = split(splitString[2], ',');

        return User(id, name, splitFriends);
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

        for(auto&user: listOfUsers) {
            userMap.insert({user.getId(), &user});
        }
    }

    void initalizeFriends() {
        for(auto &OGuser: listOfUsers) {
            for(auto &friendId: OGuser.getTempFriends()) {
                if(userMap.count(std::stoi(friendId))) {
                    OGuser.addFriend(userMap.at(std::stoi(friendId)));
                }
            }
        }
    }

    void addPost(std::string fullLine) {
        std::vector<std::string> splitString = split(fullLine, ';');
        int id = std::stoi(splitString[0]);


        int owner = std::stoi(splitString[1]);
        if(!userMap.count(owner)) return;

        std::string text = splitString[2];
        std::string date = splitString[3];
        std::vector<std::string> likedBy = split(splitString[4], ',');
        int actType = 0;
        std::string actValue = "";

        //std::cout << splitString.size();

        if(splitString.size() == 7) {
            actType = std::stoi(splitString[5]);
            actValue = splitString[6];
        }

        std::vector<User*> likedByUsers;
        for(auto &uID: likedBy) {
            if(userMap.count(std::stoi(uID))) likedByUsers.emplace_back(userMap.at(std::stoi(uID)));
        }

        std::cout << likedByUsers.size();
        Post temp = Post(id, text, likedByUsers.size(), likedByUsers, date, actType, actValue);
        userMap.at(owner)->postPost(temp);
    }

    void initalizePosts() {
        std::ifstream postsFile;
        postsFile.open("Database/Posts.txt");
        std::string line;

        while (getline(postsFile, line))
        {
            addPost(line);
        }
    }

public:
    void run()
    {
        initalizeUsers();       //Create users and store the IDs of their friends
        initalizeFriends();     //Use the IDs to get pointer to friend's user
        initalizePosts();       
        std::cout << listOfUsers[0].posts[0].getLikes();
        for(auto &item: listOfUsers[0].posts[0].getLikedBy()) std::cout << item->getName();
    }
};