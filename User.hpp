#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

#include "Object.hpp"
#include "Post.hpp"
#include "Comment.hpp"
#include "Page.hpp"

class Post;
class Comment;
class Page;

class User: public Object {
    std::string name;
    std::vector<User*> friends;
    std::vector<Page*> likedPages;
    std::vector<Post*> posts;
    std::vector<std::string> temporaryFriends;

public:
    User(int id, std::string name = "", std::vector<std::string> temporaryFriends = {}):Object(id), name(name), temporaryFriends(temporaryFriends) {}

    void addFriend(User* newFriend) {
        friends.emplace_back(newFriend);
    }

    void likePage(Page* newPage) {
        likedPages.emplace_back(newPage);
    }

    void postPost(Post* post) {
        posts.emplace_back(post);
    }

    void printHome() {
        for (auto &user : friends)
        {
            for (auto &post : user->getPosts())
            {
                std::cout << user->getName() << " posted: \"" << post->getText() << "\"\n";
                for (auto &comment : post->getComments())
                {
                    std::cout << "\t\t" << comment->getAuthor()->getName() << " commented: \"" << comment->getText() << "\"\n";
                }
                std::cout << "\n";
            }
        }
    }

    std::string getName() const {return name;}
    std::vector<User*> getFriends() const {return friends;}
    std::vector<Page*> getLikedPages() const {return likedPages;}
    std::vector<std::string> getTempFriends() const {return temporaryFriends;}
    std::vector<Post*> getPosts() const {return posts;}
};