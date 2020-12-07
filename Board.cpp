#include <iostream>
#include <stdio.h>
#include <string.h>
#include <random>

#include "Board.hpp"

void Board::init(const char type[]) {
    int val;
    if (strcmp(type, "random") == 0) {

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

void Board::print() {
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

int Board::cellNrOfNeighs(int i, int j) {
    int nr;
    if (i == 0 && j == 0) {
        nr = cellArray[i+1][j].state + cellArray[i][j+1].state + cellArray[i+1][j+1].state;
    } else if (i == 0 && j == (length - 1)) {
        
    } else if (i == (height - 1) && j == 0) {

    } else if (i == (height - 1) && j == (length - 1)) {

    } else if (i == 0) {

    } else if (i == (height -1) ) {

    } else if (j == 0) {

    } else if (j == (length - 1)) {

    }
    return nr;
}

void Board::update() {


}
