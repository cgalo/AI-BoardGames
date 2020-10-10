//
// Created by Carlos Galo on 10/9/20.
//

#ifndef AI_BOARDGAMES_BOARD_H
#define AI_BOARDGAMES_BOARD_H

#include "../Move/Move.h"

class Board {

private:
    char ** board;
    int size;
    char emptyChar;

public:
    Board(int size = 3, char emptyChar = ' ');      // Constructor, requires a size, defining empty char is optional
    ~Board();                                       // Destructor

    int getSize() const;                            // Getter for int size
    bool isEmpty();                                 // Checks if the board has any empty spaces left
    Move** getAvailableMoves();                     // Returns list of open spots in the board
};


#endif //AI_BOARDGAMES_BOARD_H
