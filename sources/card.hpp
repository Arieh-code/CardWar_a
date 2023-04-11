#pragma once
#include <iostream>
#include <map>
using namespace std;
namespace ariel
{
    class Card
    {
        int value;
        char symbol;
        map<int, string> nameValueMap;
        map<char, string> symbolValueMap;

    public:
        int getCardValue();
        char getType();
        string to_string() const;
        string getCardName();
        Card(int, char);
        
    };
}