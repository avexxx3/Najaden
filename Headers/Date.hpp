#pragma once
#include <string>

class Date{
    int y, mon, d, h, min;
    std::string toString(int);

    public:
    Date(int, int, int, int, int);
    std::string getFormattedDate();
    std::string getCompressedDate();
    bool is24h();
};