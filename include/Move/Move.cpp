//
// Created by Carlos Galo on 10/9/20.
//

#include "Move.h"

Move::Move(int row, int column) {
    /**
     * Constructor for the Move class
     * @param row to set the row index for the move, if not given then is sets it to -1
     * @param column to set the column index for the move, if not given then is sets it to -1
     */

    this->row = row;
    this->column = column;
}

int Move::getRow() const {
    /**
     * Getter method for the int row attribute
     * @return the current Move's row value
     */

    return row;                     // Return the row index
}

void Move::setRow(int row) {
    /**
     * Setter method for the int row attribute
     * @param int row, to set it as the new row value of the Move object
     */

    this->row = row;                // Set the new value of the row
}

int Move::getColumn() const {
    /**
     * Getter for the column attribute
     * @return the current Move'
     */

    return column;                  // Return the column for the move
}

void Move::setColumn(int column) {
    /**
     * Setter method for the int column attribute
     * @param int column, to set it as the new column of the Move object
     */

    this->column = column;
}