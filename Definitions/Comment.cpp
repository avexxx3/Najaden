#pragma once
#include "../Headers/App.hpp"
#include "../Headers/Comment.hpp"
#include "../Headers/Helper.hpp"
#include "../Headers/Object.hpp"
#include "../Headers/Page.hpp"
#include "../Headers/Post.hpp"
#include "../Headers/User.hpp"

Comment::Comment(int id, std::string text, User *author)
    : Object(id), text(text), author(author) {}

std::string Comment::getText() const
{
    return text;
}

User *Comment::getAuthor() const
{
    return author;
}

void Comment::printComment() const
{
    std::cout << "\t\t" << author->getName() << " commented: \"" << text << "\"\n";
}