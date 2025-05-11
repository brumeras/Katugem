#ifndef USER_HPP
#define USER_HPP

#include <string>
#include <memory>
#include <map>

#include "Cat.hpp"
#include "QuizStrategy.hpp"

using namespace std;

class QuizStrategy;

class User
{
private:
    double balance;
    Cat cat;
    QuizStrategy *strategy = nullptr;

public:
    User();
    User(string catName);

    void setBalance(int balance);
    void setCat(Cat cat);
    Cat& getCat();
    int getBalance();

    void setLearningStrategy();
    void setTestingStrategy();

    void runQuiz(map<string, string> wordMap);
};

#endif