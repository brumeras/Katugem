#ifndef USER_H
#define USER_H

#include <string>

#include "Cat.h"

using namespace std;

class User
{
private:
    double balance;
    Cat cat;

public:
    User();
    User(string catName);

    void setBalance(int balance);
    void setCat(Cat cat);
    Cat& getCat();
    int getBalance();

    // these methods will be called after/during games
    void reward(double balanceGained, int knowledgeGained);
    void punish(int knowledgeGained);
};

#endif
