#include <iostream>
#include <vector>

enum CellState {
    DEAD = 0,
    ALIVE = 1,
};

// Use a struct for Cell instead!!!!!!!!!!!!
struct Cell {
    enum CellState state{DEAD};
    int xPos;
    int yPos;
};


class Board {
private:
    constexpr static uint32_t length{100};
    constexpr static uint32_t width{100};

    Cell cellArray[length][width];

public:
    Board();
    void initializeBoard(const char initType[]);
    void printBoard();
    void updateState();
    ~Board();
};