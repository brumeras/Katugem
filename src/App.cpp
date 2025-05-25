#include <iostream>
#include <string>
#include <limits>

#include "User.hpp"
#include "DataManager.hpp"
#include "TreatShop.hpp"

using namespace std;

void displayThemeSelectionAndLoad(DataManager &dataManager);

int main()
{
     cout << "\n---------------------------------------------\n"
          << "               Grow Your German"
          << "\n---------------------------------------------\n\n";

     DataManager dataManager;
     TreatShop treatShop;

     vector<Treat> treats = dataManager.loadTreatsFromFile("treats.txt");
     if (!treats.empty())
     {
          treatShop.loadTreats(treats);
     }
     else
     {
          cout << "Failed to load treats from file. Using default treats.\n\n";
     }

     int gameRunning = 1;

     while (gameRunning)
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
               << user.getCat().getName() << " some treats!\n\n";

          displayThemeSelectionAndLoad(dataManager);

          int input = 0;
          while (input != 8 && input != 10)
          {
               cout << "\nWhat kind of adventures are you and " << user.getCat().getName() << " up to?!\n"
                    << "1) Choose word theme.\n"
                    << "2) Start quiz in learning mode.\n"
                    << "3) Start quiz in testing mode.\n"
                    << "4) Go to the treat shop.\n"
                    << "5) Feed your cat a treat.\n"
                    << "6) Save user data.\n"
                    << "7) Load user data.\n"
                    << "8) Create a new user.\n"
                    << "9) See user data.\n"
                    << "10) None. Let me out.\n\n"
                    << "\nYour choice >> ";

               cin >> input;

               if (cin.fail())
               {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "\nInvalid input! Please enter a number between 1 and 10.\n";
                    input = 0;
                    continue;
               }

               switch (input)
               {
               case 1:
                    displayThemeSelectionAndLoad(dataManager);
                    user.ageCatSlightly();
                    break;

               case 2:
                    if (dataManager.getWordMap().empty())
                    {
                         cout << "\nNo words loaded! Please select a theme first.\n\n";
                    }
                    else
                    {
                         cout << "\n";
                         user.setLearningStrategy();
                         user.runQuiz(dataManager.getWordMap());
                    }
                    break;

               case 3:
                    if (dataManager.getWordMap().empty())
                    {
                         cout << "\nNo words loaded! Please select a theme first.\n\n";
                    }
                    else
                    {
                         cout << "\n";
                         user.setTestingStrategy();
                         user.runQuiz(dataManager.getWordMap());
                    }
                    break;

               case 4:
                    treatShop.enterShop(user);
                    break;

               case 5:
                    treatShop.displayInventory(user);
                    break;

               case 6:
               {
                    string filename;
                    cout << "\nEnter a filename to save your data >> ";
                    cin >> filename;

                    if (dataManager.saveUserData(user, filename))
                    {
                         cout << "\nUser data saved successfully to " << filename << "!\n\n";
                    }
                    else
                    {
                         cout << "\nFailed to save user data.\n\n";
                    }

                    user.ageCatSlightly();

                    cout << "Press enter to continue >> ";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    string temp;
                    getline(cin, temp);
               }

               break;

               case 7:
               {
                    string filename;
                    cout << "\nEnter the filename to load your data from >> ";
                    cin >> filename;

                    if (dataManager.loadUserData(user, filename))
                    {
                         cout << "\nUser data loaded successfully from " << filename << "!\n";
                         cout << "\nLoaded " << user.getCat().getName() << "'s stats:\n"
                              << "Name:\t\t" << user.getCat().getName() << "\n"
                              << "Age:\t\t" << user.getCat().getAge() << " years\n"
                              << "Weight:\t\t" << user.getCat().getWeight() << " kilograms\n"
                              << "Knowledge:\t" << user.getCat().getKnowledge() << " knowledge points\n"
                              << "Balance:\t" << user.getBalance() << " euros\n\n";
                    }
                    else
                    {
                         cout << "\nFailed to load user data.\n\n";
                    }

                    user.ageCatSlightly();

                    cout << "Press enter to continue >> ";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    string temp;
                    getline(cin, temp);
               }

               break;

               case 8:
                    cout << "\nStarting over...\n\n";
                    break;

               case 9:
               {
                    cout << "\nYour dear " << user.getCat().getName() << "'s current stats:\n"
                         << "Name:\t\t" << user.getCat().getName() << "\n"
                         << "Age:\t\t" << user.getCat().getAge() << " years\n"
                         << "Weight:\t\t" << user.getCat().getWeight() << " kilograms\n"
                         << "Knowledge:\t" << user.getCat().getKnowledge() << " knowledge points\n\n"
                         << "Your current balance: " << user.getBalance() << " euros!\n\n";

                    const vector<Treat> &treats = user.getOwnedTreats();
                    cout << "Your inventory has " << treats.size() << " treats.\n\n";

                    user.ageCatSlightly();

                    cout << "Press enter to continue >> ";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    string temp;
                    getline(cin, temp);

                    break;
               }

               case 10:
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

void displayThemeSelectionAndLoad(DataManager &dataManager)
{
     cout << "\nStarting theme selection...\n";

     int themeChoice = 0;
     bool validSelection = false;

     while (!validSelection)
     {
          dataManager.displayThemes();

          cout << "Select your theme >> ";
          cin >> themeChoice;

          if (dataManager.loadWordsByTheme(themeChoice))
          {
               validSelection = true;
               cout << "Theme loaded successfully! Ready to start learning.\n";
          }
          else
          {
               cout << "Failed to load theme. Please try again.\n\n";
          }
     }

     cout << "Press enter to continue >> ";
     cin.ignore(numeric_limits<streamsize>::max(), '\n');
     string temp;
     getline(cin, temp);
}