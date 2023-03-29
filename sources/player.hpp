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
        int points;
        vector<Card> cards;

    public:
        Player(string);
        int stacksize();
        int cardesTaken();
        string getName();
        string to_string();
        void addPoints(int num);
        int getCards();
    };

}