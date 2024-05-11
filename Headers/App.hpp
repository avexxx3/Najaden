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

struct Login
{
    int id;
    std::string password;
    Login(int id, std::string password) : id(id), password(password) {}
};
class App
{
    std::string *najaden;
    std::string userLogin = "";
    std::string userPassword = "";
    std::string status[2] = {"", ""};

    bool isLogging = false;
    bool isPasswording = false;

    User *addUser(std::string);
    void addPost(std::string, bool);
    void addComment(std::string, bool);
    Page *addPage(std::string);

    void initalizeUsers();
    void initalizeComments();
    void initalizeFriends();
    void initalizePosts();
    void initalizePages();

    void comeSailAway();
    void printNajaden(int = -1, std::string = "", int = 0, int = 0);
    void printLogin(int = 7);
    void startupAnimation();
    void loginAnimation();
    bool promptCreate();
    void loginUser();

    void appLoop();

public:
    static std::unordered_map<int, User *> userMap;           // uID, and User
    static std::unordered_map<int, Page *> pageMap;           // uID, and Page
    static std::unordered_map<int, Post *> postMap;       // uID, and Post
    static std::unordered_map<int, Comment *> commentMap;
    static std::unordered_map<std::string, Login> loginMap;   // Username and password
    static User *currentUser;

    App();
    void run();
    ~App();
};

std::unordered_map<int, User *> App::userMap;           // uID, and User
std::unordered_map<int, Page *> App::pageMap;           // uID, and Page
std::unordered_map<int, Post *> App::postMap;       // uID, and Post
std::unordered_map<std::string, Login> App::loginMap;   // Username and password
std::unordered_map<int, Comment *> App:: commentMap;
User *App::currentUser;