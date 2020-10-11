/**
 * @author: Carlos Galo
 * @date: 10/11/2020
 *
 * Testing class for the TicTacToe class, utilizes BoardTest to implement pre-made boards
 */

#ifndef AI_BOARDGAMES_TICTACTOETEST_H
#define AI_BOARDGAMES_TICTACTOETEST_H

#include "BoardTest.h"

class TicTacToeTest : public BoardTest {
private:
    bool testEvalBoard();                   // Test the evaluateBoard method
    bool testIsGameDone();                  // Test the isGameDone method
public:
    bool test();                            // Driver test method
};

#endif //AI_BOARDGAMES_TICTACTOETEST_H
