#include <fstream>
#include <sstream>
#include <iostream>

#include "DataManager.hpp"

DataManager::DataManager() : wordMap() 
{
    // Initialize with empty wordMap
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

const map<string, string>& DataManager::getWordMap() const
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
            while ((pos = treat.name.find('_', pos)) != string::npos) {
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
    
    const vector<Treat>& treats = user.getOwnedTreats();
    outputFile << treats.size() << "\n";
    
    for (const Treat& treat : treats)
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