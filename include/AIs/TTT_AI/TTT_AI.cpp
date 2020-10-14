//
// Created by Carlos Galo on 10/11/20.
//

#include "TTT_AI.h"

TTT_AI::TTT_AI(char maxP, char minP)
{
    this->maxP = maxP;
    this->minP = minP;
}

TTT_AI::~TTT_AI()
{
    this->maxP = 0x00;
    this->minP = 0x00;
}

int TTT_AI::evalBoard(Board *board) const
{

    // First lets see if there is a winner through all rows/horizontally
    for (int row = 0; row < board->getSize(); row++)
    {
        // If all the values/columns in this row are the same
        if (board->getValue(row, 0) == board->getValue(row, 1) &&
            board->getValue(row, 1) == board->getValue(row, 2))
        {
            // Check which player won
            if (board->getValue(row, 0) == maxP)                // If Player1 (X) is the winner
                return 10;
            else if (board->getValue(row, 0) == minP)           // Player2 (O) is the winner
                return -10;
        }
    }

    // We get here if no player has won horizontally, now we check vertically (through columns)
    for (int column = 0; column < board->getSize(); column++)
    {
        if (board->getValue(0, column) == board->getValue(1, column) &&
            board->getValue(1, column) == board->getValue(2, column))
        {
            if (board->getValue(0, column) == maxP)         // If Player1 (X) is the winner
                return 10;
            if (board->getValue(0, column) == minP)         // If Player2 (O) is the winner
                return -10;
        }
    }

    // We get here if they didn't win either horizontally or vertically, now we check diagonally
    if (board->getValue(0,0) == board->getValue(1,1) &&
        board->getValue(1,1) == board->getValue(2,2))
    {
        if (board->getValue(0,0) == maxP)                 // If Player1 (X) is the winner
            return 10;
        else if (board->getValue(0,0) == minP)            // If player2 (O) is the winner
            return -10;
    }

    if (board->getValue(0,2) == board->getValue(1,1) &&
        board->getValue(1,1) == board->getValue(2,0))
    {
        if (board->getValue(0, 2) == maxP)                // If Player1 (X) is the winner
            return 10;
        else if (board->getValue(0,2) == minP)            // If Player2 (O) is the winner
            return -10;
    }

    // Else there is no winner, this is a tie state
    return 0;
}

Move * TTT_AI::getBestMove(Board *board)
{
    Move** moves = board->getAvailableMoves();
    int totMoves = board->getSize() * board->getSize();
    int bestScore = INT_MIN;
    Move* bestMove = new Move();
    for (int i = 0; i  < totMoves; i++)
    {
        Move* move = moves[i];
        if (move != nullptr)
        {
            int row = move->getRow(), col = move->getColumn();
            board->setMove(row, col, maxP);
            int tempScore = MiniMax(board, 0, false);
            board->setMove(row, col, board->getEmptyChar());
            if (tempScore > bestScore)
            {
                bestScore = tempScore;
                bestMove->setRow(row);
                bestMove->setColumn(col);
            }

        }
        else
            continue;
    }
    return bestMove;
}

int TTT_AI::MiniMax(Board *board, int depth, bool isMax) const
{
    int score = evalBoard(board);
    // If the current state of the board is a terminal state
    // Then return value of the board
    if (score == 10)
        return score - depth;
    if (score == -10)
        return score + depth;
    if (board->isFull() && score == 0)
        return 0;

    if (isMax)
    {
        Move** moves = board->getAvailableMoves();
        int totMoves = board->getSize() * board->getSize();
        int maxScore = INT_MIN;
        for (int i = 0; i < totMoves; i++)
        {
            Move *move = moves[i];
            if (move != nullptr)
            {
                board->setMove(move, maxP);
                int score = MiniMax(board, depth+1, false);
                board->setMove(move, board->getEmptyChar());
                if (score > maxScore)
                    maxScore = score;
            }
        }
        return maxScore;
    }
    else
    {
        Move** moves = board->getAvailableMoves();
        int totMoves = board->getSize() * board->getSize();
        int minScore = INT_MAX;
        for (int i = 0; i < totMoves; i++)
        {
            Move* move = moves[i];
            if (move != nullptr)
            {
                board->setMove(move, minP);
                int score = MiniMax(board, depth + 1, true);
                board->setMove(move, board->getEmptyChar());

                if (score < minScore)
                    minScore = score;
            }
        }
        return minScore;
    }


}