#include <iostream>
#include "player.hpp"
#include <algorithm>
#include <random>
#include <chrono>
using namespace ariel;
using namespace std;

// initialize player with satckpile and wonpile
Player::Player(const string &playerName) : name(playerName), playingStack_(), wonPile_()
{
}

string Player::getName() const
{
    return name;
}

string Player::to_string() const
{
    return name;
}

int Player::stacksize()
{
    return playingStack_.size();
}

int Player::cardesTaken()
{
    return wonPile_.size();
}

void Player::addCardToPlayeingStack(const Card &card)
{
    playingStack_.push(card);
}

void Player::addCardToWonVector(const Card &card)
{
    wonPile_.push_back(card);
}

// shuffle function to shuffle the winning packs if there is a draw with no cards left
void Player::shuffleWinningCards()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(wonPile_.begin(), wonPile_.end(), default_random_engine(seed));
}