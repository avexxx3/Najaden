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

class User: public Entity {
    std::vector<User*> friends;
    std::vector<Page*> likedPages;
    std::vector<std::string> temporaryFriends;

public:
    User(int id, std::string name = "", std::vector<std::string> temporaryFriends = {});

    void addFriend(User* newFriend);

    void likePage(Page* newPage);

    void printHome();

    std::vector<User*> getFriends() const;
    std::vector<Page*> getLikedPages() const;
    std::vector<std::string> getTempFriends() const;
};