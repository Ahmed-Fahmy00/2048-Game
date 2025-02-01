2048 Console Game (C++)

Features

Console-based gameplay: Classic 2048 game playable in the terminal.

Dynamic board sizes: Supports different board sizes (default is 4x4).

Game state saving: Save and continue previous games.

Leaderboard: Tracks highest scores across multiple players.

Pause and resume: Ability to pause and resume gameplay.

Random tile generation: New tiles appear after every move.

Game over detection: Automatically detects when no moves are left.

Game Controls

Arrow Keys: Move tiles in the respective direction.

P: Pause the game.

C: Continue a previously saved game.

Q: Quit the game.

Dependencies

Windows OS: Required due to Windows-specific headers (<windows.h>, <conio.h>).

C++ Compiler: MinGW or MSVC for compilation.

Compilation

Compile the game using a C++ compiler:

g++ -o 2048_game main.cpp -std=c++11

Usage

Run the game executable:

./2048_game

Code Structure

Game State Management: Handles saving and resuming gameplay.

Player Data: Stores player names and scores.

Core Game Functions: Manages game logic, tile movement, and interactions.

Sliding Mechanics: Implements movement logic for merging tiles.

Future Improvements

Cross-platform support: Remove Windows-specific dependencies.

AI integration: Implement AI to play the game automatically.

Graphical interface: Develop a GUI version using Qt or SFML.
