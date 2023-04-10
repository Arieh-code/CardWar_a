#include "game.hpp"
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace ariel;
using namespace std;

Game::Game(Player &p1, Player &p2)
    : player1(p1), player2(p2), roundCounter(0), drawCounter(0)
{
    // check if the same player is playing
    if (&p1 == &p2)
    {
        throw invalid_argument("Cannot play game againts yourself");
    }

    // initialize deck
    for (int i = 1; i <= 14; i++)
    {
        deck.push_back(Card(i, 'H'));
        deck.push_back(Card(i, 'D'));
        deck.push_back(Card(i, 'S'));
        deck.push_back(Card(i, 'C'));
    }

    shuffleDeck();
    dealCards();
}

void Game::shuffleDeck()
{
    random_shuffle(deck.begin(), deck.end());
}

void Game::dealCards()
{
    for (int i = 0; i < 26; i++)
    {
        player1.addCardToPlayingStack(deck.back());
        deck.pop_back();

        player2.addCardToPlayingStack(deck.back());
        deck.pop_back();
    }
}

void Game::playTurn()
{
    if (player1.stacksize() == 0 || player2.stacksize() == 0)

    {
        throw runtime_error("Cannot play turn: no cards in playing stack");
    }
};
void Game::playAll(){};
void Game::printLastTurn() const {};
void Game::printLog() const {};
void Game::printStats() const {};
void Game::printWiner() const {};
