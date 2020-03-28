#ifndef USER_H
#define USER_H
#include <vector>

struct UserData
{
    std::string name;
    std::string pass;
    std::string id;
    std::string groupId;
    std::string group;
    std::string homePath;
    std::string shell;
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

        void saveUsers();

        bool edit(int id, std::string param, std::string value);

        bool issetId(int id);

        std::string userDataToString(UserData ud);

    // private:
    //     std::string userDataToString(UserData ud);
};


#endif