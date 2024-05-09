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
    Page(int id = 0, User* owner = 0, std::string title = ""): Object(id), owner(owner), title(title) {}

    void postPost(Post* newPost) {sharedPosts.emplace_back(newPost);}

    int getLikes() const {return likes;}
    User* getOwner() const {return owner;}
    std::vector<Post*> getPosts() const {return sharedPosts;}
    std::string getTitle() const {return title;}
};