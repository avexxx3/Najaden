#pragma once
#include <iostream>
#include <string>

#include "Object.hpp"
#include "User.hpp"
#include "Post.hpp"
#include "Page.hpp"

class User;
class Post;
class Page;

class Comment: Object {
    std::string text;
    User* parentUser;

    public:
    Comment(int id, std::string text, User* parentUser): Object(id), text(text), parentUser(parentUser) {}

    std::string getText() const {return text;}
};