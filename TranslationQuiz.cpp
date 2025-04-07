#include "TranslationQuiz.h"

TranslationQuiz::TranslationQuiz(User& user) : user(user) {}

void TranslationQuiz::addWordPair(const string& english, const string& german)
{
    wordMap[english] = german;
}

// game simulation
void TranslationQuiz::startQuiz()
{
    cout << "Welcome to the Translation Quiz!" << endl;
    
    for (auto& pair : wordMap)
    {
        cout << "The German translation of \"" << pair.first << "\" >> ";
        string userAnswer;
        cin >> userAnswer;

        if (userAnswer == pair.second)
        {
            cout << "Correct! Well done, your reward is one dollar!" << endl;
            // call correct answer method
        }
        else
        {
            cout << "Oops! The correct answer is: \"" << pair.second << "\"... " << user.getCat().getName() << "'s knowledge is degrading..." << endl;
            // call wrong answer method
        }
    }
}
