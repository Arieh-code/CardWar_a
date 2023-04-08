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
        Card(int, char)
        {
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
    };
}