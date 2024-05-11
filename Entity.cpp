#include "Headers/App.hpp"
#include "Headers/Comment.hpp"
#include "Headers/Helper.hpp"
#include "Headers/Object.hpp"
#include "Headers/Page.hpp"
#include "Headers/Post.hpp"
#include "Headers/User.hpp"
#include "Headers/Entity.hpp"

Entity::Entity(int id, std::string name, std::string type): Object(id), name(name), type(type) {}

void Entity::postPost(Post *post) {
    posts.emplace_back(post);
}

std::string Entity::getName() const {
    return name;
}

std::vector<Post *> Entity::getPosts() const {
    return posts;
}

std::string Entity::getType() const {
    return type;
}

void User::showProfile()
{
    while (1)
    {
        system("clear");
        std::cout << "Press 'q' to go back.\n\n";
        std::cout << getName() << "'s Profile\n\n";
        for (auto &post : getPosts()) post->printPost();
        if(getch() == 'q') break;
    }
}