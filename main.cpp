#include <iostream>
#include <string>

#include "User.hpp"
#include "Cat.hpp"
#include "Quiz.hpp"

using namespace std;

int main()
{
    cout << "\n---------------------------------------------\n"
         << "               Grow Your German"
         << "\n---------------------------------------------\n\n"
         << "Your cat has just been born, give it a name!\n"
         << "Cat's name >> ";

    string catName;
    cin >> catName;

    User user(catName);

    cout << "\nYour dear " << user.getCat().getName() << "'s current stats:\n"
         << "Name:\t\t" << user.getCat().getName() << "\n"
         << "Age:\t\t" << user.getCat().getAge() << " years\n"
         << "Weight:\t\t" << user.getCat().getWeight() << " kilograms\n"
         << "Knowledge:\t" << user.getCat().getKnowledge() << " knowledge points\n\n"
         << "Your current balance: " << user.getBalance()
         << " euros!\nGet more Euros by playing interactive German learning games to buy "
         << user.getCat().getName() << " some treats!\n\n"
         << "Starting Quiz...\n\n";

    Quiz quiz(user);

    quiz.loadWordsFromFile("words.txt");

    quiz.startQuiz();

    return 0;
}
