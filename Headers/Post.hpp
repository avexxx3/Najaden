#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Object.hpp"
#include "User.hpp"
#include "Comment.hpp"
#include "Page.hpp"
#include "Date.hpp"

class Post : public Object
{
    std::string text;
    Date* date;
    std::string activityValue;
    std::vector<User *> likedBy;
    std::vector<Comment *> comments;
    bool isMemory;
    Entity *author;
    int activityType;
    int likes = 0;

public:
    Post(int, std::string, int, Entity *, std::vector<User *>, Date*, int, std::string, bool = 0);

    void printPost(bool = 0, bool = 0);

    void addLike(User *);
    void removeLike(User *);
    void addComment(Comment *);

    void showDetailedView();

    void setMemory();

    Entity* getAuthor() const;
    std::string getText() const;
    int getLikes() const;
    std::vector<User *> getLikedBy() const;
    std::vector<Comment *> getComments() const;
    Date* getDate() const;
    int getActivityType() const;
    std::string getActivityValue() const;
    bool getMemory() const;
};