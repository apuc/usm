#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Params.h"

Params::Params(int argc, char *argv[])
{
    this->argc = argc;
    this->setArgv(argv);

    this->type = this->getType();
    this->command = this->getCommand();
    
    //this->type = this->getType(argv);
    //std::cout << this->command << std::endl;
}

std::string Params::getType()
{
    if(this->argc > 1){
        if(std::string(this->argv[1]) == "user"){
            return "user";
        }
        if(std::string(this->argv[1]) == "group"){
            return "group";
        }
    }

    return "uncnown";
}

std::string Params::getCommand()
{
    if(this->argc > 2){
        return this->argv[2];
    }

    return "uncnown";
}

bool Params::hasFlag(std::string flag)
{
    for(int i = 0; i < argv.size(); i++){
        if(flag == argv[i]){
            return true;
        }
    }
    return false;
}

void Params::setArgv(char *argv[])
{
    for ( size_t i = 0; i < this->argc; i++ ) {
        this->argv.push_back(*(argv+i));
    }
}