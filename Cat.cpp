#include "Cat.hpp"

using namespace std;

Cat::Cat()
{
    setName("Unnamed");
    setWeight(0.1);
    setAge(0);
    setKnowledge(0);
}

Cat::Cat(string name)
{
    setName(name);
    setWeight(0.1);
    setAge(0);
    setKnowledge(0);
}

void Cat::setName(string name)
{
    this->name = name;
}

void Cat::setWeight(double weight)
{
    this->weight = weight;
}

void Cat::setAge(int age)
{
    this->age = age;
}

void Cat::setKnowledge(int knowledge)
{
    this->knowledge = knowledge;
}

string Cat::getName() const
{
    return name;
}

double Cat::getWeight() const
{
    return weight;
}

int Cat::getAge() const
{
    return age;
}

int Cat::getKnowledge() const
{
    return knowledge;
}
