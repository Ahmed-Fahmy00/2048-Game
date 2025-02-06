
#include <iostream>
#include <conio.h>
#include "src/include/game2048.h"
using namespace std;

void displayMenu() {

    cout << "\n===== 2048 Game =====\n";
    cout << "1. Start Game\n";
    cout << "2. View Leaderboard\n";
    cout << "3. Quit\n";
    cout << "Enter your choice: ";
}

int main() {
    Game2048 game;
    char choice;

    while (true) {
        displayMenu();
         choice= _getch();

        if (choice == '1') {
            game.startGame();

            char input;
            while (true) {
                game.renderGame();
                cout << "Move (WASD) or (ESC)ause: ";
                input= _getch();

                if (input == 27) {
                    cout << "Game Paused. Press (ESC) to Continue or (M) to Main Menu: ";
                    input= _getch();
                    if (input == 'm' || input == 'M') break;
                } else {
                    game.processInput(input);
                    game.updateGame();
                    if (game.isGameOver()) {
                        system("cls");
                        cout << "Game Over! Enter your name: ";
                        string name;
                        cin >> name;
                        game.addScore(name, game.getScore());
                        break;
                    }
                }
            }
        } else if (choice == '2') {
            game.displayScores();
        } else if (choice == 27) {
            cout << "Thanks for playing!\n";
            break;
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}
