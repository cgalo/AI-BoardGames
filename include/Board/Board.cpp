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
    if (!isEmpty())                                     // If the board has no empty spaces in it
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
            {
                moves[movesIndex] = new Move(row, col); // Insert a new move into the array with the curr row & col
                movesIndex++;                           // Update index
            }

    return moves;                                       // Return the array of Move pointers
}

bool Board::isMoveValid(int row, int col) const
{
    /**
     * Method checks that the given row and column are within the size of the board, not out of bound
     *
     * Invalid Input: Move->row(or column) == -1 or Move->row(or column) >= Board.getSize()
     *
     * @param int row: index location inside the board
     * @param int col: index location inside the board
     * @return false is the row or column are outside the bounds of the board, by being either less than 0
     *         or greater than the size of the board
     * @return true if both, row and column, are within the board, both are equal or greater than 0 and less than the
     *         size
     */

    if (row < 0 && row >= size ||                       // If the row is an invalid input
        col < 0 && col >= size)                         // Or if the column is an invalid input
        return false;                                   // Return false as this move is not valid

    return true;                                        // Else the move is valid so we return true
}

void Board::setMove(int row, int col, char val)
{

    if (isMoveValid(row, col))                          // If the move is valid (within the size of the board)
        setMoveHelper(row, col, val);                   // Then make the move and set the new value in the board
    else                                                // Else the move was not valid, output an error message
        std::cerr << "Error! The move (" << row << ", " << col << ") is not valid." << std::endl;
}

void Board::setMove(Move *move, char val)
{
    /**
     * Method parses the Move pointer to get the row and column and passes the values to the isMoveValid method to
     * check if the row and column are within the board, if they are then we call setMoveHelper to perform the move
     *
     * Method also checks that the given move is a valid input. Both row and column have to be greater than 0 but
     * less than the size of the board.
     *
     * @param Move pointer, holds the row and column location of the board we want to change the value in
     * @param char Val should be the new value we want to insert into the board
     */

    // First we validate the the Move has row and column in a valid location
    int row = move->getRow();
    int col = move->getColumn();
    if (isMoveValid(row, col))                          // If the move is valid (within the size of the board)
        setMoveHelper(row, col, val);                   // Then make the move and set the new value in the board
    else                                                // Else the move was not valid, output an error message
        std::cerr << "Error! The move (" << row << ", " << col << ") is not valid." << std::endl;
}

bool Board::setMoveHelper(int row, int col, char val) {

    /**
     * Method sets the given val into the location provided inside the board
     *
     * @param int row, index location of the row were to insert the char val
     * @param int col, index location of the column in the board we want to insert char val
     * @param char val, character that will be places inside the board
     *
     * @returns true if the value was set in the location, false if it wasn't successfully set
     */

    board[row][col] = val;                      // Set the value in the given location of the board
    return (board[row][col] == val);            // Return true if the value was successfully set, else return false
}
