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

class Post: public Object {
    std::string text;
    int likes = 0;
    std::vector<User*> likedBy;
    std::string date;
    int activityType;
    std::string activityValue;

    public:
    Post(int id, std::string text, int likes, std::vector<User*> likedBy ,std::string date, int activityType, std::string activityValue):Object(id), text(text), date(date), likes(likes), likedBy(likedBy), activityType(activityType), activityValue(activityValue) {}

    void addLike(User* newLike) {
        likedBy.emplace_back(newLike);
        likes++;
    }

    std::string getText() const {return text;}
    int getLikes() const {return likes;}
    std::vector<User*> getLikedBy() const {return likedBy;}
    std::string getDate() const {return date;}
    int getActivityType() const {return activityType;}
    std::string getActivityValue() const {return activityValue;}
};

