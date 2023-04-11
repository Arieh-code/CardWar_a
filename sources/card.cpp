#include <iostream>
#include <string>
#include "card.hpp"
using namespace std;
using namespace ariel;

Card::Card(int value, char symbol)
{
    this->value = value;
    this->symbol = symbol;
    nameValueMap[1] = "Ace";
    nameValueMap[2] = "2";
    nameValueMap[3] = "3";
    nameValueMap[4] = "4";
    nameValueMap[5] = "5";
    nameValueMap[6] = "6";
    nameValueMap[7] = "7";
    nameValueMap[8] = "8";
    nameValueMap[9] = "9";
    nameValueMap[10] = "10";
    nameValueMap[11] = "Jack";
    nameValueMap[12] = "Queen";
    nameValueMap[13] = "King";

    // Initialize symbol-value map
    symbolValueMap['S'] = "Spades";
    symbolValueMap['H'] = "Hearts";
    symbolValueMap['D'] = "Diamonds";
    symbolValueMap['C'] = "Clubs";
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