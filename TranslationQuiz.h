#ifndef TRANSLATIONQUIZ_H
#define TRANSLATIONQUIZ_H

#include <iostream>
#include <map>
#include <string>
#include "User.h"  

using namespace std;

class TranslationQuiz
{
private:
    map<string, string> wordMap;
    User& user;

public:
    TranslationQuiz(User& user);
    void addWordPair(const string& english, const string& german);
    void startQuiz();
};

#endif
