#include <iostream>
#include "Board.hpp"


int main() {
    Board* board = new Board();

    const char str[] = "random";
    board->initBoard("random");
    board->printBoard();

    return 0;
}