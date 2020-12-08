#include <iostream>
#include "Board.hpp"


int main() {
    Board* board = new Board();

    const char str[] = "random";
    board->init("random");

    while(true) {    
    board->print();
    board->update();
    }

    return 0;
}