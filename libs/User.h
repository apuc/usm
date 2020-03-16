#ifndef USER_H
#define USER_H
#include <vector>

class User 
{

    public:
        int user_count;

        std::vector<std::string> userVector;

        User();
        
        void getUsers();
    
};

#endif