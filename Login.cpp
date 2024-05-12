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
        if (isPasswording || isLogging)
            std::cout << "\t\t\t\t\t" << "Login: " << userLogin;
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
    for (int i = 192; i >= 0; i = i - 18)
    {
        system("clear");
        printNajaden(-1, "", i);
        system("sleep 0.3");
    }

    for (int i = 0; i < 7; i += 2)
    {
        printLogin(i);
        system("sleep 0.3");
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
            status[0] = status[1] = "";
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
            choice = tolower(Helper::getInstance()->getch());
            
            switch (choice)
            {
            case 'a' ... 'z':
            case '0' ... '9':
            {
                userLogin += choice;
                break;
            }

            case 127:
            {
                userLogin = userLogin.substr(0, userLogin.size() - 1);
                break;
            }

            case 10:
            {
                if (App::loginMap.count(userLogin))
                {
                    isLogging = false;
                    isPasswording = true;
                    status[0] = "";
                }
                else if (promptCreate())
                {
                    return;
                }

                break;
            }
            }
        }

        while (isPasswording)
        {
            printLogin();
            choice = tolower(Helper::getInstance()->getch());
            switch (choice)
            {
            case 'a' ... 'z':
            case '0' ... '9':
            {
                userPassword += choice;
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
    for (int i = 0; i < 168; i += 16)
    {
        printNajaden(-1, "", 0, i);
        system("sleep 0.4");
    }
    system("clear");
}

void Login::loginScreen()
{
    comeSailAway();
    startupAnimation();
    loginUser();
    loginAnimation();
}