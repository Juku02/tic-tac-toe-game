#include "../include/board.hpp"


Board::Board ()  
{   
}

void Board::initBoard()
{
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
        //     row.push_back('*');
        // board.push_back(std::move(row));
        board[i][j] = ' ';
}

void Board::drawBoard()
{
    for (i = 0; i < 3; i++)
    {   
           printf(" %c | %c | %c ", board[i][0],
               board[i][1], board[i][2]);
            if (i != 2)
                printf("\n---|---|---\n"); 
    }
    printf("\n");
}


// char Board::check()
// {

// }