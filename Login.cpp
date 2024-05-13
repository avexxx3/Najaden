#pragma once
#include "Headers/Login.hpp"
#include "Headers/App.hpp"
#include <iostream>
#include <vector>
#include <string>

void Login::comeSailAway()
{
    najaden = new std::string[29]{
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⣤⡼⣷⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠛⠿⠳⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣤⣤⣤⣿⣾⣿⣷⣶⣶⣶⣶⣶⣦⠀⠀⣶⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣿⠀⠀⠀⠀⠹⣏⠉⠉⠉⠙⢛⣛⡛⠛⢋⡙⢷⣄⢈⣿⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣀⣀⣸⣿⣄⣀⣀⣀⣠⡿⣦⠀⠀⠀⠈⢻⡇⠀⠸⣿⠽⢯⠭⠽⠿⠭⠿⠿⢿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠛⢻⡟⠛⠛⠛⠿⣿⠒⠒⠚⣿⣇⣿⣠⣇⣀⣀⣈⣁⠀⠀⠈⣧⣀⣄⡀⠀⠀⠀⠀⠀⣿⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⢸⡄⡀⠀⠸⢦⣤⣴⣿⣿⣿⡯⣿⣿⣿⣭⡭⠿⠽⣶⣧⣼⣼⣹⠀⠀⠀⠀⠀⣸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⢸⡇⡇⣠⠀⠀⠙⢿⡉⠉⠉⠙⢹⠉⠉⠙⢋⣉⣿⣿⣿⣿⣿⣿⣿⣶⣶⣶⣦⣿⣿⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣼⣣⣿⣴⣷⣿⣤⠤⠤⣼⣧⢠⡀⠀⠈⠀⠀⠀⠘⠻⣿⠛⠛⠛⠛⠛⠛⠛⢛⢿⣟⠛⢿⣿⣧⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠶⣿⠿⠿⠭⠭⠯⠿⠿⠽⠭⢽⣿⢸⠇⡖⢀⡄⠀⠀⠀⠀⢸⣗⣄⡀⠀⠀⠀⠀⠘⡆⢿⣷⣌⢿⣧⠙⢧⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠻⡆⡀⠀⠀⠀⠀⠀⠀⠀⣼⣣⣾⣴⣧⣾⣤⣤⣤⣤⣄⣸⢣⡇⣽⠀⠀⠀⠀⠀⠁⠀⢿⡝⢿⣿⡆⠸⡿⣦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣷⢹⠀⣤⠀⠀⢀⣴⣾⡯⠭⢥⣤⣤⣼⣧⣾⣤⣤⣿⣷⣿⣿⣷⣶⣶⡶⠦⢤⣀⣀⠘⣷⠀⢹⣿⡀⠈⢿⣷⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⢸⠆⣿⢸⡆⠀⠙⢿⡍⠉⠉⠉⠉⠉⠉⢹⣿⣿⣿⣿⣿⣿⣿⣿⣷⣷⣶⣶⣶⣿⣿⣿⡞⢦⣹⣷⣤⣹⣿⢿⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣼⢇⣾⣰⣿⣾⣥⡤⠤⢤⣿⠀⠀⠀⠀⠀⠀⠀⠈⢻⡄⠀⠀⠀⠀⠀⢹⡀⠀⠀⠀⢠⡀⠙⣿⡀⠙⢿⣿⣿⡛⠻⠿⣿⣦⡀⠀⠀⡀⠀⠀⠀⠀",
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣿⠀⡇⠀⠀⠀⠀⠀⢰⠄⢿⠀⠀⠀⠀⠀⠀⠁⠀⠀⠀⠀⠁⠀⠹⠷⢶⠾⣯⣿⣿⣦⡀⠈⠙⣷⣤⣾⠇⠀⠀⠀⠀",
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⣧⣀⡀⠀⠀⠀⠀⠀⠀⢀⡟⣰⡇⣾⢀⡄⠀⠀⠈⠀⣸⠈⡇⢀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⡇⢸⡇⠀⠀⠉⠙⣿⣴⣾⣿⡿⠃⠀⠀⠀⠀⠀",
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⣾⡆⣆⠀⠀⠀⠀⣰⣿⣱⣿⣴⡿⣾⣷⡶⣶⠦⢤⡟⣸⠃⡼⢠⡆⢀⠀⢀⡀⠀⣰⠇⣠⡟⢀⡿⠁⠀⢀⣠⣾⣿⣿⠟⠉⠀⠀⠀⠀⠀⠀⠀",
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⣻⠃⡾⠀⠠⢶⣿⠿⠿⠿⠿⠿⢿⣿⣿⣿⣿⣿⣿⣴⣿⣿⣷⣿⣦⣿⣦⣾⣷⣾⣣⡼⣋⣤⡞⠀⣠⣴⣻⣷⠟⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣼⣿⣟⣚⣛⣋⣿⣿⣏⣉⣉⣙⣛⣦⣼⠋⢹⡿⣿⠿⠿⠿⠿⠿⠿⠿⢿⡿⣿⢿⣿⠿⣿⣿⣿⣿⣷⠾⣿⡿⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⠻⠛⠛⠛⠛⠛⠛⣿⠻⡟⠛⠛⠛⠛⠛⠛⠃⢸⠇⢸⠀⠀⠀⠀⢰⣷⣶⣾⣶⣿⠟⣿⣠⡿⢷⣟⡟⢹⡟⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⣦⣤⣀⡀⠀⣿⠀⡇⠀⠀⠀⠀⠀⠀⠀⢸⡄⢸⠀⠀⠀⠀⢀⣸⣿⣿⡿⠿⠛⣿⣁⣴⠾⣻⡇⣾⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢷⣄⣹⣉⠙⠛⢾⠷⠶⠶⣶⣤⣤⣤⣴⣾⣷⠾⠶⠶⠾⣿⠿⣽⣽⣿⣶⡾⠟⠋⠡⠴⠚⣻⣿⠇⣀⣀⣠⢶⣶⢦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢻⣎⣙⡛⠛⠿⠷⢶⣶⣶⣿⣶⣾⣾⣿⣿⣶⡾⠿⣿⡟⠛⣻⣿⣿⢿⣦⣄⡀⣀⣠⢴⣿⣿⡟⠙⢯⣻⣶⢿⡿⣧⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠛⣯⠉⠓⣒⡆⠀⠉⠙⣿⡛⠛⠛⣛⣛⣻⣀⠀⠉⢰⢟⣟⠛⣻⣦⣤⣍⠻⣆⣠⣿⣿⠏⣠⣤⣼⡿⠋⣶⣷⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        "⠀⠀⠀⠀⠀⠀⣠⣄⠀⠀⢀⣤⠖⠀⠀⣈⣳⣄⠉⠉⣹⣤⠞⠉⠛⠶⣬⣭⣭⣭⣽⡟⢶⣼⣿⣽⠆⣿⣿⣍⡍⠀⠽⠿⠛⢡⠞⢫⣽⣝⣿⡆⠻⣯⠾⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        "⢀⠀⣀⣠⠴⠚⠁⠈⠻⠿⢯⣤⣤⠄⠀⠈⠉⠉⠉⠉⠉⠀⠀⠀⢀⣀⣀⣠⡴⠟⠉⠀⠀⠈⠉⠛⠶⠾⠿⠿⠷⠀⠀⠀⠀⠉⠀⠐⣶⣿⣿⡇⠀⠑⠶⣤⣠⣴⠶⠟⠿⠶⢤⣤⡶",
        "⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣀⣀⡼⣦⣀⡀⠀⠀⠀⠀⠀⣰⣆⠀⠀⠀⠀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠛⠛⠛⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠀⠀⠀⠀⠙⠦⠤⠤⠴⠛⠁⠙⠷⠤⠴⠞⠋⠛⠦⠤⠴⠆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣾⣦⡀⠀⠀⠀⢠⣄⠀⠀⠀⠀⠀⠀",
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠒⠒⠒⠛⠉⠀⠉⣟⣓⣶⡶⠛⠙⠳⠦⣤⠄⠀⠀"};
}

void Login::printNajaden(int index, std::string message, int substring, int offset)
{
    if (index == -1)
    {
        system("clear");
        std::cout << "\n\n\n";
        for (int i = 0; i < 29; i++)
        {
            for (int j = 0; j < offset; j++)
                std::cout << ' ';
            if (offset < 103)
                std::cout << najaden[i].substr(substring) << '\n';
            else
                std::cout << najaden[i].substr(0, najaden[i].size() - (offset - 106) * 3 - 12) << '\n';
        }
        return;
    }

    std::cout << najaden[index] << '\t' << message;
    switch (index)
    {
    case 12:
    {
        if (status[1] != "")
            std::cout << "\t\t\t\t\t" << status[0];
        break;
    }

    case 13:
    {
        if (status[1] == "")
            std::cout << "\t\t\t\t\t" << status[0];
        std::cout << "\t\t\t\t\t" << status[1];
        break;
    }

    case 14:
    {
        if (isPasswording || isLogging) {
            if(isCreating) std::cout << "\t\t\t\t\t" << "Name: " << userName;
            else std::cout << "\t\t\t\t\t" << "Login: " << userLogin;
        }
        break;
    }

    case 15:
    {
        if (isPasswording)
        {
            std::cout << "\t\t\t\t\t" << "Password: ";
            for (int i = 0; i < userPassword.size(); i++)
                std::cout << '*';
        }
    }
    }

    std::cout << '\n';
}

void Login::printLogin(int logoOffset)
{
    int index = 0;

    std::string logo[] = {
        "\t\t\t.   .                .          ",
        "\t\t\t|\\  |      o         |          ",
        "\t\t\t| \\ | .-.  . .-.  .-.| .-. .--. ",
        "\t\t\t|  \\|(   ) |(   )(   |(.-' |  | ",
        "\t\t\t'   ' `-'`-| `-'`-`-'`-`--''  `-",
        "\t\t\t-----------;--------------------",
        "\t\t\t        `-'  "};

    system("clear");
    std::cout << "\n\n\n";
    for (int i = 0; i < logoOffset; i++)
    {
        printNajaden(index++, logo[i]);
    }

    if (logoOffset == 7)
    {
        printNajaden(index++);
        printNajaden(index++);
        printNajaden(index++, "ID\tUsername");
        printNajaden(index++, "--\t--------");

        for (auto &user : App::userMap)
        {
            std::string temp = std::to_string(user.second->getId()) + "\t" + user.second->getUsername();
            printNajaden(index++, temp);
        }
    }

    while (index < 29)
        printNajaden(index++);
}

void Login::startupAnimation()
{
    for (int i = 192; i >= 0; i = i - 3)
    {
        system("clear");
        printNajaden(-1, "", i);
        system("sleep 0.025");
    }

    for (int i = 0; i < 7; i += 1)
    {
        printLogin(i);
        system("sleep 0.15");
    }

    isLogging = true;
}

bool Login::promptCreate()
{
    char choice;
    while (1)
    {
        status[0] = "Account not found.";
        status[1] = "Would you like to create one? (y/n)";
        printLogin();
        choice = tolower(Helper::getInstance()->getch());
        switch (choice)
        {
        case 'y':
        {
            status[0] = status[1] = "";
            return 1;
        }
        case 'n':
        {
            status[0] = status[1] = userLogin = "";
            return 0;
        }
        }
    }
}

void Login::loginUser()
{
    char choice;
    while (1)
    {
        while (isLogging)
        {
            printLogin();
            choice = Helper::getInstance()->getch();

            switch (tolower(choice))
            {
            case 'a' ... 'z':
            case '0' ... '9':
            {
                if (isCreating)
                    userName += choice;
                else
                    userLogin += choice;
                break;
            }

            case ' ': {
                if (isCreating)
                    userName += choice;
                break;
            }

            case 27: {
                isCreating = 0;
                isLogging = 1;
                isPasswording = 0;
                userLogin = "";
                userPassword = "";
                status[0] = status[1] = "";
                break;
            }

            case 127:
            {
                if (isCreating)
                    userName = userName.substr(0, userName.size() - 1);
                else
                    userLogin = userLogin.substr(0, userLogin.size() - 1);
                break;
            }

            case 10:
            {
                if (isCreating)
                {
                    status[0] = "Please enter the password you want";
                    status[1] = "associated with the username: " + userLogin;
                    isLogging = false;
                    isPasswording = true;
                    break;
                }

                if (App::loginMap.count(userLogin))
                {
                    isLogging = false;
                    isPasswording = true;
                    status[0] = "";
                }
                else if (promptCreate())
                {
                    status[0] = "Please enter the name you want";
                    status[1] = "associated with the username: " + userLogin;
                    isCreating = true;
                }

                break;
            }
            }
        }

        while (isPasswording)
        {
            printLogin();
            choice = Helper::getInstance()->getch();
            switch (tolower(choice))
            {
            case 'a' ... 'z':
            case '0' ... '9':
            {
                userPassword += choice;
                break;
            }

            case 27: {
                isCreating = 0;
                isLogging = 1;
                isPasswording = 0;
                userLogin = "";
                userPassword = "";
                status[0] = status[1] = "";
                break;
            }

            case 127:
            {
                if (userPassword.size() == 0)
                {
                    isPasswording = false;
                    isLogging = true;
                    status[0] = "";
                }

                userPassword = userPassword.substr(0, userPassword.size() - 1);
                break;
            }

            case 10:
            {
                if (isCreating)
                {
                    if (userPassword.size() != 0)
                    {
                        int i = 1;
                        while (1)
                        {
                            if (!App::userMap.count(i))
                                break;
                            i++;
                        }

                        User *newUser = new User(i, userName, userLogin);

                        App::loginMap.insert({userLogin, LoginData(i, userPassword)});
                        App::userMap.insert({i, newUser});
                        App::currentUser = newUser;
                        
                        Helper::getInstance()->writeUsers();

                        status[0] = "Logged in successfully.";
                        status[1] = "You will be redirected shortly..";
                        isPasswording = isLogging = false;
                        printLogin();
                        system("sleep 1");
                        return;
                    }
                    break;
                }

                if (App::loginMap.at(userLogin).password == userPassword)
                {
                    App::currentUser = App::userMap.at(App::loginMap.at(userLogin).id);
                    isLogging = false;
                    isPasswording = false;
                    status[0] = "Logged in successfully.";
                    status[1] = "You will be redirected shortly..";
                    printLogin();
                    system("sleep 1");
                    return;
                }
                else
                    status[0] = "Invalid password.";
                break;
            }
            }
        }
    }
}

void Login::loginAnimation()
{
    for (int i = 0; i < 168; i += 1)
    {
        printNajaden(-1, "", 0, i);
        system("sleep 0.025");
    }
    system("clear");
}

void Login::loginScreen()
{
    comeSailAway();
    startupAnimation();
    loginUser();
    loginAnimation();
    userLogin = userName = userPassword = status[0] = status[1] = "";
    isLogging = isPasswording = isCreating = false;
}