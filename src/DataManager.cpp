#include <fstream>
#include <sstream>
#include <iostream>

#include "DataManager.hpp"

DataManager::DataManager() : wordMap()
{
    initializeThemes();
}

void DataManager::initializeThemes()
{
    availableThemes.clear();

    availableThemes.push_back({"Basic Words", "words.txt", "Essential everyday German words"});
    availableThemes.push_back({"Numbers", "numbers.txt", "Learn German numbers from 1 to 1000"});
    availableThemes.push_back({"Colors", "colors.txt", "All the colors of the rainbow in German"});
    availableThemes.push_back({"Family", "family.txt", "Family members and relationships"});
    availableThemes.push_back({"Food & Drinks", "food.txt", "Delicious German food vocabulary"});
    availableThemes.push_back({"Animals", "animals.txt", "Wild and domestic animals in German"});
}

void DataManager::displayThemes() const
{
    cout << "\n---------------------------------------------\n";
    cout << "             CHOOSE YOUR THEME";
    cout << "\n---------------------------------------------\n\n";

    for (size_t i = 0; i < availableThemes.size(); ++i)
    {
        cout << i + 1 << ") " << availableThemes[i].name << "\n";
        cout << "   " << availableThemes[i].description << "\n\n";
    }

    cout << availableThemes.size() + 1 << ") Use all themes (mixed)\n";
    cout << "   Practice words from all available themes\n\n";
}

bool DataManager::loadWordsByTheme(int themeIndex)
{
    wordMap.clear();

    if (themeIndex >= 1 && themeIndex <= static_cast<int>(availableThemes.size()))
    {
        // Load specific theme
        const Theme &selectedTheme = availableThemes[themeIndex - 1];
        cout << "\nLoading theme: " << selectedTheme.name << "\n";
        loadWordsFromFile(selectedTheme.filename);

        if (wordMap.empty())
        {
            cout << "Warning: No words loaded from " << selectedTheme.filename << "\n";
            return false;
        }

        cout << "Loaded " << wordMap.size() << " words from " << selectedTheme.name << " theme!\n\n";
        return true;
    }
    else if (themeIndex == static_cast<int>(availableThemes.size()) + 1)
    {
        // Load all themes
        cout << "\nLoading all themes...\n";

        for (const Theme &theme : availableThemes)
        {
            cout << "Loading " << theme.name << "...\n";
            loadWordsFromFile(theme.filename);
        }

        if (wordMap.empty())
        {
            cout << "Warning: No words loaded from any theme files\n";
            return false;
        }

        cout << "Loaded " << wordMap.size() << " words from all themes!\n\n";
        return true;
    }
    else
    {
        cout << "\nInvalid theme selection!\n\n";
        return false;
    }
}

const vector<Theme> &DataManager::getAvailableThemes() const
{
    return availableThemes;
}

void DataManager::addWordPair(const string &english, const string &german)
{
    wordMap[english] = german;
}

void DataManager::loadWordsFromFile(const string &filename)
{
    string fullPath = resourcesPath + filename;

    ifstream file(fullPath);
    if (!file)
    {
        cerr << "Failed to open file: " << fullPath << "\n";
        return;
    }

    string line;
    while (getline(file, line))
    {
        istringstream iss(line);
        string english, german;
        if (iss >> english >> german)
        {
            addWordPair(english, german);
        }
    }

    file.close();
}

const map<string, string> &DataManager::getWordMap() const
{
    return wordMap;
}

vector<Treat> DataManager::loadTreatsFromFile(const string &filename)
{
    string fullPath = resourcesPath + filename;
    vector<Treat> treats;

    ifstream file(fullPath);
    if (!file)
    {
        cerr << "Failed to open treats file: " << fullPath << "\n";
        return treats;
    }

    string line;
    while (getline(file, line))
    {
        istringstream iss(line);
        Treat treat;

        if (iss >> treat.name >> treat.price >> treat.weightIncrease >> treat.knowledgeIncrease)
        {
            size_t pos = 0;
            while ((pos = treat.name.find('_', pos)) != string::npos)
            {
                treat.name.replace(pos, 1, " ");
                pos += 1;
            }

            treats.push_back(treat);
        }
    }

    file.close();
    return treats;
}

bool DataManager::saveUserData(User &user, const string &filename)
{
    string fullPath = savesPath + filename;
    ofstream outputFile(fullPath);

    if (!outputFile)
    {
        cerr << "Error: Could not open file " << fullPath << " for writing.\n";
        return false;
    }

    outputFile << user.getCat().getName() << "\n";
    outputFile << user.getCat().getWeight() << "\n";
    outputFile << user.getCat().getAge() << "\n";
    outputFile << user.getCat().getKnowledge() << "\n";

    outputFile << user.getBalance() << "\n";

    const vector<Treat> &treats = user.getOwnedTreats();
    outputFile << treats.size() << "\n";

    for (const Treat &treat : treats)
    {
        outputFile << treat.name << "\n";
        outputFile << treat.price << "\n";
        outputFile << treat.weightIncrease << "\n";
        outputFile << treat.knowledgeIncrease << "\n";
    }

    outputFile.close();

    return true;
}

bool DataManager::loadUserData(User &user, const string &filename)
{
    string fullPath = savesPath + filename;
    ifstream inputFile(fullPath);

    if (!inputFile)
    {
        cerr << "Error: Could not open file " << fullPath << " for reading.\n";
        return false;
    }

    string catName;
    double catWeight;
    double catAge;
    int catKnowledge, balance;

    getline(inputFile, catName);
    inputFile >> catWeight;
    inputFile >> catAge;
    inputFile >> catKnowledge;

    inputFile >> balance;

    Cat cat(catName);
    cat.setWeight(catWeight);
    cat.setAge(catAge);
    cat.setKnowledge(catKnowledge);

    user.setCat(cat);
    user.setBalance(balance);

    int treatCount;
    inputFile >> treatCount;
    inputFile.ignore();

    for (int i = 0; i < treatCount; ++i)
    {
        Treat treat;

        getline(inputFile, treat.name);
        inputFile >> treat.price;
        inputFile >> treat.weightIncrease;
        inputFile >> treat.knowledgeIncrease;

        inputFile.ignore();

        user.buyTreat(treat);
        user.setBalance(user.getBalance() + treat.price);
    }

    inputFile.close();

    return true;
}