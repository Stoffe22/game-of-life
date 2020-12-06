#include <iostream>
#include <stdio.h>
#include "Board.hpp"
#include <random>





void Board::initializeBoard(const char initType[]) {
    int val;
    if (strcmp(initType, "random")) {

        for (int i = 0; i < length; i++){
            for (int j = 0; j < width; j++){
                val = rand() % 2;
                if (val == 1){
                    cellArray[i][j].state = ALIVE; 
                }else {
                    
                }
            }
        }
    }
}

void Board::printBoard() {
    
}

