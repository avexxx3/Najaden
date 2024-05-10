#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Object.hpp"
#include "User.hpp"
#include "Post.hpp"
#include "Comment.hpp"
#include "Entity.hpp"

class User;
class Post;
class Comment;

class Page: public Entity{
    User* owner;
    int likes;

    public:
    Page(int id = 0, User* owner = 0, std::string title = "");

    int getLikes() const;
    User* getOwner() const;
};