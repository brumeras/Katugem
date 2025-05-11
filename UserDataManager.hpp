#ifndef USERDATAMANAGER_HPP
#define USERDATAMANAGER_HPP

#include <string>

#include "User.hpp"

class UserDataManager
{
public:
    static bool saveUserData(User &user, const string &filename);

    static bool loadUserData(User &user, const string &filename);
};

#endif // USERDATAMANAGER_HPP