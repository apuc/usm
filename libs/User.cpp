#include <fstream>
#include <iostream>
#include <iomanip> 
#include <vector>
#include <sstream>
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

UserData User::setSingleUserData(std::string userData)
{
    const char delim = ':';
 
    std::vector<std::string> elems;
 
    std::stringstream ss(userData);
    std::string item;
    while(std::getline(ss, item, delim))
    {
        elems.push_back(item);
    }

    UserData ud = {elems[0], elems[2]};

    return ud;
}

void User::printList()
{
    const char separator    = ' ';

    for(int i = 0; i < userVector.size(); i++){
        UserData elem;
        elem = this->setSingleUserData(userVector[i]);
        std::cout << std::left << std::setw(30) << std::setfill(separator) << "name: " + elem.name;
        std::cout << std::left << std::setw(30) << std::setfill(separator) << "id: " + elem.id;
        std::cout << std::endl;
    }
    
}

