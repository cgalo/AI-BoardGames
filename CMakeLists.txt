cmake_minimum_required(VERSION 3.17)
project(AI_BoardGames)

set(CMAKE_CXX_STANDARD 14)

add_executable(AI_BoardGames src/main.cpp include/Games/TicTacToe/TicTacToe.cpp include/Games/TicTacToe/TicTacToe.h include/Move/Move.cpp include/Move/Move.h include/Board/Board.cpp include/Board/Board.h test/BoardTest.h)