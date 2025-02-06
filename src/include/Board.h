#ifndef BOARD_H
#define BOARD_H

class Board {
public:
    class Tile {
    public:
        int value;
        int x, y;
    };

    Board();
    ~Board();

    void startNewGame();
    bool isGameOver() const;

    int getScore() const;

    void printBoard() const;

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

private:
    int size = 4 ;
    int grid[16][16];
    int score;

    void spawnTile();

    void mergeUp();
    void mergeDown();
    void mergeLeft();
    void mergeRight();
};

#endif // BOARD_H
