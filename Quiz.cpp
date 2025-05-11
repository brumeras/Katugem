#include <fstream>
#include <sstream>
#include <iostream>

#include "Quiz.hpp"

using namespace std;

Quiz::Quiz(User& user) : user(user) {}

void Quiz::addWordPair(const string& english, const string& german)
{
    wordMap[english] = german;
}

void Quiz::loadWordsFromFile(const string& filename)
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

void Quiz::startQuiz()
{
    cout << "Welcome to the Translation Quiz!\n"
         << "Type the German translation of the English word.\n"
         << "Type '1' at any time to exit the quiz early.\n\n";

    Cat &cat = user.getCat();

    for (auto& pair : wordMap)
    {
        cout << "The German translation of \"" << pair.first << "\" >> ";
        string userAnswer;
        cin >> userAnswer;

        if(userAnswer=="1")
        {
            cout << "\nYou've chosen to end the quiz early.\n";
            break;
        }

        if (userAnswer == pair.second)
        {
            user.reward(1, 3);
            cout << "Correct! Well done, your reward is one Euro and 3 knowledge points for " << cat.getName() << "!!\n"
                 << "Current user account balance: " << user.getBalance() << " Euro\n"
                 << "Current " << cat.getName() << "'s knowledge: " << cat.getKnowledge() << " knowledge points\n\n";
        }
        else
        {
            user.punish(1);
            cout << "Oops! The correct answer is: \"" << pair.second << "\"... " << cat.getName() << "'s knowledge is decreasing...\n"
                 << "Current " << cat.getName() << "'s knowledge: " << cat.getKnowledge() << " knowledge points.\n\n";
        }
    }

    cout << "Stats after quiz: \n"
         << "Current user's account balance: " << user.getBalance() << " Euro\n"
         << "Current " << cat.getName() << "'s knowledge: " << cat.getKnowledge() << " knowledge points\n";
}
