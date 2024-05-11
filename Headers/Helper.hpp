#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include <termios.h>

std::vector<std::string> split (const std::string &s, char delim) {
    std::vector<std::string> result;
    std::stringstream stringstream(s);
    std::string item;

    while (getline (stringstream, item, delim)) {
        result.push_back (item);
    }

    return result;
}

bool isInt(std::string word) {
    for(int i=0; i < word.size(); i++)
        if(!(word[i] >= '0' && word[i] <= '9')) return 0;
    return 1;
}

char getch(void)
{
    char buf = 0;
    struct termios old = {0};
    fflush(stdout);
    if(tcgetattr(0, &old) < 0)
        perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if(tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");
    if(read(0, &buf, 1) < 0)
        perror("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if(tcsetattr(0, TCSADRAIN, &old) < 0)
        perror("tcsetattr ~ICANON");
    printf("%c\n", buf);
    return buf;
 }