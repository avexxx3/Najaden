#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "User.hpp"
#include "Post.hpp"
#include "Comment.hpp"

class User;
class Post;
class Comment;

class Page {
    int id;
    User* owner;
    std::string title;
    std::vector<Post> sharedPosts;
    int likes;
};