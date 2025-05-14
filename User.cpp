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

User::~User()
{
    if (strategy != nullptr)
    {
        delete strategy;
        strategy = nullptr;
    }
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

int User::getBalance() const
{
    return this->balance;
}

const vector<Treat>& User::getOwnedTreats() const
{
    return ownedTreats;
}

void User::buyTreat(const Treat& treat)
{
    if (balance >= treat.price)
    {
        balance -= treat.price;
        ownedTreats.push_back(treat);
        cout << "You bought " << treat.name << " for " << treat.price << " euros!\n";
    }
    else
    {
        cout << "Not enough balance to buy this treat!\n";
    }
}

void User::feedCat(int treatIndex)
{
    if (treatIndex >= 0 && treatIndex < ownedTreats.size())
    {
        Treat treat = ownedTreats[treatIndex];
        
        // Update cat's weight and knowledge
        cat.setWeight(cat.getWeight() + treat.weightIncrease);
        cat.setKnowledge(cat.getKnowledge() + treat.knowledgeIncrease);
        
        // Age the cat slightly when fed
        cat.setAge(cat.getAge() + 0.1);
        
        // Remove the treat from inventory
        ownedTreats.erase(ownedTreats.begin() + treatIndex);
        
        cout << cat.getName() << " enjoyed the " << treat.name << "!\n";
        cout << "Weight increased by " << treat.weightIncrease << " kg.\n";
        cout << "Knowledge increased by " << treat.knowledgeIncrease << " points.\n";
        cout << cat.getName() << " is now " << cat.getAge() << " years old.\n";
    }
    else
    {
        cout << "Invalid treat selection!\n";
    }
}

void User::ageCatSlightly()
{
    // Age the cat by a very small amount (0.01 years) after each action
    cat.setAge(cat.getAge() + 0.01);
}

void User::setLearningStrategy()
{
    if (strategy != nullptr)
    {
        delete strategy;
        strategy = nullptr;
    }

    strategy = new LearningQuizStrategy(&cat, &balance, this);
}

void User::setTestingStrategy()
{
    if (strategy != nullptr)
    {
        delete strategy;
        strategy = nullptr;
    }

    strategy = new TestingQuizStrategy(&cat, &balance, this);
}

void User::runQuiz(map<string, string> wordMap)
{
    strategy->runQuiz(wordMap);
}