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
        void addCardToPlayeingStack(const Card &card);
        void addCardToWonVector(const Card &card);
        int stacksize();
        int cardesTaken();
        string getName() const;
        string to_string() const;
        void shuffleWinningCards();
    };

}