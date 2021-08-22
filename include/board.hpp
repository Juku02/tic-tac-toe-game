#ifndef BOARD_H
#define BOARD_H

#include<vector>
#include<iostream>

extern "C"{

class Board
{
private:
    std::vector<std::vector<char>> board;
    
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