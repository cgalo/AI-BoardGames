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
     * @return true if the score is either -1 or 1, or if the score is 0 and the board has no empty spaces
     * @return false if the score is 0 and the board is not empty
     */

    if (score == 1 || score == -1 || (score == 0 && mainBoard->isEmpty()))
        return true;
    else return false;
}

void TicTacToe::start()
{
    /**
     * This is the driver method for the Tic tac toe game.
     */

    int boardScore = 0;                         // We start with an empty board, with a score of 0
    TTT_AI * AI = new TTT_AI(p1, p2);           // Initiate the AI, letting it know p1 is max & p2 is min

    while (!isGameDone(boardScore))
    {
        boardScore=  AI->evalBoard(mainBoard);  // Let the AI check the state of the board
    }
    // We evaluate who is the winner and output a message of the end state of the game
    if (boardScore == 0)
        std::cout << "Looks like the game ended in a tie, good game!" << std::endl;
    else if (boardScore == 1)
        std::cout << "\n\tX is the winner, congratulations!" << std::endl;
    else
        std::cout << "\n\tO is the winner, congratulations!" << std::endl;


}