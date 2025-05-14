#ifndef CAT_HPP
#define CAT_HPP

#include <string>

using namespace std;

class Cat
{
private:
    string name;
    double weight;
    double age;
    int knowledge;

public:
    Cat();
    Cat(string name);

    void setName(string name);
    void setWeight(double weight);
    void setAge(double age);
    void setKnowledge(int knowledge);

    string getName() const;
    double getWeight() const;
    double getAge() const;
    int getKnowledge() const;
};

#endif // CAT_HPP