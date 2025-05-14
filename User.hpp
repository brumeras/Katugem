#ifndef USER_HPP
#define USER_HPP

#include <string>
#include <memory>
#include <map>
#include <vector>

#include "Cat.hpp"
#include "QuizStrategy.hpp"

using namespace std;

class QuizStrategy;

struct Treat
{
    string name;
    double price;
    double weightIncrease;
    int knowledgeIncrease;
};

class User
{
private:
    double balance;
    Cat cat;
    QuizStrategy *strategy = nullptr;
    vector<Treat> ownedTreats;

public:
    User();
    User(string catName);
    ~User();

    void setBalance(int balance);
    void setCat(Cat cat);
    Cat &getCat();
    int getBalance() const;

    void buyTreat(const Treat &treat);
    void feedCat(int treatIndex);
    const vector<Treat> &getOwnedTreats() const;
    void ageCatSlightly();

    void setLearningStrategy();
    void setTestingStrategy();

    void runQuiz(map<string, string> wordMap);
};

#endif