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

class Comment: public Object {
    std::string text;
    User* author;

    public:
    Comment(int id, std::string text, User* author): Object(id), text(text), author(author) {}

    std::string getText() const {return text;}
    User* getAuthor() const {return author;}
};