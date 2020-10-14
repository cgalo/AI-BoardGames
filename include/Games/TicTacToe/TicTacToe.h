/**
 * @author: Carlos Galo
 * Created: 10/9/2020
 * Last Updated: 10/10/2020
 */

#ifndef AI_BOARDGAMES_TICTACTOE_H
#define AI_BOARDGAMES_TICTACTOE_H

#include "../../AIs/TTT_AI/TTT_AI.h"    // Import the AI to evaluate the board and provided the best move
#include "../../AIs/AI.h"

class TicTacToe {
private:
    // Set the values for player1, player2, and what is considered as an empty space in the board
    const char p1 =  'X', p2 = '0', empty = ' ';
    Board * mainBoard;                  // 3x3 board


    // Methods
    bool isGameDone(int score);         // Evaluates if the game is done by either a tie or a winner

public:
    TicTacToe();                        // Constructor
    ~TicTacToe();                       // Destructor

    // Methods
    void start();                       // Driver method that initiates

};


#endif //AI_BOARDGAMES_TICTACTOE_H
