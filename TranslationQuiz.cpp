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
            cout << "Correct! Well done, your reward is one dollar and 3 knowledge points for " << cat.getName() << "!!" << endl;
            user.reward(1, 3);
            cout << "Current user account balance: $" << user.getDollars() << "\n"; 
            cout << "Current " << cat.getName() << "'s knowledge: " << cat.getKnowledge(); 
            cout << "\n\n";
        }
        else
        {
            cout << "Oops! The correct answer is: \"" << pair.second << "\"... " << cat.getName() << "'s knowledge is decreasing..." << endl;
            user.punish(1);
            cout << "Current " << cat.getName() << "'s knowledge: " << cat.getKnowledge(); 
            cout << '\n';
        }
    }

    cout << "Stats after quiz: \n";
    cout << "Current user account balance: $" << user.getDollars() << "\n"; 
    cout << "Current " << cat.getName() << "'s knowledge: " << cat.getKnowledge();

    user.setCat(cat);
}
