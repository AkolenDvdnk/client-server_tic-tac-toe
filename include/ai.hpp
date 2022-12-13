#include "tictactoe.hpp"
#include "cell.hpp"

#define pAI 'O'
#define pPlayer 'X'

struct Move{
    int row, col;
};

class AI{
public:
    int minimax(Cell board[BSIZE][BSIZE], int depth, bool isMax);

    bool isMovesLeft(Cell board[3][3]);
    int evaluate(Cell b[3][3]);
    
    Move findBestMove(Cell board[BSIZE][BSIZE]);
};