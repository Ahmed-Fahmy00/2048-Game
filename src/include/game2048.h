#ifndef GAME2048_H
#define GAME2048_H

using namespace std;
#include <iostream>
#include <vector>
#include "board.h"

enum class GameState {
    MAIN_MENU,
    PLAYING,
    PAUSED,
    GAME_OVER
};

class Game2048 {
public:
    Game2048();

    void startGame();
    void updateGame();
    void renderGame() const;

    void processInput(char input);
    bool isGameOver() const;
    int getScore() const;

    void addScore(const string& name, int score);
    void displayScores() const;

private:
    Board board;
    GameState currentState;

    struct PlayerScore {
        string playerName;
        int score;
    };

    vector<PlayerScore> scores;
};

#endif // GAME2048_H