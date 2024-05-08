#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Object.hpp"
#include "User.hpp"
#include "Comment.hpp"
#include "Page.hpp"

class User;
class Comment;
class Page;

class Post: public Object {
    std::string text;
    int likes = 0;
    std::vector<User*> likedBy;
    std::string date;

    public:
    Post(int id, std::string text, int likes, std::string date):Object(id), text(text), date(date) {}

    void addLike(User* newLike) {
        likedBy.emplace_back(newLike);
        likes++;
    }
};

