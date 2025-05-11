#ifndef QUIZ_HPP
#define QUIZ_HPP

#include <iostream>
#include <map>
#include <string>

#include "User.hpp"  

using namespace std;

class Quiz
{
private:
    map<string, string> wordMap;
    User& user;

public:
    Quiz(User& user);
    void addWordPair(const string& english, const string& german);
    void startQuiz();
    void loadWordsFromFile(const string& filename);
};

#endif // QUIZ_HPP
