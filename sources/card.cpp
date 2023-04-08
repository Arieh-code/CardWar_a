#include <iostream>
#include <string>
#include "card.hpp"
using namespace std;
using namespace ariel;

Card::Card(int value, char symbol)
{
    this->value = value;
    this->symbol = symbol;
}

string Card::to_string() const
{
    return nameValueMap.at(value) + " of " + symbolValueMap.at(symbol);
}

int Card::getCardValue()
{
    return this->value;
}

char Card::getType()
{
    return this->symbol;
}

string Card::getCardName()
{
    return this->nameValueMap[this->value];
}