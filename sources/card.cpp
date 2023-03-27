#include <iostream>
#include <string>
#include "card.hpp"
using namespace std;
using namespace ariel;

Card::Card(string name, string type, int value)
{
    this->name = name;
    this->type = type;
    this->value = value;
}

string Card::to_string()
{
    return "" + this->name + " of " + this->type;
}

int Card::getValue()
{
    return this->value;
}

string Card::getType()
{
    return this->type;
}

string Card::getName()
{
    return this->name;
}