#ifndef tictactoe_hpp
#define tictactoe_hpp

#include <iostream>

#define BSIZE 3

#include "cell.hpp"
#include "ai.hpp"

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
    bool makeMoveAI(Move);
    
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