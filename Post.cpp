#pragma once
#include "Headers/Post.hpp"

Post::Post(int id, std::string text, int likes, Entity* author, std::vector<User *> likedBy, std::string date, int activityType, std::string activityValue)
:Object(id), text(text), date(date), likes(likes), author(author), likedBy(likedBy), activityType(activityType), activityValue(activityValue) {}

void Post::addLike(User *newLike)
{
    if (likes <= 10)
    {
        likedBy.emplace_back(newLike);
        likes++;
    }
    else
        std::cout << "Reached the limit of likes on postID: " << getId() << '\n';
}

void Post::addComment(Comment *newComment)
{
    if (comments.size() <= 10)
        comments.emplace_back(newComment);
    else
        std::cout << "Maximum numbers of comments exceeded for postID: " << getId() << '\n';
}

void Post::printPost()
{
    std::cout << author->getName() << " posted: \"" << text << "\"\n";
    for (auto &comment : comments)
    {
        comment->printComment();
    }
    std::cout << "\n";
}

std::string Post::getText() const
{
    return text;
}

int Post::getLikes() const
{
    return likes;
}

std::vector<User *> Post::getLikedBy() const
{
    return likedBy;
}

std::vector<Comment *> Post::getComments() const
{
    return comments;
}

std::string Post::getDate() const
{
    return date;
}

int Post::getActivityType() const
{
    return activityType;
}

std::string Post::getActivityValue() const
{
    return activityValue;
}