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
#include "Login.hpp"

class App
{
    Login login;

    void addUser(std::string);
    void addPost(std::string, bool);
    void addComment(std::string, bool);
    void addPage(std::string);

    void initalizeUsers();
    void initalizeComments();
    void initalizeFriends();
    void initalizePosts();
    void initalizePages();

    void cacheData();

    void writeUsers();
    void writePages();
    void writePosts();
    void writeComments();

    void appLoop();


public:
    static std::unordered_map<int, User *> userMap; // uID, and User
    static std::unordered_map<int, Page *> pageMap; // uID, and Page
    static std::unordered_map<int, Post *> postMap; // uID, and Post
    static std::unordered_map<int, Comment *> commentMap;
    static std::unordered_map<std::string, LoginData> loginMap; // Username and password
    static User *currentUser;

    void run();
    ~App();
};

std::unordered_map<int, User *> App::userMap;             // uID, and User
std::unordered_map<int, Page *> App::pageMap;             // uID, and Page
std::unordered_map<int, Post *> App::postMap;             // uID, and Post
std::unordered_map<std::string, LoginData> App::loginMap; // Username and password
std::unordered_map<int, Comment *> App::commentMap;
User *App::currentUser;