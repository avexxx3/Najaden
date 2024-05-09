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

class App {
    std::unordered_map<int, User*> userMap; //uID, and User
    std::unordered_map<int, Post*> postMap; //uID, and Post

    User* addUser(std::string fullLine)
    {
        std::vector<std::string> splitString = split(fullLine, ';');
        std::vector<std::string> splitFriends;

        if(splitString.size() <= 1) 
            return new User(0);

        int id = std::stoi(splitString[0]);
        std::string name = splitString[1];

        if(splitString.size() == 3) splitFriends = split(splitString[2], ',');

        return new User(id, name, splitFriends);
    }

    void initalizeUsers()
    {
        std::ifstream usersFile;
        usersFile.open("Database/Users.txt");
        std::string line;

        while (getline(usersFile, line))
        {
            User* newUser = addUser(line);
            userMap.insert({newUser->getId(), newUser});
        }
    }

    void initalizeFriends() {
        for(auto &OGuser: userMap) {
            for(auto &friendId: OGuser.second->getTempFriends()) {
                if(userMap.count(std::stoi(friendId))) {
                    OGuser.second->addFriend(userMap.at(std::stoi(friendId)));
                }
            }
        }
    }

    void addPost(std::string fullLine) {
        std::vector<std::string> splitString = split(fullLine, ';');

        int id = std::stoi(splitString[0]);
        
        int owner = std::stoi(splitString[1]);
        if(!userMap.count(owner)) return; //When a comment exists but it's parent user doesn't exist

        std::string text = splitString[2];
        std::string date = splitString[3];
        std::vector<std::string> likedBy = split(splitString[4], ','); //Get the uID of all post likers
        int actType = 0;
        std::string actValue = "";

        //Not all posts contain activities
        if(splitString.size() == 7) {
            actType = std::stoi(splitString[5]);
            actValue = splitString[6];
        }

        //If the uID of the user liking the post exists, it is added to the list
        std::vector<User*> likedByUsers;
        for(auto &uID: likedBy) {
            if(userMap.count(std::stoi(uID))) likedByUsers.emplace_back(userMap.at(std::stoi(uID)));
        }

        Post* newPost = new Post(id, text, likedByUsers.size(), likedByUsers, date, actType, actValue);

        postMap.insert({newPost->getId(), newPost});
        userMap.at(owner)->postPost(newPost);
    }

    void initalizePosts() {
        std::ifstream postsFile;
        postsFile.open("Database/Posts.txt");
        std::string line;
        
        getline(postsFile, line); //To not parse the first line, which contains the format of data

        //Each post (contained in a single line) is divided into parts and created accordingly
        while (getline(postsFile, line))
        {
            addPost(line);
        }
    }

    void addComment(std::string fullLine) {
        std::vector<std::string> splitString = split(fullLine, ';');

        int id = std::stoi(splitString[0]);
        
        int postID = std::stoi(splitString[1]);
        if(!postMap.count(postID)) return;

        int userID = std::stoi(splitString[2]);
        if(!userMap.count(userID)) return;

        std::string text = splitString[3];

        Comment* newComment = new Comment(id, text, userMap.at(userID));
        postMap.at(postID)->addComment(newComment);
    }

    void initalizeComments() {
        std::ifstream commentsFile;
        commentsFile.open("Database/Comments.txt");
        std::string line;
        
        getline(commentsFile, line); //To not parse the first line, which contains the format of data

        //Each post (contained in a single line) is divided into parts and created accordingly
        while (getline(commentsFile, line))
        {
            addComment(line);
        }
    }

public:
    void run()
    {
        initalizeUsers();       //Create users and store the IDs of their friends
        initalizeFriends();     //Use the IDs to get pointer to friend's user
        initalizePosts();       //Store all the relevant information of posts
        initalizeComments();    //Stores every comment with their respective owner and post
        std::cout << userMap.at(1)->getName() << " posted: \"" << userMap.at(1)->getPosts()[0]->getText() << "\"\n";
        for(auto &comment: userMap.at(1)->getPosts()[0]->getComments()) {
            std::cout << "\t\t" << comment->getAuthor()->getName() << " commented: \"" << comment->getText() << "\"\n";
        }
    }

    ~App() {
        for(auto user:userMap) {
            for(auto post: user.second->getPosts()) if(post) delete post;
            if(user.second) delete user.second;
        }
    }
};