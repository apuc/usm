#include <iostream>
#include <fstream>
#include <string>
#include "libs/User.h"
 
int main()
{
    User user;

    std::cout << user.user_count << std::endl;
    std::cout << user.userVector[0] << std::endl;

    return 0;
}