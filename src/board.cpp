#include "../include/board.hpp"

Board::Board(){
    fillBoard();
}

void Board::fillBoard(){
    for (int i = 0; i < BSIZE; i++){
        for (int j = 0; j < BSIZE; j++){
            board[i][j] = '*';
        }
    }
}

void Board::printBoard()const{
    std::cout << std::endl;
    for (int i = 0; i < BSIZE; i++){
        std::cout << " | ";
        for (int j = 0; j < BSIZE; j++){
            std::cout << board[i][j] << " | ";
        }

        std::cout << std::endl << std::endl;
    }
}