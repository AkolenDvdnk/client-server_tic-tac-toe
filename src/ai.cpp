#include <algorithm>

#include "../include/ai.hpp"

bool AI::isMovesLeft(Cell board[3][3])
{
    for (int i = 0; i<3; i++)
        for (int j = 0; j<3; j++)
            if (board[i][j].getMark() == ' ')
                return true;
    return false;
}
 
int AI::evaluate(Cell b[3][3])
{
    for (int row = 0; row<3; row++)
    {
        if (b[row][0].getMark()==b[row][1].getMark() &&
            b[row][1].getMark()==b[row][2].getMark())
        {
            if (b[row][0].getMark()==pAI)
                return +10;
            else if (b[row][0].getMark()==pPlayer)
                return -10;
        }
    }
 
    for (int col = 0; col<3; col++)
    {
        if (b[0][col].getMark()==b[1][col].getMark() &&
            b[1][col].getMark()==b[2][col].getMark())
        {
            if (b[0][col].getMark()==pAI)
                return +10;
 
            else if (b[0][col].getMark()==pPlayer)
                return -10;
        }
    }
 
    if (b[0][0].getMark()==b[1][1].getMark() && b[1][1].getMark()==b[2][2].getMark())
    {
        if (b[0][0].getMark()==pAI)
            return +10;
        else if (b[0][0].getMark()==pPlayer)
            return -10;
    }
 
    if (b[0][2].getMark()==b[1][1].getMark() && b[1][1].getMark()==b[2][0].getMark())
    {
        if (b[0][2].getMark()==pAI)
            return +10;
        else if (b[0][2].getMark()==pPlayer)
            return -10;
    }

    return 0;
}

int AI::minimax(Cell board[BSIZE][BSIZE], int depth, bool isMax){
    int score = evaluate(board);

    if (score == 10)
        return score;

    if (score == -10)
        return score;

    if (isMovesLeft(board) == false)
        return 0;

    if (isMax){
        int best = -1000;

        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                if (board[i][j].getMark() == ' '){
                    board[i][j].setMark(pAI);

                    best = std::max(best, minimax(board, depth + 1, !isMax));

                    board[i][j].setMark(' ');
                }
            }
        }
        return best;
    } else {
        int best = 1000;

        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                if (board[i][j].getMark() == ' '){
                    board[i][j].setMark(pPlayer);

                    best = std::min(best, minimax(board, depth + 1, !isMax));

                    board[i][j].setMark(' ');
                }
            }
        }
        return best;
    }
}

Move AI::findBestMove(Cell board[BSIZE][BSIZE]){
    int bestVal = -1000;
    Move bestMove;
    bestMove.row = -1;
    bestMove.col = -1;

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (board[i][j].getMark() == ' '){
                board[i][j].setMark(pAI);

                int moveVal = minimax(board, 0, false);

                board[i][j].setMark(' ');

                if (moveVal > bestVal){
                    bestMove.row = i;
                    bestMove.col = j;
                    bestVal = moveVal;
                }
            }
        }
    }

    //std::cout << "The value of the best move is: " << bestVal << pAI << std::endl;

    return bestMove;
}
