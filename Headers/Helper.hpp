#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include <termios.h>

class Helper
{
    static Helper* helperInstance;

    Helper();

    public:

    void writeUsers();
    void writePages();
    void writePosts();
    void writeComments();
    void writeData();

    std::vector<std::string> split(const std::string&, char);
    char getch(void);
    static Helper* getInstance();
    Date* getCurrentDate();
};

Helper* Helper::helperInstance = 0;