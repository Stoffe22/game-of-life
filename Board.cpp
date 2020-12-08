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
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }
    std::cout << "break\n";
}

int Board::cellNrOfNeighs(int i, int j) {
    int nr;
    if (i == 0 && j == 0) {
        nr = cellArray[i+1][j].state + cellArray[i][j+1].state + cellArray[i+1][j+1].state;
    } else if (i == 0 && j == (length - 1)) {
        nr = cellArray[i-1][j].state + cellArray[i][j-1].state + cellArray[i+1][j-1].state;
    } else if (i == (height - 1) && j == 0) {
        nr = cellArray[i-1][j].state + cellArray[i][j+1].state + cellArray[i-1][j+1].state;
    } else if (i == (height - 1) && j == (length - 1)) {
        nr = cellArray[i-1][j].state + cellArray[i][j-1].state + cellArray[i-1][j-1].state;
    } else if (i == 0) {
        nr = cellArray[i][j-1].state + cellArray[i][j+1].state + cellArray[i+1][j-1].state + cellArray[i+1][j].state + cellArray[i+1][j+1].state;
    } else if (i == (height -  1) ) {
        nr = cellArray[i][j-1].state + cellArray[i][j+1].state + cellArray[i-1][j-1].state + cellArray[i-1][j].state + cellArray[i-1][j+1].state;
    } else if (j == 0) {
        nr = cellArray[i-1][j].state + cellArray[i+1][j].state + cellArray[i-1][j+1].state + cellArray[i][j+1].state + cellArray[i+1][j+1].state;
    } else if (j == (length - 1)) {
        nr = cellArray[i-1][j].state + cellArray[i+1][j].state + cellArray[i-1][j-1].state + cellArray[i][j-1].state + cellArray[i+1][j-1].state;
    }
    return nr;
}

void Board::update() {
    int nr;
    for(int i = 0; i < height - 1; i++) {
        for(int j = 0; j < length -1; j++) {
            nr = cellNrOfNeighs(i, j);


            // Doesn't work!! Can't uppdate to next state before every current state has been checked
            if (cellArray[i][j].state == DEAD && (nr == 3)) {
                cellArray[i][j].state == ALIVE;
            } else if (cellArray[i][j].state == ALIVE && (nr == 2 || nr == 3)) {
                continue;
            } else {
                cellArray[i][j].state == DEAD;
            }
        }
    }
}