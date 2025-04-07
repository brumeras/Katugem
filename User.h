#ifndef USER_H
#define USER_H

#include <string>

#include "Cat.h"

using namespace std;

class User
{
private:
    double dollars;
    Cat cat;

public:
    User();
    User(string catName);

    void setDollars(int dollars);
    void setCat(Cat cat);
    Cat& getCat();
    int getDollars();

    // these methods will be called after/during games
    void reward(double dollarsGained, int knowledgeGained);
    void punish(int knowledgeGained);
};

#endif
