# War Game

This is a simple two-player card game called "War" that you can play in the command line/terminal. The objective of the game is to collect all the cards from your opponent.

## Game Rules

1. The game uses a standard deck of 52 playing cards.
2. The deck is shuffled and divided evenly between the two players, with each player receiving 26 cards.
3. Each player reveals the top card from their deck simultaneously, and the player with the higher-ranked card wins the round and collects both cards (One trick is that 2 beats Ace).
4. If the two revealed cards have the same rank, it's a "war" situation. Each player reveals one additional card faced down, and then reveals a a second card face up. The player with the higher-ranked second card wins the war and collects all the cards in the round.
5. The game continues until both players run out of cards.

## Classes

### Card

This class represents a standard playing card with a rank (e.g., 2, 3, 4, ..., Jack, Queen, King, Ace) and a suit (e.g., Hearts, Diamonds, Clubs, Spades). It has the following member variables:

- `value`: An integer representing the value/rank of the card.
- `symbol`: A character representing the suit of the card.
- `nameValueMap`: A map that maps the integer value of the card to its corresponding name (e.g., 2 to "Two", 3 to "Three", etc.).
- `symbolValueMap`: A map that maps the character symbol of the card to its corresponding value (e.g., 'H' to "Hearts", 'D' to "Diamonds", etc.).

The `Card` class also has the following member functions:

- `int getCardValue()`: Returns the value of the card.
- `char getType()`: Returns the symbol/suit of the card.
- `string to_string() const`: Returns a string representation of the card in a human-readable format.
- `string getCardName()`: Returns the name of the card (e.g., "Two of Hearts", "Queen of Diamonds", etc.).
- `Card(int, char)`: Constructor for the `Card` class that takes an integer value and a character symbol as parameters to initialize the card object.


### Player

This class represents a player in a card game. It has the following member variables:

- `name`: A string representing the name of the player.
- `playingStack_`: A stack of `Card` objects representing the playing stack of cards for the player.
- `wonPile_`: A vector of `Card` objects representing the won pile of cards for the player.
- `roundsWon`: An integer representing the number of rounds won by the player.

The `Player` class also has the following member functions:

- `Player(const string &playerName)`: Constructor for the `Player` class that takes a string `playerName` as a parameter to initialize the player object.
- `void addCardToPlayingStack(const Card &card)`: Adds a `Card` object to the playing stack of cards for the player.
- `void addCardToWonVector(const Card &card)`: Adds a `Card` object to the won pile of cards for the player.
- `Card drawCardFromPlayingStack()`: Draws a `Card` object from the playing stack of cards for the player.
- `Card drawCardFromWonPile()`: Draws a `Card` object from the won pile of cards for the player.
- `int stacksize()`: Returns the size of the playing stack of cards for the player.
- `int cardesTaken()`: Returns the total number of cards taken by the player (sum of playing stack size and won pile size).
- `string getName() const`: Returns the name of the player.
- `string to_string() const`: Returns a string representation of the player in a human-readable format.
- `int getRoundsWon()`: Returns the number of rounds won by the player.
- `void increaseRoundsWon()`: Increases the number of rounds won by the player by 1.
- `void setRoundsWon(int num)`: Sets the number of rounds won by the player to the given integer value.


### Game

This class represents a card game. It has the following member variables:

- `player1`: A reference to a `Player` object representing player 1 in the game.
- `player2`: A reference to a `Player` object representing player 2 in the game.
- `deck`: A vector of `Card` objects representing the deck of cards for the game.
- `gameLog`: A vector of strings representing the game log, storing the history of turns and outcomes.
- `roundCounter`: An integer representing the current round counter.
- `drawCounter`: An integer representing the number of draws in the current round.

The `Game` class also has the following member functions:

- `Game(Player &p01, Player &p02)`: Constructor for the `Game` class that takes references to `Player` objects `p01` and `p02` as parameters to initialize the game object.
- `void war(stringstream &logstream, Card card1, Card card2)`: Helper function to handle a war situation in the game. It takes a `stringstream` object `logstream` to update the game log, and two `Card` objects `card1` and `card2` representing the cards being compared.
- `void playTurn()`: Plays a turn of the game by drawing cards from the playing stacks of the two players, comparing the values, and updating the game log and player statistics accordingly.
- `void printLastTurn() const`: Prints the outcome of the last turn in the game log.
- `void printLog() const`: Prints the entire game log.
- `void printStats() const`: Prints the statistics of the two players, including the number of rounds won and the number of cards taken.
- `void printWinner()`: Prints the winner of the game based on the number of rounds won by the players.
- `void playAll()`: Plays the entire game until one of the players wins by accumulating all the cards.


## Dependencies

This game was developed using C++ and does not require any external libraries or modules to run.

## Acknowledgements

This game was created by Arieh Norton as a personal project. Feel free to use, modify, or distribute the game.

## Contributing

If you would like to contribute to the game, please submit a pull request with your proposed changes. All contributions are welcome!


