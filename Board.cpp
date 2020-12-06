#include <iostream>
#include <stdio.h>
#include <string.h>
#include <random>

#include "Board.hpp"

void Board::initBoard(const char initType[]) {
    int val;
    if (!strcmp(initType, "random")) {

        for (int j = 0; j < length; j++){
            for (int i = 0; i < height; i++){
                val = rand() % 2;
                if (val == 1){
                    cellArray[i][j].state = ALIVE; 
                }else {
                    cellArray[i][j].state = DEAD;
                }
            }
        }
    }
}

void Board::printBoard() {
    for (int j = 0; j < length; j++){
        for (int i = 0; i < height; i++){
            if (cellArray[i][j].state == ALIVE) {
                std::cout << "*";
            } else {
                std::cout << "-";
            }
        }
        std::cout << "\n";
    }
}

