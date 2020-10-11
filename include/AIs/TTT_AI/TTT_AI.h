//
// Created by Carlos Galo on 10/11/20.
//

#ifndef AI_BOARDGAMES_TTT_AI_H
#define AI_BOARDGAMES_TTT_AI_H

#include "../AI.h"
class TTT_AI : public AI {
private:
    char maxP, minP;                                    // Max and min player

    // Methods
    int MiniMax(Board* board, int depth, bool isMax);   // Recursive function to returns the value of the board

public:
    TTT_AI(char maxP = 'X', char minP = 'O');           // Constructor
    ~TTT_AI();                                          // Destructor

    // Methods
    int evalBoard(Board* board);                        // Evaluate the given board and return pos/neg 1 or 0
    Move* getBestMove(Board* board);                    // Get the best possible move for the max player (maxP)
};


#endif //AI_BOARDGAMES_TTT_AI_H