#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Object.hpp"
#include "User.hpp"
#include "Post.hpp"
#include "Comment.hpp"

class Post;

class Entity : public Object
{
    std::string name;
    std::vector<Post *> posts;

public:
    Entity(int id = 0, std::string name = "");

    void postPost(Post *post);

    std::string getName() const;

    std::vector<Post *> getPosts() const;
};