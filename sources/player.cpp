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

void Player::addPoints(int num)
{
    this->points += num;
}

int Player::cardesTaken()
{
    return this->points;
}

int Player::getCards()
{
    return this->cards.size();
}