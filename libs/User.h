#ifndef USER_H
#define USER_H
#include <vector>

struct UserData
{
    std::string name;
    std::string id;
    std::string homePath;
};  

class User 
{

    public:
        int user_count;

        std::vector<std::string> userVector;

        User();
        
        void getUsers();

        UserData setSingleUserData(std::string userData);

        UserData getById(int id);

        UserData getByName(std::string name);

        void printList(bool all);
        
        void printUser(UserData user);
};


#endif