#ifndef QUIZSTRATEGY_HPP
#define QUIZSTRATEGY_HPP

#include <string>
#include <map>

#include "Cat.hpp"
#include "User.hpp"

using namespace std;

class User;

class QuizStrategy
{
protected:
    Cat *cat;
    double *balance;
    User *user;

public:
    QuizStrategy(Cat *catPtr, double *balancePtr, User *userPtr)
        : cat(catPtr), balance(balancePtr), user(userPtr) {}

    virtual ~QuizStrategy() = default;
    virtual void runQuiz(const map<string, string> &wordMap) = 0;
};

class LearningQuizStrategy : public QuizStrategy
{
public:
    LearningQuizStrategy(Cat *catPtr, double *balancePtr, User *userPtr)
        : QuizStrategy(catPtr, balancePtr, userPtr) {}

    void runQuiz(const map<string, string> &wordMap) override;
};

class TestingQuizStrategy : public QuizStrategy
{
public:
    TestingQuizStrategy(Cat *catPtr, double *balancePtr, User *userPtr)
        : QuizStrategy(catPtr, balancePtr, userPtr) {}

    void runQuiz(const map<string, string> &wordMap) override;
};

#endif // QUIZSTRATEGY_HPP