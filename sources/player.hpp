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
        int roundsWon;

    public:
        Player(const string &playerName);
        void addCardToPlayingStack(const Card &card);
        void addCardToWonVector(const Card &card);
        Card drawCardFromPlayingStack();
        Card drawCardFromWonPile();
        int stacksize();
        int cardesTaken();
        string getName() const;
        string to_string() const;
        int getRoundsWon();
        void increaseRoundsWon();
        void setRoundsWon(int num);
        // void shuffleWinningCards();
    };

}