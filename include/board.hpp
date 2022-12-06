#ifndef board_hpp
#define board_hpp

#include <iostream>

class Board{
public:
    Board();
    void printBoard()const;

private:
    static const int BSIZE = 3;
    char board[BSIZE][BSIZE];

    void fillBoard();
};

#endif