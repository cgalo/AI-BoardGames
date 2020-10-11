//
// Created by Carlos Galo on 10/9/20.
//

#include "TicTacToe.h"

TicTacToe::TicTacToe()
{
    /**
     * Main method for the tic tac toe/
     * Create an empty 3x3 board to play
     */

    this->mainBoard = new Board(3);     // Create the 3x3 matrix
}

TicTacToe::~TicTacToe()
{
    /**
     * Destructor of the game, perform garbage collection.
     */

    delete mainBoard;                           // Delete the board
}

bool TicTacToe::isGameDone(int score)
{
    /**
     * Method evaluate the current state of the board to determine if the game is over
     *
     * @param score is given by the evaluationBoard method, which determines the score of the board
     * @return true if the score is either -1 or 1, or if the score is 0 and the board has no empty moves
     * @return false if the score is 0 and the board is not empty
     */

    if (score == 1 || score == -1 || (score == 0 && mainBoard->isEmpty()))
        return true;
    else return false;
}

int TicTacToe::evaluateBoard(Board *board)
{

    // First lets see if there is a winner through all rows/horizontally
    for (int row = 0; row < board->getSize(); row++)
    {
        // If all the values/columns in this row are the same
        if (board->getValue(row, 0) == board->getValue(row, 1) &&
            board->getValue(row, 1) == board->getValue(row, 2))
        {
            // Check which player won
            if (board->getValue(row, 0) == p1)                  // If Player1 (X) is the winner
                return +1;
            else if (board->getValue(row, 0) == p2)             // Player2 (O) is the winner
                return -1;
        }
    }

    // We get here if no player has won horizontally, now we check vertically (through columns)
    for (int column = 0; column < board->getSize(); column++)
    {
        if (board->getValue(0, column) == board->getValue(1, column) &&
            board->getValue(1, column) == board->getValue(2, column))
        {
            if (board->getValue(0, column) == p1)           // If Player1 (X) is the winner
                return 1;
            else if (board->getValue(0, column == p2))  // If Player2 (O) is the winner
                return -1;
        }
    }

    // We get here if they didn't win either horizontally or vertically, now we check diagonally
    if (board->getValue(0,0) == board->getValue(1,1) &&
        board->getValue(1,1) == board->getValue(2,2))
    {
        if (board->getValue(0,0) == p1)                 // If Player1 (X) is the winner
            return 1;
        else if (board->getValue(0,0) == p2)            // If player2 (O) is the winner
            return -1;
    }

    if (board->getValue(0,2) == board->getValue(1,1) &&
        board->getValue(1,1) == board->getValue(2,0))
    {
        if (board->getValue(0, 2) == p1)                // If Player1 (X) is the winner
            return 1;
        else if (board->getValue(0,2) == p2)            // If Player2 (O) is the winner
            return -1;
    }

    // Else there is no winner, this is a tie state
    return 0;
}

void TicTacToe::start()
{
    /**
     * This is the driver method for the Tic tac toe game.
     */

    int boardScore = 0;             // We start with an empty board, with a score of 0
    


    // We evaluate who is the winner and output a message of the end state of the game
    if (boardScore == 0)
        std::cout << "Looks like the game ended in a tie, nice game!" << std::endl;
    else if (boardScore == 1)
        std::cout << "X is the winner, congratulations!" << std::endl;
    else
        std::cout << "O is the winner, congratulations!" << std::endl;


}