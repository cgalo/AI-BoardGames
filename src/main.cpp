#include <iostream>
#include "../include/Games/TicTacToe/TicTacToe.h"

#include "../test/BoardTest.h"
using namespace std;
int main(int argc, char **argv) {
    if (argc > 1 && strcmp(argv[1], "-t") == 0)             // If user entered "-t" to enter testing mode
    {
        cout << "You entered testing mode." << endl;

        cout << "\nRunning BoardTest..." << endl;           // Start by testing the Board class
        BoardTest* boardTest = new BoardTest();
        bool board = boardTest->test();                     // Save the if board passed all the tests
        if (board)
            cout << "\tBoardTest passed!" << endl;

        cout << "\nRunning TicTacToeTest..." << endl;       // Test the TicTacToe class

        // Perform garbage collection
        delete boardTest;
    }
    else                                                    // By default we just run the program
    {
        TicTacToe* TTT =  new TicTacToe();
        TTT->start();
    }


    return 0;
}
