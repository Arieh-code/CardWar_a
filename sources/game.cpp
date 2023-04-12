#include "game.hpp"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <random>
#include <sstream>
using namespace ariel;
using namespace std;

Game::Game(Player &p01, Player &p02)
    : player1(p01), player2(p02), roundCounter(0), drawCounter(0),
      deck({}), gameLog({})
{

    // initialize deck
    for (int i = 1; i <= 13; i++)
    {
        deck.push_back(Card(i, 'H'));
        deck.push_back(Card(i, 'D'));
        deck.push_back(Card(i, 'S'));
        deck.push_back(Card(i, 'C'));
    }

    this->roundCounter = 0;
    this->drawCounter = 0;
    player1.setRoundsWon(0);
    player2.setRoundsWon(0);
    shuffleDeck();
    dealCards();
}

void Game::shuffleDeck()
{
    random_device rd;
    mt19937 g(rd());
    std::shuffle(deck.begin(), deck.end(), g);
}

void Game::dealCards()
{
    if (deck.size() < 52)
    {
        throw runtime_error("Not enough cards in the deck to start the game");
    }
    for (int i = 0; i < 26; i++)
    {
        this->player1.addCardToPlayingStack(deck.back());
        deck.pop_back();

        this->player2.addCardToPlayingStack(deck.back());
        deck.pop_back();
    }
}

void Game::playTurn()
{
    // check if the same player is playing
    if (&player1 == &player2)
    {
        throw runtime_error("Cannot play turn : player game againts himself");
    }

    if (player1.stacksize() == 0 || player2.stacksize() == 0)

    {
        throw runtime_error("Cannot play turn: no cards in playing stack");
    }

    // add a to round counter
    this->roundCounter++;

    // get top card of each player stack

    Card card1 = player1.drawCardFromPlayingStack();
    Card card2 = player2.drawCardFromPlayingStack();

    stringstream logstream;
    logstream << player1.getName() << " played " << card1.to_string() << " and " << player2.getName() << " played " << card2.to_string() << ". ";

    if (card1.getCardValue() > card2.getCardValue() || (card1.getCardValue() == 1 && card2.getCardValue() != 2))

    {
        // player 1 wins
        player1.addCardToWonVector(card1);
        player1.addCardToWonVector(card2);
        logstream << player1.getName() << " wins.";
        this->gameLog.push_back(logstream.str());
        logstream.str("");
        logstream.clear();
        player1.increaseRoundsWon();
    }

    else if (card2.getCardValue() > card1.getCardValue() || (card2.getCardValue() == 1 && card1.getCardValue() != 2))

    {
        // player 2 wins
        player2.addCardToWonVector(card1);
        player2.addCardToWonVector(card2);
        logstream << player2.getName() << " wins.";
        this->gameLog.push_back(logstream.str());
        logstream.str("");
        logstream.clear();
        player2.increaseRoundsWon();
    }

    else
    {
        // add to draw counter
        this->drawCounter++;
        // its a tie, time for war!!!!
        logstream << " draw.";
        war(logstream, card1, card2);
    }
};

void Game::war(stringstream &logstream, Card card1, Card card2)
{
    bool warEnded = false;

    // add the cards into a vector
    vector<Card> warCards1;
    vector<Card> warCards2;
    warCards1.push_back(card1);
    warCards2.push_back(card2);

    while (!warEnded)

    {
        // check if players have at least two cards if not use winning pile
        if (player1.stacksize() >= 2 && player2.stacksize() >= 2)
        {
            // draw one faced down card from each player
            Card facedown1 = player1.drawCardFromPlayingStack();
            Card facedown2 = player2.drawCardFromPlayingStack();

            // draw one faced up card from each player
            Card faceup1 = player1.drawCardFromPlayingStack();
            Card faceup2 = player2.drawCardFromPlayingStack();

            warCards1.push_back(facedown1);
            warCards2.push_back(facedown2);
            warCards1.push_back(faceup1);
            warCards2.push_back(faceup2);

            logstream << player1.getName() << " played " << faceup1.to_string()
                      << " and " << player2.getName() << " played " << faceup2.to_string() << ". ";

            if (faceup1.getCardValue() > faceup2.getCardValue() || (faceup1.getCardValue() == 1 && faceup2.getCardValue() != 2))

            {
                // player 1 wins he gets all the cards
                for (const auto &card : warCards1)
                {
                    player1.addCardToWonVector(card);
                }
                for (const auto &card : warCards2)
                {
                    player1.addCardToWonVector(card);
                }
                logstream << player1.getName() << " wins.";
                this->gameLog.push_back(logstream.str());
                logstream.str("");
                logstream.clear();
                player1.increaseRoundsWon();
                warEnded = true;
            }

            else if (faceup2.getCardValue() > faceup1.getCardValue() || (faceup2.getCardValue() == 1 && faceup1.getCardValue() != 2))

            {
                // player 2 wins he gets all the cards
                for (const auto &card : warCards1)
                {
                    player2.addCardToWonVector(card);
                }
                for (const auto &card : warCards2)
                {
                    player2.addCardToWonVector(card);
                }
                logstream << player2.getName() << " wins.";
                this->gameLog.push_back(logstream.str());
                logstream.str("");
                logstream.clear();
                player2.increaseRoundsWon();
                warEnded = true;
            }

            else
            {
                // add to draw counter
                this->drawCounter++;
                logstream << " draw.";
            }
        }

        // players ran out of cards
        else
        {
            // each player gets the cards they have left.
            for (const auto &card : warCards1)
            {
                player1.addCardToWonVector(card);
            }
            for (const auto &card : warCards2)
            {
                player2.addCardToWonVector(card);
            }

            while (player1.stacksize() > 0 && player2.stacksize() > 0)
            {
                // removing the last cards into their own winning pile
                Card lastCards1 = player1.drawCardFromPlayingStack();
                Card lastCards2 = player2.drawCardFromPlayingStack();

                player1.addCardToWonVector(lastCards1);
                player2.addCardToWonVector(lastCards2);
            }

            // log ends with a draw.
            logstream << " cards finished, round was a draw.";
            this->gameLog.push_back(logstream.str());
            logstream.str("");
            logstream.clear();
            warEnded = true;
        }
    }
};

void Game::playAll()
{
    bool flag = true;
    while (flag)
    {
        if (player1.stacksize() == 0 || player2.stacksize() == 0)
        {
            flag = false;
        }
        else
        {
            playTurn();
        }
    }
};

void Game::printLastTurn() const
{
    // print last element in log vector
    cout << this->gameLog.back() << endl;
};
void Game::printLog() const
{
    // print log vector line by line
    for (const auto &log : this->gameLog)
    {
        cout << log << endl;
    }
};
void Game::printStats() const
{
    // printing stats for each player
    cout << player1.getName() << " won " << player1.getRoundsWon() << " out of "
         << this->roundCounter << " rounds" << endl;
    cout << player2.getName() << " won " << player2.getRoundsWon() << " out of "
         << this->roundCounter << " rounds" << endl;
    cout << "This game has had: " << this->drawCounter << " draws, which is: "
         << this->drawCounter << " rounds out of " << this->roundCounter << endl;
}

void Game::printWiner()
{

    if (player1.cardesTaken() > player2.cardesTaken())
    {
        cout << player1.getName() << ": is the winner!" << endl;
    }
    else if (player2.cardesTaken() > player1.cardesTaken())
    {
        cout << player2.getName() << ": is the winner!" << endl;
    }
    else
    {
        cout << "The game ended in a draw" << endl;
    }
};
