#ifndef GAME_H_
#define GAME_H_

#include <vector>
#include <string>
#include "player.hpp"
#include "card.hpp"
using namespace std;

namespace ariel
{
    class Game
    {
    private:
        Player player1;
        Player player2;
        vector<Card> deck;
        vector<string> gameLog;
        int roundCounter;
        int drawCounter;

        void shuffleDeck();
        void dealCards();

    public:
        Game(Player &p1, Player &p2);
        void war(stringstream &logstrea, Card card1, Card card2);
        void playTurn();
        void printLastTurn() const;
        void printLog() const;
        void printStats() const;
        void printWiner() const;
        void playAll();
    };
}

#endif /* GAME_H_ */
