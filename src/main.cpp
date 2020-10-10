#include <iostream>
#include "../test/BoardTest.h"
using namespace std;
int main(int argc, char **argv) {

    if (argc > 1 && strcmp(argv[1], "-t") == 0)             // If user entered "-t" to enter testing mode
    {
        cout << "You enter testing mode." << endl;

        cout << "Running BoardTest..." << endl;             // Start by testing the Board class
        BoardTest* boardTest = new BoardTest();
        bool board = boardTest->test();                     // Save the if board passed all the tests



    }
    else                                                    // By default we just run the program
    {

    }


    return 0;
}
