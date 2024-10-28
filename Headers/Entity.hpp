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
    Entity(int = 0, std::string = "", std::string = "");
    
    void showProfile();
    
    void addPost(Post *post);

    std::string getName() const;
    std::string getType() const;
    std::vector<Post *> getPosts() const;
};