//
// Created by Carlos Galo on 10/9/20.
//

#ifndef AI_BOARDGAMES_BOARD_H
#define AI_BOARDGAMES_BOARD_H

#include "../Move/Move.h"
#include <iostream>                                     // For cout, endl & cerr

class Board {

private:
    char ** board;
    int size;
    char emptyChar;

    // Methods
    bool setMoveHelper(int row, int col, char val);     // Method is called by both setMove methods to perform the move in the board
    bool isMoveValid(int row, int col) const;           // Check if the given row and column are valid locations for the board

public:
    Board(int size = 3, char emptyChar = ' ');          // Constructor, size and emptyChar have a default value if not given
    ~Board();                                           // Destructor

    // Methods
    int getSize() const;                                // Getter for int size
    bool isEmpty();                                     // Checks if the board has any empty spaces left
    Move** getAvailableMoves();                         // Returns list of open spots in the board
    void setMove(Move* move, char val);                 // Set move allows the user to set value inside the Board
    void setMove(int row, int col, char val);           // Set move allows the user to set value inside the Board
    void printBoard();                                  // Outputs the current state of the board
};


#endif //AI_BOARDGAMES_BOARD_H
