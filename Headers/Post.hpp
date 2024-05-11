#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Object.hpp"
#include "User.hpp"
#include "Comment.hpp"
#include "Page.hpp"

class User;
class Comment;
class Page;

class Post : public Object
{
    std::string text;
    std::string date;
    std::string activityValue;
    std::vector<User *> likedBy;
    std::vector<Comment *> comments;
    Entity *author;
    int activityType;
    int likes = 0;

public:
    Post(int id, std::string text, int likes, Entity* author, std::vector<User *> likedBy, std::string date, int activityType, std::string activityValue);

    void printPost(bool = 0);

    void addLike(User *newLike);
    void addComment(Comment *newComment);
    void detailedView();

    void dislike(User*);

    std::string getText() const;
    int getLikes() const;
    std::vector<User *> getLikedBy() const;
    std::vector<Comment *> getComments() const;
    std::string getDate() const;
    int getActivityType() const;
    std::string getActivityValue() const;
};
