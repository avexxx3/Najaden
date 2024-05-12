#pragma once
#include "Headers/Object.hpp"

Object::Object(int id)
    : id(id) {}

int Object::getId()
{
    return id;
}