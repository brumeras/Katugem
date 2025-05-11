#ifndef CAT_HPP
#define CAT_HPP

#include <string>

using namespace std;

class Cat
{
private:
    string name;
    double weight;
    int age;
    int knowledge;

public:
    Cat();
    Cat(string name);

    void setName(string name);
    void setWeight(double weight);
    void setAge(int age);
    void setKnowledge(int knowledge);

    string getName();
    double getWeight();
    int getAge();
    int getKnowledge();
};

#endif // CAT_HPP
