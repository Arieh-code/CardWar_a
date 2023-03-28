#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "card.hpp"
using namespace std;
namespace ariel
{
    class Player
    {
        string name;

    public:
        Player(string);
        int points;
        int stacksize();
        int cardesTaken();
        string getName();
        string to_string();
        vector<Card> cards;
    };

}