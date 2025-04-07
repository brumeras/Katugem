#ifndef USER_H
#define USER_H

#include <string>

#include "Cat.h"

using namespace std;

class User
{
private:
    Cat cat;

public:
    User(string catName);
    void setCat(Cat cat);
    Cat getCat();
};

#endif
