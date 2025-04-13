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
    setBalance(0);
}

void User::setBalance(int balance)
{
    this->balance = balance;
}

void User::setCat(Cat cat)
{
    this->cat = cat;
}

Cat& User::getCat()
{
    return cat;
}

int User::getBalance()
{
    return this->balance;
}

void User::reward(double balanceGained, int knowledgeGained)
{
    int balanceCurrent = this->getBalance();
    this->setBalance(balanceCurrent + balanceGained);

    int knowledgeCurrent = this->getCat().getKnowledge();
    this->getCat().setKnowledge(knowledgeCurrent + knowledgeGained);
}

void User::punish(int knowledgeLost)
{
    int currentKnowledge = this->getCat().getKnowledge();
    this->getCat().setKnowledge(currentKnowledge - knowledgeLost);
}
