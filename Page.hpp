#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Object.hpp"
#include "User.hpp"
#include "Post.hpp"
#include "Comment.hpp"

class User;
class Post;
class Comment;

class Page: public Object{
    User* owner;
    std::string title;
    std::vector<Post*> sharedPosts;
    int likes;

    public:
    Page(int id, User* owner, std::string title): Object(id), owner(owner), title(title) {}

    void postPost(Post* newPost) {sharedPosts.emplace_back(newPost);}

    std::vector<Post*> getPosts() const {return sharedPosts;}
    std::string getTitle() const {return title;}
};