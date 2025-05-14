#ifndef DATAMANAGER_HPP
#define DATAMANAGER_HPP

#include <string>
#include <map>
#include <vector>

#include "User.hpp"

using namespace std;

class DataManager
{
private:
    static const string savesPath;
    map<string, string> wordMap;

public:
    void addWordPair(const string &english, const string &german);
    void loadWordsFromFile(const string &filename);
    const map<string, string> &getWordMap() const;
    
    static bool saveUserData(User &user, const string &filename);
    static bool loadUserData(User &user, const string &filename);
};

#endif // DATAMANAGER_HPP