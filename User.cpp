#include <iostream>
#include <string>
#include <memory>

#include "User.hpp"

using namespace std;

User::User()
{
    setCat(Cat("Unnamed"));
    setBalance(0);
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

Cat &User::getCat()
{
    return cat;
}

int User::getBalance()
{
    return this->balance;
}

void User::setLearningStrategy()
{
    if (strategy != nullptr)
    {
        delete strategy;
        strategy = nullptr;
    }

    strategy = new LearningQuizStrategy(&cat, &balance);
}

void User::setTestingStrategy()
{
    if (strategy != nullptr)
    {
        delete strategy;
        strategy = nullptr;
    }

    strategy = new TestingQuizStrategy(&cat, &balance);
}

void User::runQuiz(map<string, string> wordMap)
{
    strategy->runQuiz(wordMap);
}

