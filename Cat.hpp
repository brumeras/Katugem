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

    string getName() const;
    double getWeight() const;
    int getAge() const;
    int getKnowledge() const;
};

#endif // CAT_HPP
