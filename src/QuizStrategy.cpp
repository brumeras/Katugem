#include <iostream>
#include <limits>

#include "QuizStrategy.hpp"

using namespace std;

void LearningQuizStrategy::runQuiz(const map<string, string> &wordMap)
{
    // getline(cin, input) function misbehaves, if the "cin << <string>" function was called before
    // the newline character gets carried over and that results in an immediate call of getline(cin, input)
    // where input is "\n". This ignore function clears the buffer and is used repeatedly across the project
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Welcome to Learning Mode!\n"
         << "We'll show you English words and their German translations.\n"
         << "Type '1' at any time to exit.\n\n";

    const string name = cat->getName();
    string input;

    for (auto &pair : wordMap)
    {
        cout << "English: \"" << pair.first << "\" = German: \"" << pair.second << "\"\n";
        cout << "Press Enter to continue or type '1' to exit >> ";

        getline(cin, input);
        if (input == "1")
        {
            cout << "\nYou've chosen to end the learning session.\n";
            break;
        }

        cat->setKnowledge(cat->getKnowledge() + 1);

        user->ageCatSlightly();

        cout << name << " gained 1 knowledge point for reviewing this word!\n"
             << "Current " << name << "'s knowledge: " << cat->getKnowledge() << " points\n\n";
    }

    cout << "Learning session complete!\n"
         << "Current user's account balance: " << *balance << " Euro\n"
         << "Current " << name << "'s knowledge: " << cat->getKnowledge() << " knowledge points\n"
         << "Current " << name << "'s age: " << cat->getAge() << " years\n";
}

void TestingQuizStrategy::runQuiz(const map<string, string> &wordMap)
{
    cout << "Welcome to the Translation Quiz!\n"
         << "Type the German translation of the English word.\n"
         << "Type '1' at any time to exit the quiz early.\n\n";

    const string name = cat->getName();
    int correctCounter = 0;
    string userAnswer;

    for (auto &pair : wordMap)
    {
        cout << "The German translation of \"" << pair.first << "\" >> ";
        cin >> userAnswer;

        if (userAnswer == "1")
        {
            cout << "\nYou've chosen to end the quiz early.\n";
            break;
        }

        user->ageCatSlightly();

        if (userAnswer == pair.second)
        {
            ++correctCounter;

            *balance += 1;
            cat->setKnowledge(cat->getKnowledge() + 3);

            cout << "Correct! Well done, your reward is one Euro and 3 knowledge points for " << name << "!!\n"
                 << "Current user account balance: " << *balance << " Euro\n"
                 << "Current " << name << "'s knowledge: " << cat->getKnowledge() << " knowledge points\n\n";
        }
        else
        {
            cat->setKnowledge(cat->getKnowledge() - 1);
            cout << "Oops! The correct answer is: \"" << pair.second << "\"... " << name << "'s knowledge is decreasing...\n"
                 << "Current " << name << "'s knowledge: " << cat->getKnowledge() << " knowledge points.\n\n";
        }
    }

    cout << "Quiz complete!\n"
         << correctCounter << "/" << wordMap.size() << " correct answers!\n"
         << "Current user's account balance: " << *balance << " Euro\n"
         << "Current " << name << "'s knowledge: " << cat->getKnowledge() << " knowledge points\n"
         << "Current " << name << "'s age: " << cat->getAge() << " years\n";
}