#include <iostream>
#include <vector>

#define NR_ROWS 60
#define NR_COLS 60

enum State {
    DEAD = 0,
    ALIVE = 1,
};

struct Cell {
    enum State state;
    enum State nextState;
};


class Board {
private:
    Cell cellArray[NR_ROWS][NR_COLS];
    int nrRows = NR_ROWS;
    int nrCols = NR_COLS;
    int cellNrOfNeighs(int row, int col);

public:
    void init(const char type[]);
    void print();
    void update();
    ~Board();
};