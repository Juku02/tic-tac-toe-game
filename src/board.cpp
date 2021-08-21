#include "board.hpp"

void Board::initBoard()
{
     int i, j;
     std::vector<char> row;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            row.push_back('*');
        board.push_back(std::move(row));
           
}

// void Board::drawBoard()
// {
//       int t;

//     for (t = 0; t < 3; t++)
//     {
//         printf(" %c | %c | %c ", );
//         if (t != 2)
//             printf("\n---|---|---\n");
//     }
//     printf("\n");
// }


// char Board::check()
// {

// }