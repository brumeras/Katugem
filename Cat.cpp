#include <iostream>
#include <vector>

using namespace std;

class Cat
{
private:
    string name;
    double weight;
    int age;
    int knowledge;

public:
    Cat(string name)
    {
        setName(name);
        setWeight(0.1);
        setAge(0);
        setKnowledge(0);
    }

    void setName(string name)
    {
        this->name = name;
    }
    void setWeight(double weight)
    {
        this->weight = weight;
    }
    void setAge(int age)
    {
        this->age = age;
    }
    void setKnowledge(int knowledge)
    {
        this->knowledge = knowledge;
    }

};

