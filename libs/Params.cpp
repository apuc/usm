#include <fstream>
#include <iostream>
#include <string>
#include "Params.h"

Params::Params(int argc, char* argv[])
{
    this->argc = argc;
    this->type = this->getType(argv);
    //this->type = this->getType(argv);
    std::cout << this->type << std::endl;
}

std::string Params::getType(char* argv[])
{
    if(this->argc > 1){
        if(std::string(argv[1]) == "user"){
            return "user";
        }
        if(std::string(argv[1]) == "group"){
            return "group";
        }
    }

    return "uncnown";
}