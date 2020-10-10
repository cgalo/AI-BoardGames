//
// Created by Carlos Galo on 10/9/20.
//

#ifndef AI_BOARDGAMES_MOVE_H
#define AI_BOARDGAMES_MOVE_H


class Move {
private:
    int row;                                // Index location of the row in the graph
    int column;                             // Index location of the column in the graph

public:
    Move(int row = -1, int column = -1);    // Constructor

    // Getters and setters
    int getRow() const;                     // Row getter

    void setRow(int row);                   // Row setter

    int getColumn() const;                  // Column getter

    void setColumn(int column);             // Column setter
};


#endif //AI_BOARDGAMES_MOVE_H
