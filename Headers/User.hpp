#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

#include "Object.hpp"
#include "Post.hpp"
#include "Comment.hpp"
#include "Page.hpp"
#include "Entity.hpp"

class Post;
class Comment;
class Page;

class User : public Entity
{
    std::string username;
    std::vector<User *> friends;
    std::vector<Page *> likedPages;
    std::vector<std::string> temporaryFriends;

    void addFriendsMenu();
    void removeFriendsMenu();

    void likePagesMenu();
    void dislikePagesMenu();

    
    void showPosts(bool = 0, bool = 0);

public:
    User(int, std::string = "", std::string = "", std::vector<std::string> = {});

    void printHome();
    
    void showFriends();
    void showPages();

    void showProfile();

    void chooseDetailedPost();

    void addFriend(User *newFriend);
    void likePage(Page *newPage);

    std::vector<User *> getFriends() const;
    std::vector<Page *> getLikedPages() const;
    std::vector<std::string> getTempFriends() const;
    std::string getUsername() const;
};