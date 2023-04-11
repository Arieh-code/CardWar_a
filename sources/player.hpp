#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include "card.hpp"
using namespace std;
namespace ariel
{
    class Player
    {
        string name;
        stack<Card> playingStack_;
        vector<Card> wonPile_;

    public:
        Player(const string &playerName);
        void addCardToPlayingStack(const Card &card);
        void addCardToWonVector(const Card &card);
        Card drawCardFromPlayingStack();
        Card drawCardFromWonPile();
        int stacksize() const;
        int cardesTaken() const;
        string getName() const;
        string to_string() const;
        // void shuffleWinningCards();
    };

}