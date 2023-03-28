#include <iostream>
#include "player.hpp"
using namespace ariel;
using namespace std;

Player::Player(string name)
{
    this->name = name;
}

string Player::getName()
{
    return this->name;
}

string Player::to_string()
{
    return "" + this->name;
}

int Player::stacksize()
{
    return this->cards.size();
}

int Player::cardesTaken()
{
    return this->points;
}