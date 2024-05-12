#pragma once
#include "Headers/App.hpp"
#include "Headers/Comment.hpp"
#include "Headers/Helper.hpp"
#include "Headers/Object.hpp"
#include "Headers/Page.hpp"
#include "Headers/Post.hpp"
#include "Headers/User.hpp"

Page::Page(int id, User *owner, std::string title)
    : Entity(id, title), owner(owner) {}

int Page::getLikes() const
{
    return likes;
}

User *Page::getOwner() const
{
    return owner;
}