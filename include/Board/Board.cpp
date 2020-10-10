//
// Created by Carlos Galo on 10/9/20.
//

#include "Board.h"

Board::Board(int size, char emptyChar)
{
    /**
     * Constructor for the Board class, called every time we create a new Board object
     *
     * @param size to set the size of the board, if not provided then the size is default to a 3x3
     * @param emptyChar to set every column/element in the board to that, if not provided then emptyChar is a space (' ')
     */
    board = new char* [size];                   // Create the the rows of the board
    for (int row = 0; row < size; row++)        // Iterate through the new create rows
        board[row] = new char[size];            // Create columns, equivalent to the total rows, per row

    // Now we iterate through the created board and set every column to the emptyChar
    for (int row = 0; row < size; row++)        // Iterate through every row
        for (int col = 0; col < size; col++)    // Iterate through every column
            board[row][col] = emptyChar;        // Set the current block to the emptyChar

    this->size = size;                          // Set the size of the board
    this->emptyChar = emptyChar;                // Set the emptyChar for the board
}

Board::~Board()
{
    /**
     * Destructor for the Board class to perform garbage collection
     * Deletes the Board (char array) and resets the size and emptyChar variables back to 0
     */

    delete []board;                             // Delete the board array
    size = 0;                                   // Set the size to 0
    emptyChar = 0x00;                           // Set the char to 0
}

int Board::getSize() const
{
    /**
     * Getter method for the int size
     *
     * @param: None
     * @return the size of the board
     */

    return this->size;                          // Return the size of the board
}

bool Board::isEmpty()
{
    /**
     * Method checks if there is at least one empty space in the current state of the board
     *
     * @param: None
     * @returns True if there is at least one column with an emptyChar
     * @returns False if it never finds one column with an emptyChar
     */

    for (int row = 0; row < size; row++)
        for (int col = 0; col < size; col++)
            if (board[row][col] == emptyChar)
                return true;
    return false;
}

Move ** Board::getAvailableMoves()
{
    /**
     * Method returns list of Move pointers that contain open spaces in the board
     * - A column is considered as an empty space if it has an emptyChar value in it
     *
     * @parm: None
     * @returns: Array of Move pointers with location of empty spaces in the board
     * @return: Nullptr if there are no available spots in the board
     * */

    // Base case
    if (isEmpty())                                      // If the board has no empty spaces in it
        return nullptr;                                 // Return nullptr

    int maxMoves = size * size;                         // Total possible moves is the size * size
    Move ** moves = new Move* [maxMoves];               // First we create an empty array of move pointers
    for (int i = 0; i < maxMoves; i++)                  // Iterate through the whole array
        moves[i] = nullptr;                             // Set each index to a nullptr before filling out with moves

    // Now we are going to iterate through the board to see get the empty spaces in it
    int movesIndex = 0;                                 // Keep track of the index of the moves array
    for (int row = 0; row < size; row++)                // Iterate through every row
        for (int col = 0; col < size; col++)            // Iterate through every column of the current row
            if (board[row][col] == emptyChar)           // If we found an empty spot
                moves[movesIndex] = new Move(row, col); // Insert a new move into the array with the curr row & col

    return moves;                                       // Return the array of Move pointers
}