#include "include/board.h"
#include <iostream>
#include <vector>
#include <cstdlib>  // For random number generation
#include <ctime>    // For seeding random numbers

Board::Board() {
    srand(time(0));
    startNewGame();
}
Board::~Board(){};

void Board::startNewGame() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            grid[i][j] = 0; // Set all tiles to 0 (empty)
        }
    }
    spawnTile();
    spawnTile();
    score = 0;
}
bool Board::isGameOver() const {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (grid[i][j] == 0) return false;
            if (i < size - 1 && grid[i][j] == grid[i + 1][j]) return false;
            if (j < size - 1 && grid[i][j] == grid[i][j + 1]) return false;
        }
    }
    return true;
}

void Board::spawnTile() {
    std::vector<std::pair<int, int>> emptyTiles;

    // Find all empty tiles
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (grid[i][j] == 0) {
                emptyTiles.push_back({i, j});
            }
        }
    }

    // If there are empty spaces, place a new tile
    if (!emptyTiles.empty()) {
        int randIndex = rand() % emptyTiles.size();
        int x = emptyTiles[randIndex].first;
        int y = emptyTiles[randIndex].second;
        grid[x][y] = (rand() % 10 < 9) ? 2 : 4; // 90% chance of spawning 2, 10% for 4
    }
}

void Board::printBoard() const {

    std::cout << "Score: " << score << "\n";
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << (grid[i][j] ? std::to_string(grid[i][j]) : ".") << "\t";
        }
        std::cout << "\n";
    }
    std::cout << "--------------------------\n";
}

int Board::getScore() const {
    return score;
}

void Board::moveUp() {
    mergeUp();
    spawnTile();
}
void Board::moveDown() {
    mergeDown();
    spawnTile();
}
void Board::moveLeft() {
    mergeLeft();
    spawnTile();
}
void Board::moveRight() {
    mergeRight();
    spawnTile();
}

void Board::mergeUp() {
    for (int col = 0; col < size; col++) {
        for (int row = 1; row < size; row++) {
            if (grid[row][col] != 0) {
                int r = row;
                while (r > 0 && grid[r - 1][col] == 0) {
                    grid[r - 1][col] = grid[r][col];
                    grid[r][col] = 0;
                    r--;
                }
                if (r > 0 && grid[r - 1][col] == grid[r][col]) {
                    grid[r - 1][col] *= 2;
                    grid[r][col] = 0;
                    score += grid[r - 1][col];
                }
            }
        }
    }
}
void Board::mergeDown() {
    for (int col = 0; col < size; col++) {
        for (int row = size - 2; row >= 0; row--) {
            if (grid[row][col] != 0) {
                int r = row;
                while (r < size - 1 && grid[r + 1][col] == 0) {
                    grid[r + 1][col] = grid[r][col];
                    grid[r][col] = 0;
                    r++;
                }
                if (r < size - 1 && grid[r + 1][col] == grid[r][col]) {
                    grid[r + 1][col] *= 2;
                    grid[r][col] = 0;
                    score += grid[r + 1][col];
                }
            }
        }
    }
}
void Board::mergeLeft() {
    for (int row = 0; row < size; row++) {
        for (int col = 1; col < size; col++) {
            if (grid[row][col] != 0) {
                int c = col;
                while (c > 0 && grid[row][c - 1] == 0) {
                    grid[row][c - 1] = grid[row][c];
                    grid[row][c] = 0;
                    c--;
                }
                if (c > 0 && grid[row][c - 1] == grid[row][c]) {
                    grid[row][c - 1] *= 2;
                    grid[row][c] = 0;
                    score += grid[row][c - 1];
                }
            }
        }
    }
}
void Board::mergeRight() {
    for (int row = 0; row < size; row++) {
        for (int col = size - 2; col >= 0; col--) {
            if (grid[row][col] != 0) {
                int c = col;
                while (c < size - 1 && grid[row][c + 1] == 0) {
                    grid[row][c + 1] = grid[row][c];
                    grid[row][c] = 0;
                    c++;
                }
                if (c < size - 1 && grid[row][c + 1] == grid[row][c]) {
                    grid[row][c + 1] *= 2;
                    grid[row][c] = 0;
                    score += grid[row][c + 1];
                }
            }
        }
    }
}

