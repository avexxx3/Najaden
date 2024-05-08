#pragma once
#include <iostream>
#include <vector>
#include <string>

#include "Object.hpp"
#include "Post.hpp"
#include "Comment.hpp"
#include "Page.hpp"

class Post;
class Comment;
class Page;

class User: public Object {
    std::string name;
    std::vector<User*> friends;
    std::vector<Page*> likedPages;
    std::vector<std::string> temporaryFriends;

public:
    User(int id, std::string name = "", std::vector<std::string> temporaryFriends = {}):Object(id), name(name) {}

    void addFriend(User* newFriend) {
        std::cout << name << " has added " << newFriend->getId() << "as a friend.\n";
        friends.emplace_back(newFriend);
    }

    void likePage(Page* newPage) {
        std::cout << name << " has liked page: " << newPage->getTitle() << "\n";
        likedPages.emplace_back(newPage);
    }

    std::string getName() const {return name;}
    std::vector<User*> getFriends() const {return friends;}
    std::vector<Page*> getLikedPages() const {return likedPages;}
};