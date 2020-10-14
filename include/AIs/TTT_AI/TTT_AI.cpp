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
            int tempScore = MiniMax(board, 0, false, INT_MIN, INT_MAX);
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

int TTT_AI::MiniMax(Board *board, int depth, bool isMax, int alpha, int beta) const
{
    int score = evalBoard(board);                                       // Evaluate the current state of the board
    /* If the current state of the board is a terminal state
     Then return value of the board*/
    if (score == 10)                                                    // If this is a terminal state where max is winner
        return score - depth;                                           // We return the score minus the depth
    if (score == -10)                                                   // If this is a terminal state where min is winner
        return score + depth;                                           // Return score plus depth
    if (board->isFull() && score == 0)                                  // If this is a terminal state with a tie
        return score;                                                   // Return score, which is 0

    Move** moves = board->getAvailableMoves();                          // Get the available moves/spaces for the current state
    int totMoves = board->getSize() * board->getSize();                 // Max possible moves in tic tac toe is 3*3

    if (isMax)                                                          // If we are maximizing
    {
        int maxScore = INT_MIN;                                         // Value will be used to keep track of the max score
        for (int i = 0; i < totMoves; i++)
        {
            Move* move = moves[i];                                      // Get the move from the current index of moves
            if (move != nullptr)                                        // If the move is not null
            {                                                           // Then we evaluate the state for with the move
                board->setMove(move, maxP);                             // Perform the move in the board
                int score = MiniMax(board, depth+1, false, alpha, beta);    // Evaluate the state for this board, next state we minimize
                board->setMove(move, board->getEmptyChar());            // Revert the done
                maxScore = (score > maxScore) ? score : maxScore;       // If maxScore is less than score, make score the new maxScore
                alpha = (maxScore > alpha) ? maxScore : alpha;          // If alpha is less than maxScore, make maxScore the new alpha
                // Perform alpha-beta pruning
                if (beta <= alpha)                                      // If beta es less than or equal than alpha
                    break;                                              // We break, we stop evaluating
            }
        }
        return maxScore;                                                // Return the max score found
    }
    else                                                                // Else we are minimizing 
    {
        int minScore = INT_MAX;                                         // Keep track of the lowest/min score
        for (int i = 0; i < totMoves; i++)
        {
            Move* move = moves[i];                                      // Get the move from the current index of moves
            if (move != nullptr)                                        // If the move is not null
            {                                                           // Then we evaluate the state for with the move
                board->setMove(move, minP);                             // Make the move to evaluate the possible new state
                int score = MiniMax(board, depth + 1, true, alpha, beta);   // Evaluate the state for this board, next move we maximize
                board->setMove(move, board->getEmptyChar());            // Revert the done
                minScore = (score < minScore) ? score : minScore;       // If the score is less than minScore, make the score the new minScore
                beta = (minScore < beta) ? minScore : beta;             // If minScore is less than beta, make minScore the new beta
                // Perform alpha-beta pruning
                if (beta <= alpha)                                      // If beta es less than or equal than alpha
                    break;                                              // We break, we stop evaluating
            }
        }
        return minScore;                                                // Return the lowest score found
    }
}