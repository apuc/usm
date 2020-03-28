#include <fstream>
#include <string>
#include <iostream>
#include <iterator>
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

    UserData ud = {elems[0], elems[1], elems[2], elems[3], elems[4], elems[5], elems[6]};

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

bool User::edit(int id, std::string param, std::string value)
{
    for(int i = 0; i < userVector.size(); i++){
        UserData elem;
        elem = this->setSingleUserData(userVector[i]);
        if(std::stoi(elem.id) == id){
            if(param == "name"){
                elem.name = value;
                userVector[i] = this->userDataToString(elem);
            }
            if(param == "homePath"){
                elem.homePath = value;
                userVector[i] = this->userDataToString(elem);
            }
        }
    }
    this->saveUsers();
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

void User::saveUsers()
{
    std::ofstream output_file("./example.txt");
    std::ostream_iterator<std::string> output_iterator(output_file, "\n");
    std::copy(userVector.begin(), userVector.end(), output_iterator);
}

std::string User::userDataToString(UserData ud)
{
    return ud.name + ":" + ud.pass + ":" + ud.id + ":" + ud.groupId + ":" + ud.group + ":" + ud.homePath + ":" + ud.shell;
}

bool User::issetId(int id)
{
    for(int i = 0; i < userVector.size(); i++){
        UserData elem;
        elem = this->setSingleUserData(userVector[i]);
        if(std::stoi(elem.id) == id){
            return true;
        }
    }

    return false;
}

