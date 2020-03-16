#ifndef USER_H
#define USER_H
#include <vector>

struct UserData
{
    std::string name;
    std::string id;
};

class User 
{

    public:
        int user_count;

        std::vector<std::string> userVector;

        User();
        
        void getUsers();

        UserData setSingleUserData(std::string userData);

        void printList();
        
    
};


#endif