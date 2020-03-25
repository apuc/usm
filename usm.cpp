#include <iostream>
#include <fstream>
#include <string>
#include "libs/User.h"
#include "libs/Params.h"

void printList(bool all)
{
    User user;

    user.printList(all);
}

void getUserById(int id)
{
    User user;
    UserData userInfo;

    userInfo = user.getById(id);
    if (userInfo.id == ""){
        std::cout << "User not found" << std::endl;
    }
    else
    {
        user.printUser(userInfo);
    }
    
}

void getUserByName(std::string name)
{
    User user;
    UserData userInfo;

    userInfo = user.getByName(name);
    if (userInfo.id == ""){
        std::cout << "User not found" << std::endl;
    }
    else
    {
        user.printUser(userInfo);
    }
}
 
int main(int argc, char *argv[])
{
    Params params(argc, argv);

    // getUserById(1001);

    if(params.type == "user"){
        if(params.command == "list"){
            printList(params.hasFlag("--all"));
        }
        if(params.command == "get"){
            if(params.hasParam("--id")){
                std::string id = params.getParam("--id");
                if(id == ""){
                    std::cout << "User not found or --id parameter not specified" << std::endl;
                }
                else
                {
                    getUserById(std::stoi(id));
                }
                
            }
            else if(params.hasParam("--name")){
                std::string name = params.getParam("--name");
                if(name == ""){
                    std::cout << "User not found or --name parameter not specified" << std::endl;
                }
                else
                {
                    getUserByName(name);
                }
                
            }
            else
            {
                std::cout << "Need user --id or --name" << std::endl;
            }
            
            
        }
    }
    
    std::cout << "Enter command" << std::endl;

    return 0;
}