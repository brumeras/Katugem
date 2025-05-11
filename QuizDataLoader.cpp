#include <fstream>
#include <sstream>

#include "QuizDataLoader.hpp"

void QuizDataLoader::addWordPair(const string &english, const string &german)
{
    wordMap[english] = german;
}

void QuizDataLoader::loadWordsFromFile(const string &filename)
{
    ifstream file(filename);
    if (!file)
    {
        cerr << "Failed to open file: " << filename << endl;
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

const map<string, string>& QuizDataLoader::getWordMap() const
{
    return wordMap;
}