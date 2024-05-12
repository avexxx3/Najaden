#pragma once
#include "Headers/Date.hpp"
#include "Headers/Helper.hpp"
#include <iostream>
#include <string>

Date::Date(int y, int mon, int d, int h, int min): y(y), mon(mon), d(d), h(h), min(min) {}

std::string Date::getFormattedDate() {
    std::string date = "";
    
    date += std::to_string(d) + " ";

    switch(mon) {
        case 1: date += "Jan"; break;
        case 2: date += "Feb"; break;
        case 3: date += "Mar"; break;
        case 4: date += "Apr"; break;
        case 5: date += "May"; break;
        case 6: date += "Jun"; break;
        case 7: date += "Jul"; break;
        case 8: date += "Aug"; break;
        case 9: date += "Sep"; break;
        case 10: date += "Oct"; break;
        case 11: date += "Nov"; break;
        case 12: date += "Dec"; break;
    }


    date += " 20" + toString(y) + ", " + toString(h) + ':' + toString(min);
    return date;
}

std::string Date::getCompressedDate() {
    return toString(y) + toString(mon) + toString(d) + toString(h) + toString(min);
}

std::string Date::toString(int compressed) {
   std::string date = std::to_string(compressed);
   if(date.size() == 1) date = '0' + date;
   return date; 
}

bool Date::is24h() {
    Date* currentDate = Helper::getInstance()->getCurrentDate();
    Date postDate = *this;

    int newY, newMon, newD, newH, newMin;
    
    newMin = currentDate->min - postDate.min;
    while(newMin < 0) {
        currentDate->h--;
        newMin += 60;
    }

    newH = currentDate->h - postDate.h;
    while(newH < 0) {
        currentDate->d--;
        newH += 24;
    }

    newD = currentDate->d - postDate.d--;
    while(newD < 0) {
        currentDate->mon--;
        newD += 30;
    }

    newMon = currentDate->mon - postDate.mon;
    while(newMon < 0) {
        currentDate->y--;
        newMon += 12;
    }


    newY = postDate.y - currentDate->y;

    return (newY == 0) && (newMon == 0) && (newD == 0) && (newH <= 24);
}