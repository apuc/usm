#include <iostream>
#include <fstream>
#include <string>
#include "libs/User.h"
#include "libs/Params.h"

void printList()
{
    User user;

    user.printList();
}
 
int main(int argc, char *argv[])
{
    Params params(argc, argv);

    std::cout << params.hasFlag("--all") << std::endl;

    if(params.type == "user"){
        if(params.command == "list"){
            printList();
        }
    }
    
    std::cout << "Enter command" << std::endl;

    return 0;
}