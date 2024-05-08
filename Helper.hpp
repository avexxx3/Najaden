#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

std::vector<std::string> split (const std::string &s, char delim) {
    std::vector<std::string> result;
    std::stringstream stringstream(s);
    std::string item;

    while (getline (stringstream, item, delim)) {
        result.push_back (item);
    }

    return result;
}
