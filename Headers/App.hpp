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
    std::unordered_map<int, User *> userMap;     // uID, and User
    std::unordered_map<int, Page *> pageMap;     // uID, and Page
    std::unordered_map<int, Post *> userPostMap; // uID, and Post
    std::unordered_map<int, Post *> pagePostMap; 
    
    User *addUser(std::string fullLine);
    void addPost(std::string fullLine, bool isPage);
    void addComment(std::string fullLine);
    Page* addPage(std::string newLine);

    void initalizeUsers();
    void initalizeComments();
    void initalizeFriends();
    void initalizePosts();
    void initalizePages();
    
    void printNajaden();
    
public:
    void run();
    ~App();
};