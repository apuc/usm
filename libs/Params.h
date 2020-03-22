#ifndef PARAMS_H
#define PARAMS_H
#include <string>
#include <vector>

class Params 
{

    public:
        int argc;

        std::vector<std::string> argv;

        std::string type;

        std::string command;

        Params(int argc, char *argv[]);

        std::string getType();

        std::string getCommand();

        bool isGroup();

        bool isUser();

        bool hasFlag(std::string flsg);

        void setArgv(char *argv[]);

};

#endif