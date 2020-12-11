#include <iostream>
#include <stdio.h>
#include <string.h>
#include <random>
#include "stdlib.h"
#include "Board.hpp"

void Board::init(const char type[]) {
    int val;
    if (strcmp(type, "glider") == 0) {
        int rowCoord = 10;
        int colCoord = 10;
        cellArray[rowCoord][colCoord].state 	= ALIVE;//left square
		cellArray[rowCoord+1][colCoord].state 	= ALIVE;
		cellArray[rowCoord][colCoord+1].state	= ALIVE;
		cellArray[rowCoord+1][colCoord+1].state 	= ALIVE;
		cellArray[rowCoord][colCoord+10].state 		= ALIVE; //first glider
		cellArray[rowCoord+1][colCoord+10].state 		= ALIVE;
		cellArray[rowCoord+2][colCoord+10].state 		= ALIVE;
		cellArray[rowCoord-1][colCoord+11].state 		= ALIVE;
		cellArray[rowCoord+3][colCoord+11].state 		= ALIVE;
		cellArray[rowCoord-2][colCoord+12].state 		= ALIVE;
		cellArray[rowCoord+4][colCoord+12].state 		= ALIVE;
		cellArray[rowCoord-2][colCoord+13].state 		= ALIVE;
		cellArray[rowCoord+4][colCoord+13].state 		= ALIVE;
		cellArray[rowCoord+1][colCoord+14].state 		= ALIVE;
		cellArray[rowCoord-1][colCoord+15].state 		= ALIVE;
		cellArray[rowCoord+3][colCoord+15].state 		= ALIVE;
		cellArray[rowCoord][colCoord+16].state 		= ALIVE;
		cellArray[rowCoord+2][colCoord+16].state 		= ALIVE;
		cellArray[rowCoord+1][colCoord+16].state		= ALIVE;
		cellArray[rowCoord+1][colCoord+17].state 		= ALIVE;
		cellArray[rowCoord-2][colCoord+20].state 		= ALIVE; //second glider
		cellArray[rowCoord-1][colCoord+20].state 		= ALIVE;
		cellArray[rowCoord][colCoord+20].state 		= ALIVE;
		cellArray[rowCoord-2][colCoord+21].state 		= ALIVE;
		cellArray[rowCoord-1][colCoord+21].state 		= ALIVE;
		cellArray[rowCoord][colCoord+21].state 		= ALIVE;
		cellArray[rowCoord-3][colCoord+22].state 		= ALIVE;
		cellArray[rowCoord+1][colCoord+22].state 		= ALIVE;
		cellArray[rowCoord-4][colCoord+24].state 		= ALIVE;
		cellArray[rowCoord-3][colCoord+24].state 		= ALIVE;
		cellArray[rowCoord+1][colCoord+24].state	= ALIVE;
		cellArray[rowCoord+2][colCoord+24].state 		= ALIVE;
		cellArray[rowCoord-2][colCoord+34].state 		= ALIVE; //last square
		cellArray[rowCoord-1][colCoord+34].state 		= ALIVE;
		cellArray[rowCoord-2][colCoord+35].state 		= ALIVE;
		cellArray[rowCoord-1][colCoord+35].state 		= ALIVE;   
    }
}

void Board::print() {

    
    for (int j = 0; j < nrCols; j++){
        for (int i = 0; i < nrRows; i++){
            if (cellArray[i][j].state == ALIVE) {
                std::cout << "X";
            } else {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}

int Board::cellNrOfNeighs(int i, int j) {
    int nr = 0;
    if (i == 0 && j == 0) {
        nr = cellArray[i+1][j].state + cellArray[i][j+1].state + cellArray[i+1][j+1].state;
        std::cout << nr;
    } else if (i == 0 && j == (nrCols - 1)) {
        nr = cellArray[i-1][j].state + cellArray[i][j-1].state + cellArray[i+1][j-1].state;
    } else if (i == (nrRows - 1) && j == 0) {
        nr = cellArray[i-1][j].state + cellArray[i][j+1].state + cellArray[i-1][j+1].state;
    } else if (i == (nrRows - 1) && j == (nrCols - 1)) {
        nr = cellArray[i-1][j].state + cellArray[i][j-1].state + cellArray[i-1][j-1].state;
    } else if (i == 0) {
        nr = cellArray[i][j-1].state + cellArray[i][j+1].state + cellArray[i+1][j-1].state + cellArray[i+1][j].state + cellArray[i+1][j+1].state;
    } else if (i == (nrRows -  1) ) {
        nr = cellArray[i][j-1].state + cellArray[i][j+1].state + cellArray[i-1][j-1].state + cellArray[i-1][j].state + cellArray[i-1][j+1].state;
    } else if (j == 0) {
        nr = cellArray[i-1][j].state + cellArray[i+1][j].state + cellArray[i-1][j+1].state + cellArray[i][j+1].state + cellArray[i+1][j+1].state;
    } else if (j == (nrCols - 1)) {
        nr = cellArray[i-1][j].state + cellArray[i+1][j].state + cellArray[i-1][j-1].state + cellArray[i][j-1].state + cellArray[i+1][j-1].state;
    }
    else {
       nr = cellArray[i-1][j-1].state + cellArray[i][j-1].state + cellArray[i+1][j-1].state + cellArray[i-1][j].state + cellArray[i+1][j].state + cellArray[i-1][j+1].state + cellArray[i][j+1].state + cellArray[i+1][j+1].state;
    }

    return nr;
}

void Board::update() {
    int nr;
    // Compute the next state for each cell
    for(int i = 0; i < nrRows - 1; i++) {
        for(int j = 0; j < nrCols - 1; j++) {

            nr = cellNrOfNeighs(i, j);
            if (cellArray[i][j].state == DEAD && (nr == 3)) {
                cellArray[i][j].nextState = ALIVE;
            } else if (cellArray[i][j].state == ALIVE && (nr == 2 || nr == 3)) {
                cellArray[i][j].nextState = ALIVE;
            } else {
                cellArray[i][j].nextState = DEAD;
            }
        }
    }

    // Update the state
    for(int i = 0; i < nrRows - 1; i++) {
        for(int j = 0; j < nrCols - 1; j++) {
            cellArray[i][j].state = cellArray[i][j].nextState;
        }
    }

}