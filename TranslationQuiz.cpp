#include "TranslationQuiz.h"

TranslationQuiz::TranslationQuiz(User& user) : user(user) {}

void TranslationQuiz::addWordPair(const string& english, const string& german)
{
    wordMap[english] = german;
}

// game simulation
void TranslationQuiz::startQuiz()
{
    cout << "Welcome to the Translation Quiz!" << "\n\n";

    Cat &cat = user.getCat();

    for (auto& pair : wordMap)
    {
        cout << "The German translation of \"" << pair.first << "\" >> ";
        string userAnswer;
        cin >> userAnswer;

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
                 << "Current " << cat.getName() << "'s knowledge: " << cat.getKnowledge() << " knowledge points.\n";
        }
    }

    cout << "Stats after quiz: \n"
         << "Current user's account balance: " << user.getBalance() << " Euro\n"
         << "Current " << cat.getName() << "'s knowledge: " << cat.getKnowledge() << " knowledge points";
}
