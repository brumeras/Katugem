#include <iostream>
#include <string>

#include "User.h"
#include "Cat.h"

using namespace std;

User::User(string catName)
{
    setCat(Cat(catName));
}

void User::setCat(Cat cat)
{
    this->cat = cat;
}

Cat User::getCat()
{
    return cat;
}
