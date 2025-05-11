#ifndef QUIZDATALOADER_HPP
#define QUIZDATALOADER_HPP

#include <iostream>
#include <map>
#include <string>

using namespace std;

class QuizDataLoader
{
private:
    map<string, string> wordMap;

public:
    void addWordPair(const string &english, const string &german);
    void loadWordsFromFile(const string &filename);

    const map<string, string> &getWordMap() const;
};

#endif // QUIZDATALOADER_HPP