#pragma once
#include <iostream>
#include <vector>
#include <string>

#include "Post.hpp"
#include "Comment.hpp"
#include "Page.hpp"

class Post;
class Comment;
class Page;

class User {
    public:
    int id;
    std::string name;
    std::vector<User*> friends;
    std::vector<Page*> likedPages;

    User() {}
};