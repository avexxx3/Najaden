#include "Headers/App.hpp"
#include "Headers/Comment.hpp"
#include "Headers/Helper.hpp"
#include "Headers/Object.hpp"
#include "Headers/Page.hpp"
#include "Headers/Post.hpp"
#include "Headers/User.hpp"
#include "Headers/Entity.hpp"

Entity::Entity(int id, std::string name): Object(id), name(name) {}

void Entity::postPost(Post *post) {
    posts.emplace_back(post);
}

std::string Entity::getName() const {
    return name;
}

std::vector<Post *> Entity::getPosts() const {
    return posts;
}