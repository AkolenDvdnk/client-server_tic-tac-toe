#ifndef tictactoe_hpp
#define tictactoe_hpp

#include <iostream>

#include "cell.hpp"

#define BSIZE 3

class TTT{
public:
    TTT();
    void printBoard()const;
    void printWinner()const;
    void makeMove();
    void initialize();
    
    bool gameOver();
    bool correctNumber(int);
    bool isMovesLeft();
    
    char getTurn();

private:
    static const int maxMoves = 9;
    int choice;
    int totalMoves = 0;
    
    Cell board[BSIZE][BSIZE];
    char turn = 'X';
    
    void fillBoard();
};

#endif