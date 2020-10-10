//
// Created by Carlos Galo on 10/10/20.
//

#ifndef AI_BOARDGAMES_BOARDTEST_H
#define AI_BOARDGAMES_BOARDTEST_H

#include "../include/Board/Board.h"
class BoardTest {
protected:
    Board* testingBoard(int size = 3)
    {
        // This method returns a prefilled board
        Board * board = new Board(size);            // Start by creating an empty board, with size of 3
        char val = 'X';                             // To set the first two rows with Xs

        for (int row = 0; row < size - 1; row++)    // Iterate through all rows except the last one
            for (int col = 0; col < size; col++)    // Iterate through all the columns of the current row
                board->setMove(row, col, val);      // Set an 'X' in the current index

        /*
         * We'll leave the last row in the board as open spaces (as default in the board)
         * Board ends up looking like this:
         *
         *  X | X | X
         *  ----------
         *  X | X | X
         *  ----------
         *    |   |
         *
         *  With only 3 open/available spots left in the board: (2,0), (2,1), (2,2)
         * */

        return board;
    }
    Board* fullBoard(int size = 3)
    {
        // Create an empty board and fill up all the elements in the board
        Board* filledBoard = new Board(size);       // Create a new board
        for (int row = 0; row < size; row++)        // Iterate through every row
            for (int col = 0; col < size; col++)    // Iterate through every column
                filledBoard->setMove(row, col, 'X');    // Set the board with 'X's throughout

        return filledBoard;
    }

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
            std::cerr << "Fail task: sizeTest" << std::endl;

        delete board;
        delete board1;
        delete board2;

        return result;

    }

    bool isEmptyTest()
    {
        bool results = true;                        // We'll use this to return if the test worked as expected
        // First lets check isEmpty method with an empty board, no moves done yet
        Board * board1 = new Board();               // This will be set to default size 3 with emptyChar = (' ')
        if (!board1->isEmpty())                     // If the board is marked as not empty, aka it thinks it's full
        {
            // We expect this to never happen, so we output an error as log and set results to false
            std::cerr << "Fail task: isEmptyTest, Board1\n"
                         "Board1 was expected to return isEmpty as true but returned false" << std::endl;
            results = false;
        }

        // Now lets test with an halfway filled board
        Board * board2 = testingBoard();            // Get a board with values in it
        if (!board2->isEmpty())                     // If the board is marked as not empty, aka it thinks it's full
        {
            // We expect this to never happen, so we output an error as log and set results to false
            std::cerr << "Fail task: isEmptyTest, Board2\n"
                         "Board2 was expected to return isEmpty as true but returned false" << std::endl;
            results = false;
        }

        // Now we'll test for a board that has no empty spaces
        Board * board3 = fullBoard();               // Get the testingBoard with some filled values
        if (board3->isEmpty())                      // If the fullBoard is marked as empty
        {
            // We expect this to never happen, so we output an error as log and set results to false
            std::cerr << "Fail task: isEmptyTest, Board3\n"
                         "Board3 was expected to return isEmpty as false but returned true" << std::endl;
            results = false;
        }

        // Perform GC on the boards created for this test
        delete board1;
        delete board2;
        delete board3;

        // Now return the result of this exam
        return results;
    }

    bool availableMovesTest()
    {
        bool results = true;                                // To keep track if we failed this test

        // First we test for an empty board
        Board* board1 = new Board();                        // Create an open board
        int maxMoves = board1->getSize() * board1->getSize();   // Max open spaces is Board size * size
        Move** moves1 = board1->getAvailableMoves();        // Get all the available moves in the board
        if (moves1 == nullptr)                              // If we got returned a nullptr
            results = false;                                // Then we failed
        else                                                // Else we did not get returned  nullptr
        {
            int totMoves = 0;                               // Keep track of total moves in the array
            for (int i = 0; i < maxMoves; i++)              // Iterate through the array of moves
                if (moves1[i] != nullptr)                   // If we are in an actual move
                    totMoves++;                             // Update total moves
            // We get here after iterating through the moves
            if (totMoves != maxMoves)                       // If total moves is not equal to total max
                results = false;                            // Set the test as failed
        }
        if (!results)                                       // If we failed the test until here
            std::cerr << "Failed task: availableMoveTest -> Board: board1" << std::endl;

        // Now lets check for a played board
        Board* board2 = testingBoard();                     // Test for a board 3x3 that has been filled
        int maxMoves2 = board2->getSize() * board2->getSize();  // Calculate max moves for this board
        Move** moves2 = board2->getAvailableMoves();        // Get the available moves
        if (moves2 == nullptr)                              // If moves2 is a nullptr
        {
            results = false;                                // We failed
            std::cerr << "Failed task: availableMoveTest -> Board: board2" << std::endl;
        }
        else
        {
            int totMoves = 0;                               // Keep track of how many moves are in the moves array
            for (int i = 0; i < maxMoves2; i++)             // Iterate through the moves array
                if (moves2[i] != nullptr)                   // If the current element is not a nullptr
                    totMoves++;                             // We increase the size of totMoves
            if (totMoves != 3)                              // We know that in this board there only 3 possible moves
            {
                results = false;                            // We set it to false if it doesn't have what's expected
                std::cerr << "Failed task: availableMoveTest -> Board: board2" << std::endl;
            }
        }

        // Now we test for a filled board
        Board* board3 = fullBoard();                        // Get a filled board of size 3x3
        int maxMoves3 = board3->getSize() * board3->getSize();  // Calculate the mas moves for this board
        Move** moves3 = board3->getAvailableMoves();        // Get the available moves
        if (moves3 != nullptr)                              // If moves3 is not a nullptr
        {
            results = false;                                // Then we fail this test as there shouldn't be any moves
            std::cerr << "Failed task: availableMoveTest -> Board: board3" << std::endl;
        }


        //Perform garbage collection
        delete board1;
        delete []moves1;
        delete board2;
        delete []moves2;
        delete board3;
        delete []moves3;

        return results;                                         // Return result for this test
    }
public:
    bool test()
    {
        bool testResults = true;            // Value to check if we failed a test or not

        // Call and get the results of the tests
        bool testSize = sizeTest();
        bool testIsEmpty = isEmptyTest();
        bool testMoves = availableMovesTest();

        // If we failed any of our tests
        if (!testSize || !testIsEmpty || !testMoves)
        {
            std::cerr << "BoardTest result: Failed" << std::endl;
            testResults = false;
        }
        return testResults;
    }

};

#endif //AI_BOARDGAMES_BOARDTEST_H