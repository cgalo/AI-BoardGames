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
                return +1;
            else if (board->getValue(row, 0) == minP)           // Player2 (O) is the winner
                return -1;
        }
    }

    // We get here if no player has won horizontally, now we check vertically (through columns)
    for (int column = 0; column < board->getSize(); column++)
    {
        if (board->getValue(0, column) == board->getValue(1, column) &&
            board->getValue(1, column) == board->getValue(2, column))
        {
            if (board->getValue(0, column) == maxP)           // If Player1 (X) is the winner
                return 1;
            else if (board->getValue(0, column == minP))  // If Player2 (O) is the winner
                return -1;
        }
    }

    // We get here if they didn't win either horizontally or vertically, now we check diagonally
    if (board->getValue(0,0) == board->getValue(1,1) &&
        board->getValue(1,1) == board->getValue(2,2))
    {
        if (board->getValue(0,0) == maxP)                 // If Player1 (X) is the winner
            return 1;
        else if (board->getValue(0,0) == minP)            // If player2 (O) is the winner
            return -1;
    }

    if (board->getValue(0,2) == board->getValue(1,1) &&
        board->getValue(1,1) == board->getValue(2,0))
    {
        if (board->getValue(0, 2) == maxP)                // If Player1 (X) is the winner
            return 1;
        else if (board->getValue(0,2) == minP)            // If Player2 (O) is the winner
            return -1;
    }

    // Else there is no winner, this is a tie state
    return 0;
}

Move * TTT_AI::getBestMove(Board *board)
{
    return nullptr;
}

int TTT_AI::MiniMax(Board *board, int depth, bool isMax) const
{
    return 0;
}