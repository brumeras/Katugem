#include <iostream>
#include <string>

#include "User.hpp"
#include "Cat.hpp"
#include "QuizDataLoader.hpp"

using namespace std;

int main()
{
     cout << "\n---------------------------------------------\n"
          << "               Grow Your German"
          << "\n---------------------------------------------\n\n";

     int gameRunning = 1;

     while(gameRunning)
     {
          cout << "Your cat has just been born, give it a name!\n"
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

          QuizDataLoader loader;
          loader.loadWordsFromFile("words.txt");

          int input = 0;
          while (input != 7 && input != 8)
          {
               cout << "\nWhat kind of adventures are you and " << user.getCat().getName() << " are up to?!\n"
                    << "1) TODO: Choose word theme.\n"
                    << "2) Start quiz in learning mode.\n"
                    << "3) Start quiz in testing mode.\n"
                    << "4) TODO: Go to the treat shop.\n"
                    << "5) TODO: Save user data.\n"
                    << "6) TODO: Load user data.\n"
                    << "7) Create a new user.\n"
                    << "8) None. Let me out.\n"
                    << "\nYour choice >> ";

               cin >> input;

               switch (input)
               {
                    case 1:
                         cout << "\nTODO\n\n";
                         break;

                    case 2:
                         cout << "\n";
                         user.setLearningStrategy();
                         user.runQuiz(loader.getWordMap());
                         break;

                    case 3:
                         cout << "\n";
                         user.setTestingStrategy();
                         user.runQuiz(loader.getWordMap());
                         break;

                    case 4:
                         cout << "\nTODO\n\n";
                         break;

                    case 5:
                         cout << "\nTODO\n\n";
                         break;

                    case 6:
                         cout << "\nTODO\n\n";
                         break;

                    case 7:
                         cout << "\nStarting over...\n\n";
                         break;

                    case 8:
                         cout << "\nExiting program...\n\n";
                         gameRunning = 0;
                         break;
                    
                    default:
                         cout << "\nInvalid choice! Try again...\n\n";
                         break;
               }

          }
     }


    return 0;
}
