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

This class represents a standard playing card with a rank (e.g., 2, 3, 4, ..., Jack, Queen, King, Ace) and a suit (e.g., Hearts, Diamonds, Clubs, Spades). It has methods to get the rank and suit of the card, as well as a method to display the card in a human-readable format.

### Player

This class represents a player in the game. It has a name, a hand of cards (represented as a list of Card objects), and methods to add cards to the hand, play a card from the hand, and check if the player has any cards left in their hand.

### Game

This class represents the game itself. It has methods to start the game, play rounds, handle war situations, check for a winner, and display the game state.

## Dependencies

This game was developed using C++ and does not require any external libraries or modules to run.

## Acknowledgements

This game was created by [Your Name] as a personal project. Feel free to use, modify, or distribute the game according to the terms of the [license](LICENSE) provided.

## Contributing

If you would like to contribute to the game, please submit a pull request with your proposed changes. All contributions are welcome!

## Contact

If you have any questions, comments, or suggestions regarding the game, please feel free to contact [Your Email Address].
