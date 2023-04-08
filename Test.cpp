// #include "doctest.h"
// #include "sources/player.hpp"
// #include "sources/card.hpp"
// #include "sources/game.hpp"

// #include <iostream>
// #include <vector>
// #include <algorithm>

// #include <stdio.h>
// #include <unistd.h>

// using namespace std;
// using namespace ariel;

// // first check that the basics work such as creating a player checking his name and that he has no cards.
// TEST_CASE("Basics")
// {
//     CHECK_NOTHROW(Player p1("Arieh"));
//     Player temp("Ploni");
//     CHECK_EQ(temp.getName(), "Ploni");
//     CHECK_EQ(temp.getCards(), 0);
// }

// // testing the begining of a game
// TEST_CASE("Init game checks")
// {
//     Player p1("Arieh");
//     Player p2("Sivan");
//     // test that the game actually started.
//     CHECK_NOTHROW(Game game(p1, p2));
//     Game game(p1, p2);

//     // testing the void functions
//     CHECK_NOTHROW(game.printWiner());
//     CHECK_NOTHROW(game.printLastTurn());
//     CHECK_NOTHROW(game.printLog());
//     CHECK_NOTHROW(game.playAll());
//     CHECK_NOTHROW(game.playTurn());
//     CHECK_NOTHROW(game.printStats());
//     // check game againts your self doesn't work
//     Player p3("Almoni");
//     CHECK_THROWS(Game(p3, p3));
// }

// // testing cards
// TEST_CASE("Cards test")
// {
//     // first checkin that the card is created without a problem
//     CHECK_NOTHROW(Card card("Ace", "Heart", 1));

//     // testing prints and value of card

//     Card test1("Two", "Spade", 2);
//     Card test2("King", "Hearts", 13);

//     // testing to string
//     CHECK_EQ(test1.to_string(), "Two of Spade");

//     // testing value
//     CHECK_EQ(test2.getValue(), 13);

//     // testing type
//     CHECK_EQ(test2.getType(), "Hearts");
//     CHECK_EQ(test1.getType(), "Spade");
// }

// TEST_CASE("One game at a time")
// {
//     Player p1("Arieh");
//     Player p2("Sivan");
//     Player p3("David");
//     CHECK_NOTHROW(Game(p1, p2));
//     Game game(p1, p2);
//     CHECK_THROWS(Game(p1, p3));
//     CHECK_THROWS(Game(p2, p3));
// }

// TEST_CASE("Check beggining and end")
// {
//     Player p1("Arieh");
//     Player p2("Sivan");

//     Game game(p1, p2);
//     CHECK_EQ(p1.stacksize(), p2.stacksize());
//     game.playAll();
//     CHECK(p1.cardesTaken() + p2.cardesTaken() == 52);
// }
