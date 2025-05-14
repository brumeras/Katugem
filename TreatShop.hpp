#ifndef TREATSHOP_HPP
#define TREATSHOP_HPP

#include <vector>
#include "User.hpp"

using namespace std;

class TreatShop
{
private:
    static const vector<Treat> availableTreats;
    
    static void displayShop(User& user);

public:
    static void enterShop(User& user);
    static void displayInventory(User& user);
};

#endif // TREATSHOP_HPP