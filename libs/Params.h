#ifndef PARAMS_H
#define PARAMS_H
#include <string>
#include <vector>

class Params 
{

    public:
        int argc;

        std::string type;

        std::string command;

        Params(int argc, char* argv[]);

        std::string getType(char* argv[]);

        std::string getCommand();

        bool isGroup();

        bool isUser();

        bool hasFlag();

};

#endif