/**
 * @author: Carlos Galo
 * @date: 10/11/2020
 *
 * This is an abstract class for the AI's I'll implement for each game.
 * C++ does not have built-in concepts of interfaces, so it was decided to use an abstract class with pure virtual
 * classes instead.
 */

#ifndef AI_BOARDGAMES_AI_H
#define AI_BOARDGAMES_AI_H

#include "../Board/Board.h"

class AI {
protected:
    virtual int MiniMax(Board* board, int depth, bool isMax, int alpha, int beta) const = 0;
public:
    virtual int evalBoard(Board* board) const = 0;
    virtual Move* getBestMove(Board* board) = 0;
};

#endif //AI_BOARDGAMES_AI_H
