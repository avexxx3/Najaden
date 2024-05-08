#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "User.hpp"
#include "Comment.hpp"
#include "Page.hpp"

class User;
class Comment;
class Page;

class Post {
    int id;
    std::string text;
    int likes;
    std::vector<User> likedBy;
    std::string date;
};

