#include <fstream>
#include <iostream>
#include <vector>
#include "User.h"

User::User()
{
    getUsers();
}

void User::getUsers()
{
    std::string *line = new std::string;
    user_count = 0;

    std::ifstream in("/etc/passwd"); // окрываем файл для чтения
    if (in.is_open())
    {
        while (getline(in, *line))
        {
            userVector.push_back(*line);
            user_count++;
        }
    }
    in.close();     // закрываем файл
    delete line;
}