//
// Created by Carlos Galo on 10/10/20.
//

#ifndef AI_BOARDGAMES_BOARDTEST_H
#define AI_BOARDGAMES_BOARDTEST_H

#include "../include/Board/Board.h"
class BoardTest {
private:
    bool sizeTest()
    {
        bool result = false;
        Board * board = new Board(5);
        Board * board1 = new Board(3);
        Board* board2 = new Board(8);

        if (board->getSize() == 5 &&
            board1->getSize() == 3 &&
            board2->getSize() == 8 )
            result = true;
        else
            result = false;

        delete board;
        delete board1;
        delete board2;

        return result;

    }

    bool isEmptyTest()
    {
        Board * board = new Board();    // This will be set to default size 3 with emptyChar = (' ')
        // Now set up a board that is halfway played

    }
public:
    bool test()
    {
        bool testSize = sizeTest();
        bool testIsEmpty = isEmptyTest();
        return true;
    }


};


#endif //AI_BOARDGAMES_BOARDTEST_H
