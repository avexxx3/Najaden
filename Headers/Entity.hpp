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
    std::string type;

public:
    Entity(int id = 0, std::string name = "", std::string type = "");
    void postPost(Post *post);
    std::string getName() const;
    std::vector<Post *> getPosts() const;
    std::string getType() const;
    void showProfile();
};