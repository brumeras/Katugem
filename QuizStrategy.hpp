#ifndef QUIZSTRATEGY_HPP
#define QUIZSTRATEGY_HPP

#include <string>
#include <map>

#include "User.hpp"

using namespace std;

class QuizStrategy
{
protected:
    Cat *cat;
    double *balance;

public:
    QuizStrategy(Cat *catPtr, double *balancePtr)
        : cat(catPtr), balance(balancePtr) {}

    virtual ~QuizStrategy() = default;
    virtual void runQuiz(const map<string, string> &wordMap) = 0;
};

class LearningQuizStrategy : public QuizStrategy
{
public:
    LearningQuizStrategy(Cat *catPtr, double *balancePtr)
        : QuizStrategy(catPtr, balancePtr) {}

    void runQuiz(const map<string, string> &wordMap) override;
};

class TestingQuizStrategy : public QuizStrategy
{
public:
    TestingQuizStrategy(Cat *catPtr, double *balancePtr)
        : QuizStrategy(catPtr, balancePtr) {}

    void runQuiz(const map<string, string> &wordMap) override;
};

#endif // QUIZSTRATEGY_HPP