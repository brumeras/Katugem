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
    setDollars(0);
}

void User::setDollars(int dollars)
{
    this->dollars = dollars;
}

void User::setCat(Cat cat)
{
    this->cat = cat;
}

Cat& User::getCat()
{
    return cat;
}

int User::getDollars()
{
    return this->dollars;
}

void User::reward(double dollarsGained, int knowledgeGained)
{
    int dollarsCurrent = this->getDollars();
    this->setDollars(dollarsCurrent + dollarsGained);

    int knowledgeCurrent = this->getCat().getKnowledge();
    this->getCat().setKnowledge(knowledgeCurrent + knowledgeGained);
}

void User::punish(int knowledgeLost)
{
    int currentKnowledge = this->getCat().getKnowledge();
    this->getCat().setKnowledge(currentKnowledge - knowledgeLost);
}
