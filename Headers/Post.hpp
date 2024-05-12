#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Object.hpp"
#include "User.hpp"
#include "Comment.hpp"
#include "Page.hpp"

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
    Post(int, std::string, int, Entity *, std::vector<User *>, std::string, int, std::string);

    void printPost(bool = 0);

    void addLike(User *);
    void removeLike(User *);

    void addComment(Comment *);

    void showDetailedView();

    Entity* getAuthor() const;
    std::string getText() const;
    int getLikes() const;
    std::vector<User *> getLikedBy() const;
    std::vector<Comment *> getComments() const;
    std::string getDate() const;
    int getActivityType() const;
    std::string getActivityValue() const;
};
