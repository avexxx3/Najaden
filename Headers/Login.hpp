#pragma once
#include <string>

struct LoginData
{
    int id;
    std::string password;
    LoginData(int id, std::string password) : id(id), password(password) {}
};

class Login
{
    std::string *najaden;
    std::string userLogin = "";
    std::string userPassword = "";
    std::string userName = "";
    std::string status[2] = {"", ""};

    bool isLogging = false;
    bool isPasswording = false;
    bool isCreating = false;

    void comeSailAway();
    void printNajaden(int = -1, std::string = "", int = 0, int = 0);
    void printLogin(int = 7);

    bool promptCreate();

    void startupAnimation();
    void loginAnimation();

    void loginUser();

public:
    void loginScreen();
};