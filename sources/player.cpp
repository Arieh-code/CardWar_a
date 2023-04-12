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

Card Player::drawCardFromPlayingStack()
{
    if (playingStack_.empty())
    {
        throw runtime_error("Cannot draw card: playing stack is empty");
    }
    Card drawnCard = playingStack_.top();
    playingStack_.pop();
    return drawnCard;
}

Card Player::drawCardFromWonPile()
{
    if (wonPile_.empty())
    {
        throw runtime_error("Cannot draw card: won pile is empty");
    }
    Card drawnCard = wonPile_.back();
    wonPile_.pop_back();
    return drawnCard;
}

int Player::stacksize() 
{
    return playingStack_.size();
}

int Player::cardesTaken() 
{
    return wonPile_.size();
}

void Player::addCardToPlayingStack(const Card &card)
{
    playingStack_.push(card);
}

void Player::addCardToWonVector(const Card &card)
{
    wonPile_.push_back(card);
}

int Player::getRoundsWon()
{
    return this->roundsWon;
}

void Player::increaseRoundsWon()
{
    this->roundsWon++;
}

void Player::setRoundsWon(int num)
{
    this->roundsWon = num;
}
