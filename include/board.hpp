#ifndef BOARD_H
#define BOARD_H

#include<vector>
#include<iostream>

extern "C"{

class Board
{
private:
    // std::vector<std::vector<char>> board;
    // std::vector<char> row;
    char board[3][3];
    int i,j;
    
public:
        Board();
        void initBoard();
        void drawBoard();
        char check();
};

#ifdef __cplusplus
}
#endif
#endif