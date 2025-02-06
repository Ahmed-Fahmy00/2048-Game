#include "include/game2048.h"
#include <conio.h>
#include <algorithm>

Game2048::Game2048() {
    currentState = GameState::MAIN_MENU;
}

void Game2048::startGame() {
    board.startNewGame();
    currentState = GameState::PLAYING;
}
void Game2048::updateGame() {
    if (board.isGameOver()) {
        currentState = GameState::GAME_OVER;
    }
}
void Game2048::renderGame() const {
    system("cls");
    board.printBoard();
}

void Game2048::processInput(char input) {
    if (currentState != GameState::PLAYING) return;

    switch (input) {
        case 'w': case 'W': board.moveUp(); break;
        case 's': case 'S': board.moveDown(); break;
        case 'a': case 'A': board.moveLeft(); break;
        case 'd': case 'D': board.moveRight(); break;
        case 27: currentState = GameState::PAUSED; break;
    }
}

bool Game2048::isGameOver() const {
    return board.isGameOver();
}
int Game2048::getScore() const {
    return board.getScore();
}

void Game2048::addScore(const std::string& name, int score) {
    scores.push_back({name, score});
    sort(scores.begin(), scores.end(), [](const PlayerScore& a, const PlayerScore& b) {
        return a.score > b.score;
    });
    if (scores.size() > 10) scores.pop_back(); // Keep top 10 scores
}
void Game2048::displayScores() const {
    cout << "=== Leaderboard ===\n";
    for (size_t i = 0; i < scores.size(); ++i) {
        cout << i + 1 << ". " << scores[i].playerName << " - " << scores[i].score << "\n";
    }
}