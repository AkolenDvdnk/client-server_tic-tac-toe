#ifndef tictactoe_hpp
#define tictactoe_hpp

#include <iostream>

#include "cell.hpp"

class TTT{
public:
    TTT();
    void printBoard()const;
    void makeMove();
    bool gameOver();
    void initialize();

private:
    static const int BSIZE = 3;
    static const int maxMoves = 8;
    int choice;
    int totalMoves;
    
    Cell board[BSIZE][BSIZE];
    char turn = 'X';
    
    void fillBoard();
};

#endif