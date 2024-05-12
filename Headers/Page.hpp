#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Entity.hpp"
#include "User.hpp"

class User;

class Page : public Entity
{
    User *owner;
    int likes;

public:
    Page(int = 0, User * = 0, std::string = "", int = 0);

    int getLikes() const;
    User *getOwner() const;
};