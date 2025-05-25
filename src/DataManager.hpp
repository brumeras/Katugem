#ifndef DATAMANAGER_HPP
#define DATAMANAGER_HPP

#include <string>
#include <map>
#include <vector>

#include "User.hpp"

using namespace std;

struct Theme
{
    string name;
    string filename;
    string description;
};

class DataManager
{
private:
    const string savesPath = "src/saves/";
    const string resourcesPath = "src/resources/";
    map<string, string> wordMap;
    vector<Theme> availableThemes;

public:
    DataManager();
    
    void initializeThemes();
    void displayThemes() const;
    bool loadWordsByTheme(int themeIndex);
    const vector<Theme>& getAvailableThemes() const;
    
    void addWordPair(const string &english, const string &german);
    void loadWordsFromFile(const string &filename);
    const map<string, string> &getWordMap() const;
    
    vector<Treat> loadTreatsFromFile(const string &filename);
    
    bool saveUserData(User &user, const string &filename);
    bool loadUserData(User &user, const string &filename);
};

#endif // DATAMANAGER_HPP