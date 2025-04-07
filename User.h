#ifndef USER_H
#define USER_H

#include <string>

#include "Cat.h"

using namespace std;

class User
{
private:
    int user_id;
    Cat cat;

public:
    User();
    User(string catName);
    void setId(int id);
    void setCat(Cat cat);
    Cat getCat();
    int getId();
};

#endif
