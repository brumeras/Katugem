#ifndef TREATSHOP_HPP
#define TREATSHOP_HPP

#include <vector>
#include "User.hpp"

using namespace std;

class TreatShop
{
private:
    vector<Treat> availableTreats;

    void displayShop(User &user);

public:
    TreatShop();

    void enterShop(User &user);
    void displayInventory(User &user);

    void loadTreats(const vector<Treat> &treats);
    const vector<Treat> &getAvailableTreats() const;
};

#endif // TREATSHOP_HPP