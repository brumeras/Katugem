#include <iostream>
#include <string>

#include "User.h"
#include "Cat.h"
#include "TranslationQuiz.h"

using namespace std;

User::User()
{
}

User::User(string catName)
{
    setCat(Cat(catName));
}

void User::setId(int id)
{
    this->user_id = id;
}

void User::setCat(Cat cat)
{
    this->cat = cat;
}

Cat User::getCat()
{
    return cat;
}

int User::getId()
{
    return this->user_id;
}
