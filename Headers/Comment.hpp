#pragma once
#include <iostream>
#include <string>

#include "Object.hpp"
#include "User.hpp"
#include "Post.hpp"
#include "Page.hpp"

class Comment : public Object
{
    std::string text;
    User *author;

public:
    Comment(int, std::string, User *);

    void printComment() const;

    std::string getText() const;
    User *getAuthor() const;
};