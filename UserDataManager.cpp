#include <fstream>
#include <iostream>

#include "UserDataManager.hpp"

const string savesPath = "saves/";

bool UserDataManager::saveUserData(User &user, const string &filename)
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

bool UserDataManager::loadUserData(User &user, const string &filename)
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