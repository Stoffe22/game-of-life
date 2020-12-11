#include <iostream>
#include <string>
#include "Board.hpp"


int main() {
    std::string userInput = "";
    int iters;
    std::cout << "1. Press p to play GameOfLife" << std::endl;
    std::cout << "2. Press q to quit" << std::endl;
    std::cin >> userInput;
    
    if (!userInput.compare("q")){
        return 0;
    } else if (!userInput.compare("p")) {
        std::cout << "How many iterations do you want to play?" << std::endl;
        std::cin >> iters;
    } else {
        std::cout << "You have entered a non-valid value!";
        return 0;
    } 

    Board* board = new Board();
    const char str[] = "glider";
    board->init("glider");

    for (int i = 0; i < iters; i++) {
        board->print();
        board->update();
    }
    
    return 0;
}