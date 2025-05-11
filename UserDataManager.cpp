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
    int catAge, catKnowledge, balance;

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

    inputFile.close();

    return true;
}