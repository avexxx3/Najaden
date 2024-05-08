#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "User.hpp"
#include "Post.hpp"
#include "Comment.hpp"
#include "Page.hpp"

class User;
class Post;
class Comment;
class Page;

class App {
    std::vector<User> listOfUsers;
};