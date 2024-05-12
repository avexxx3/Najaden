#pragma once
#include "Headers/Post.hpp"
#include "Headers/App.hpp"
#include <algorithm>

Post::Post(int id, std::string text, int likes, Entity *author, std::vector<User *> likedBy, std::string date, int activityType, std::string activityValue)
    : Object(id), text(text), date(date), likes(likes), author(author), likedBy(likedBy), activityType(activityType), activityValue(activityValue) {}

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

void Post::removeLike(User *newUser)
{
    likedBy.erase(std::find(likedBy.begin(), likedBy.end(), newUser));
}

void Post::showDetailedView()
{
    char choice;

    bool newLike = 1;
    for (auto &likeUser : likedBy)
    {
        if (likeUser->getName() == App::currentUser->getName())
        {
            newLike = 0;
            break;
        }
    }

    bool contains = 0;
    for (auto &likeUser : likedBy)
    {
        if (likeUser->getName() == App::currentUser->getName())
        {
            contains = 1;
            break;
        }
    }

    std::string comment;
    while (choice != 27)
    {
        system("clear");
        std::cout << "Press ESC to go back.\n";

        if (choice != 'c')
        {
            std::cout << "Press 'C' to comment on the post.\n";
            if (contains)
                std::cout << "Press 'U' to dislike the post.\n";
            else
                std::cout << "Press 'L' to like the post.\n";
        }

        std::cout << '\n' << getId() << " - " << author->getName() << " posted on " << date << ":\n\"" << text << "\"\n";

        for (auto &comment : comments)
        {
            comment->printComment();
        }

        if (choice != 'c')
        {
            if (likedBy.size() == 0)
                std::cout << "\nThis post has no likes";
            else
            {
                std::cout << "\nLiked by:\n";
                for (auto &user : likedBy)
                    std::cout << user->getName() << '\n';
            }
        }

        if (choice == 'c')
        {
            std::cout << "\t\t" << App::currentUser->getName() << " commented: \"" << comment << "\"\n\n";
            char tempInput;
            tempInput = Helper::getInstance()->getch();

            switch (tempInput)
            {
            case 27:
            {
                choice = 'a';
                comment = "";
                continue;
            }

            case 127:
                comment = comment.substr(0, comment.size() - 1);
                continue;
                break;

            case 10:
                if (comment.size() == 0)
                    continue;
                break;

            default:
                comment += tempInput;
                continue;
            }

            int i = 1;
            while (App::commentMap.count(i))
                i++;
            Comment *newComment = new Comment(i, comment, App::currentUser);
            addComment(newComment);
            comment = "";
        }

        if (choice != 'c')
            choice = tolower(Helper::getInstance()->getch());
        else
            choice = 'a';

        if (choice == 'l' && newLike)
        {
            addLike(App::currentUser);
            contains = 1;
            newLike = 0;
            choice = 'a';
        }

        if (choice == 'u' && contains)
        {
            removeLike(App::currentUser);
            contains = 0;
            newLike = 1;
            choice = 'a';
        }

        std::cout << "\n";
    }
}

void Post::printPost(bool showId)
{
    if (showId)
        std::cout << getId() << " - ";
    std::cout << author->getName() << " posted on " << date << ":\n\"" << text << "\"\n";
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