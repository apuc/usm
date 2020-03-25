#include <fstream>
#include <string>
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

    UserData ud = {elems[0], elems[2], elems[5]};

    return ud;
}

UserData User::getById(int id)
{
    for(int i = 0; i < userVector.size(); i++){
        UserData elem;
        elem = this->setSingleUserData(userVector[i]);
        int currentId = std::stoi(elem.id);
        if(currentId == id){
            elem = this->setSingleUserData(userVector[i]);
            return elem;
        }
    }

    UserData empty;
    return empty;
}

UserData User::getByName(std::string name)
{
    for(int i = 0; i < userVector.size(); i++){
        UserData elem;
        elem = this->setSingleUserData(userVector[i]);
        if(elem.name == name){
            elem = this->setSingleUserData(userVector[i]);
            return elem;
        }
    }

    UserData empty;
    return empty;
}

void User::printList(bool all)
{
    for(int i = 0; i < userVector.size(); i++){
        UserData elem;
        elem = this->setSingleUserData(userVector[i]);
        if(all){
            printUser(elem);
        }
        else
        {
            if(std::stoi(elem.id) >= 1000 && std::stoi(elem.id) < 10000){
                printUser(elem);
            }
        }
        
        
    }
}

void User::printUser(UserData user)
{
    const char separator    = ' ';

    std::cout << std::left << std::setw(30) << std::setfill(separator) << "name: " + user.name;
    std::cout << std::left << std::setw(15) << std::setfill(separator) << "id: " + user.id;
    std::cout << std::left << std::setw(25) << std::setfill(separator) << "homePath: " + user.homePath;
    std::cout << std::endl;
}

