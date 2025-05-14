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
    const string savesPath = "src/saves/";
    const string resourcesPath = "src/resources/";
    map<string, string> wordMap;

public:
    DataManager();
    
    void addWordPair(const string &english, const string &german);
    void loadWordsFromFile(const string &filename);
    const map<string, string> &getWordMap() const;
    
    vector<Treat> loadTreatsFromFile(const string &filename);
    
    bool saveUserData(User &user, const string &filename);
    bool loadUserData(User &user, const string &filename);
};

#endif // DATAMANAGER_HPP