#pragma once
#include <iostream>
#include "card.hpp"

namespace ariel
{
    class Player
    {
        string name;

    public:
        Player(string);
        int cards;
        int points;

        int stacksize();
        int cardestaken();
        string getName();
        string to_string();
    };

}