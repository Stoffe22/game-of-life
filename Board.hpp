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
};


class Board {
private:
    Cell cellArray[HEIGHT][LENGTH];
    int height = HEIGHT;
    int length = LENGTH;
    int cellNrOfNeighs(int iIndex, int jIndex);

public:
    void init(const char type[]);
    void print();
    void update();
    ~Board();
};