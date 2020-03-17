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

    if(argc > 1){
        if(std::string(argv[1]) == "list"){
            printList();
        }
    }
    
    std::cout << "Enter command" << std::endl;

    return 0;
}