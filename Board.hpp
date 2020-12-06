#include <iostream>
#include <vector>

#define HEIGHT 10
#define LENGTH 10

enum CellState {
    DEAD = 0,
    ALIVE = 1,
};

struct Cell {
    enum CellState state{DEAD};
    int xPos;
    int yPos;
};


class Board {
private:
    Cell cellArray[HEIGHT][LENGTH];
    int height = HEIGHT;
    int length= LENGTH;

public:
    void initBoard(const char initType[]);
    void printBoard();
    void updateState();
    ~Board();
};