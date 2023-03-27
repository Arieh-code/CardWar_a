#pragma once
#include <iostream>
using namespace std;
namespace ariel
{
    class Card
    {
        int value;
        string name;
        string type;

    public:
        int getValue();
        string getType();
        string to_string();
        string getName();
        Card(string, string, int);
    };
}