#pragma once
#include <iostream>
#include <string>

#include "User.hpp"
#include "Post.hpp"
#include "Page.hpp"

class User;
class Post;
class Page;


class Comment {
    std::string text;
    User* parentUser;
    Comment* parentComment;
};