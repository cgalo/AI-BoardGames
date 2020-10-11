/**
 * @author: Carlos Galo
 * Created: 10/9/2020
 * Last Updated: 10/10/2020
 */

#ifndef AI_BOARDGAMES_TICTACTOE_H
#define AI_BOARDGAMES_TICTACTOE_H

#include "../../Board/Board.h"          // Import the Board
class TicTacToe {
private:
    // Set the values for player1, player2, and what is considered as an empty space in the board
    const char p1 =  'X', p2 = '0', empty = ' ';
    Board * mainBoard;                  // 3x3 board


    // Methods
    int evaluateBoard(Board* board);    // Evaluate the given board and determines if there is a winner or a tie
    bool isGameDone(int score);         // Evaluates if the game is done by either a tie or a winner

public:
    TicTacToe();                        // Constructor
    ~TicTacToe();                       // Destructor

    // Methods
    void start();                       // Driver method that initiates

};


#endif //AI_BOARDGAMES_TICTACTOE_H
