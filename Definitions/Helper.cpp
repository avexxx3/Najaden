#pragma once
#include "../Headers/Helper.hpp"
#include <chrono>
#include <time.h>

std::vector<std::string> Helper::split(const std::string &s, char delim)
{
    std::vector<std::string> result;
    std::stringstream stringstream(s);
    std::string item;

    while (getline(stringstream, item, delim))
    {
        result.push_back(item);
    }

    return result;
}

Helper::Helper() {

}

char Helper::getch(void) {
    char buf = 0;
        struct termios old = {0};
        fflush(stdout);
        if (tcgetattr(0, &old) < 0)
            perror("tcsetattr()");
        old.c_lflag &= ~ICANON;
        old.c_lflag &= ~ECHO;
        old.c_cc[VMIN] = 1;
        old.c_cc[VTIME] = 0;
        if (tcsetattr(0, TCSANOW, &old) < 0)
            perror("tcsetattr ICANON");
        if (read(0, &buf, 1) < 0)
            perror("read()");
        old.c_lflag |= ICANON;
        old.c_lflag |= ECHO;
        if (tcsetattr(0, TCSADRAIN, &old) < 0)
            perror("tcsetattr ~ICANON");
        printf("%c\n", buf);
        return buf;
}

Helper* Helper::getInstance() {
    if(helperInstance == nullptr) helperInstance = new Helper;
    return helperInstance;
}

Date* Helper::getCurrentDate() {
    std::time_t end_time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::vector<std::string> ctimeStr = Helper::getInstance()->split(std::ctime(&end_time), ' ');

    int mon;
    std::string monStr = ctimeStr[1];

    if (monStr == "Jan")
        mon = 1;
    else if (monStr == "Feb")
        mon = 2;
    else if (monStr == "Mar")
        mon = 3;
    else if (monStr == "Apr")
        mon = 4;
    else if (monStr == "May")
        mon = 5;
    else if (monStr == "Jun")
        mon = 6;
    else if (monStr == "Jul")
        mon = 7;
    else if (monStr == "Aug")
        mon = 8;
    else if (monStr == "Sep")
        mon = 9;
    else if (monStr == "Oct")
        mon = 10;
    else if (monStr == "Nov")
        mon = 11;
    else if (monStr == "Dec")
        mon = 12;

    std::vector<std::string> timeStr = Helper::getInstance()->split(ctimeStr[3], ':');

    return new Date(stoi(ctimeStr[4].substr(2)), mon, stoi(ctimeStr[2]), stoi(timeStr[0]), stoi(timeStr[1]));
}


void Helper::writeUsers()
{
    std::ofstream myFile("Database/Users.txt", std::ofstream::trunc);
    myFile << "uID;Name;Username;Password;uID of Friends;\n";

    for (auto &user : App::userMap)
    {
        std::string write = "";
        write += std::to_string(user.first);
        write += ';';
        write += user.second->getName();
        write += ';';
        write += user.second->getUsername();
        write += ';';
        write += App::loginMap.at(user.second->getUsername()).password;
        write += ';';
        int counter = 0, countFriends = user.second->getFriends().size();
        for (auto &buddy : user.second->getFriends())
        {
            write += std::to_string(buddy->getId());
            counter++;
            if (counter != countFriends)
                write += ',';
        }
        write += ";\n";

        myFile << write;
    }

    myFile.close();
}

void Helper::writePages() {
    std::ofstream myFile("Database/Pages.txt", std::ofstream::trunc);
    myFile << "PageID;Owner uID;Title;Liked by;\n";

    for(auto &page: App::pageMap) {
        std::string write = "";
        write += std::to_string(page.second->getId());
        write += ';';
        write += std::to_string(page.second->getOwner()->getId());
        write += ';';
        write += page.second->getName();
        write += ';';
        int counter=0, likedSize = page.second->getLikes();
        for(auto &user: App::userMap) {
            for(auto &likedPage: user.second->getLikedPages()) {
                if(page.second->getId() == likedPage->getId()) {
                    write += std::to_string(user.second->getId());
                    counter++;
                    if(counter != likedSize) write += ',';
                }
            }
        }
        write += ";\n";
        myFile << write;
    }
    myFile.close();
}

void Helper::writePosts() {
    std::ofstream myFile("Database/Posts.txt", std::ofstream::trunc);
    myFile << "PostID; authorID; Text; Date; uID of likers; Activity Type; Activity Value;\n";
    
    for(auto &post: App::postMap) {
        if(post.second->getAuthor()->getType() != "User") continue;
        std::string write = "";
        write += std::to_string(post.second->getId());
        write += ';';
        write += std::to_string(post.second->getAuthor()->getId());
        write += ';';
        write += post.second->getText();
        write += ';';
        write += std::to_string(post.second->getMemory());
        write += ';';
        write += post.second->getDate()->getCompressedDate();
        write += ';';
        int counter = 0, likeSize = post.second->getLikes();
        for(auto& buddy: post.second->getLikedBy()) {
            write += std::to_string(buddy->getId());
            counter++;
            if(counter != likeSize) write += ',';
        }

        if(post.second->getActivityValue() != "" && post.second->getActivityType() != 0) {
            write += ';';
            write += std::to_string(post.second->getActivityType());
            write += ';';
            write += post.second->getActivityValue();
        }
        write += ";\n";
        myFile << write;
    }

    myFile << "\nPAGES\n";

    for(auto &post: App::postMap) {
        if(post.second->getAuthor()->getType() != "Page") continue;
        std::string write = "";
        write += std::to_string(post.second->getId());
        write += ';';
        write += std::to_string(post.second->getAuthor()->getId());
        write += ';';
        write += post.second->getText();
        write += ';';
        write += std::to_string(post.second->getMemory());
        write += ';';
        write += post.second->getDate()->getCompressedDate();
        write += ';';
        int counter = 0, likeSize = post.second->getLikes();
        for(auto& buddy: post.second->getLikedBy()) {
            write += std::to_string(buddy->getId());
            counter++;
            if(counter != likeSize) write += ',';
        }

        if(post.second->getActivityValue() != "" && post.second->getActivityType() != 0) {
            write += ';';
            write += std::to_string(post.second->getActivityType());
            write += ';';
            write += post.second->getActivityValue();
        }
        write += ";\n";
        myFile << write;
    }

    myFile.close();
}

void Helper::writeComments() {
    std::ofstream myFile("Database/Comments.txt", std::ofstream::trunc);
    myFile << "CommentID; PostID; UserID; Text;\n";
    for(auto &post: App::postMap) {
        for(auto &comment: post.second->getComments()) {
            std::string write = "";
            write += std::to_string(comment->getId());
            write += ';';
            write += std::to_string(post.second->getId());
            write += ';';
            write += std::to_string(comment->getAuthor()->getId());
            write += ';';
            write += comment->getText();
            write += ";\n";
            myFile << write;
        }
    }
    myFile.close();
}

void Helper::writeData() {
    writeComments();
    writePages();
    writePosts();
    writeUsers();
}