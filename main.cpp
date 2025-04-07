#include <iostream>
#include <string>

#include "User.h"
#include "Cat.h"

using namespace std;

int main()
{
    User user("Spurga");
    Cat cat = user.getCat();
    cout << cat.getName(); 
}