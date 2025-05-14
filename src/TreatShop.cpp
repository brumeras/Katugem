#include <iostream>
#include <limits>
#include <vector>

#include "TreatShop.hpp"

using namespace std;

TreatShop::TreatShop() : availableTreats()
{
    // Initialize with empty treats vector
}

void TreatShop::displayShop(User &user)
{
    cout << "\n---------------------------------------------\n";
    cout << "                TREAT SHOP";
    cout << "\n---------------------------------------------\n";
    cout << "Your balance: " << user.getBalance() << " euros\n\n";

    cout << "Available treats:\n";
    for (size_t i = 0; i < availableTreats.size(); ++i)
    {
        const Treat &treat = availableTreats[i];
        cout << i + 1 << ") " << treat.name << " - " << treat.price << " euros\n";
        cout << "   Weight increase: +" << treat.weightIncrease << " kg\n";
        cout << "   Knowledge boost: +" << treat.knowledgeIncrease << " points\n\n";
    }

    cout << availableTreats.size() + 1 << ") Back to main menu\n\n";
}

void TreatShop::enterShop(User &user)
{
    int choice = 0;

    while (choice != static_cast<int>(availableTreats.size()) + 1)
    {
        displayShop(user);

        cout << "Your choice >> ";
        cin >> choice;

        if (choice >= 1 && choice <= static_cast<int>(availableTreats.size()))
        {
            user.buyTreat(availableTreats[choice - 1]);

            user.ageCatSlightly();

            cout << "Press enter to continue >> ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            string temp;
            getline(cin, temp);
        }
        else if (choice != static_cast<int>(availableTreats.size()) + 1)
        {
            cout << "\nInvalid choice! Try again...\n\n";
        }
    }
}

void TreatShop::displayInventory(User &user)
{
    cout << "\n---------------------------------------------\n";
    cout << "             YOUR TREAT INVENTORY";
    cout << "\n---------------------------------------------\n";

    const vector<Treat> &treats = user.getOwnedTreats();

    if (treats.empty())
    {
        cout << "You don't have any treats yet!\n";
        cout << "Visit the shop to buy some treats for " << user.getCat().getName() << ".\n\n";
    }
    else
    {
        cout << "You have the following treats:\n\n";

        for (size_t i = 0; i < treats.size(); ++i)
        {
            cout << i + 1 << ") " << treats[i].name << "\n";
            cout << "   Weight increase: +" << treats[i].weightIncrease << " kg\n";
            cout << "   Knowledge boost: +" << treats[i].knowledgeIncrease << " points\n\n";
        }

        cout << treats.size() + 1 << ") Back to main menu\n\n";

        int choice = 0;
        cout << "Select a treat to feed to " << user.getCat().getName() << " >> ";
        cin >> choice;

        if (choice >= 1 && choice <= static_cast<int>(treats.size()))
        {
            user.feedCat(choice - 1);

            cout << "\nPress enter to continue >> ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            string temp;
            getline(cin, temp);
        }
        else if (choice != static_cast<int>(treats.size()) + 1)
        {
            cout << "\nInvalid choice! Try again...\n\n";
        }
    }
}

void TreatShop::loadTreats(const vector<Treat> &treats)
{
    availableTreats = treats;
}

const vector<Treat> &TreatShop::getAvailableTreats() const
{
    return availableTreats;
}