#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 4096

//Game matrix structur 
struct matrix
{
    char matrix[3][3];
    char firstPlayer, secondPlayer;
};
//Initation matrix
void init_matrix(struct matrix *mi)
{
    int i, j;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            mi->matrix[i][j] = ' ';
}
//Initation players
void init_players(struct matrix *mp)
{
    printf("Choose your chars players (first,second): ");
    scanf("%c%*c%c", &mp->firstPlayer, &mp->secondPlayer);
}
//Board drawning
void drawBoad(struct matrix *md)
{

    int t;

    for (t = 0; t < 3; t++)
    {
        printf(" %c | %c | %c ", md->matrix[t][0],
               md->matrix[t][1], md->matrix[t][2]);
        if (t != 2)
            printf("\n---|---|---\n");
    }
    printf("\n");
}
//Player moves
void get_player_move(struct matrix *mp)
{
    int x, y;

    printf("Enter X,Y coordinates for your move: ");
    scanf("%d%*c%d", &x, &y);

    x--;
    y--;

    if (mp->matrix[x][y] != ' ')
    {
        printf("Invalid move, try again.\n");
        get_player_move(mp);
    }
    else
        mp->matrix[x][y] = mp->firstPlayer;
}
//Computer/Second Player moving
void get_computer_move(struct matrix *mp)
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
            if (mp->matrix[i][j] == ' ')
                break;
        if (mp->matrix[i][j] == ' ')
            break;
    }

    if (i * j == 9)
    {
        printf("Draw\n");
        exit(0);
    }
    else
        mp->matrix[i][j] = mp->secondPlayer;
}
//Board checking for winners
char check(struct matrix *mc)
{
    int i, j;
    char X[3][3];
    char O[3][3];

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            X[i][j] = mc->firstPlayer;
            O[i][j] = mc->secondPlayer;
        }
    }

    for (i = 0; i < 3; i++)
    {
        if (mc->matrix[i][0] == X[i][0] && mc->matrix[i][2] == X[i][2])
            if (mc->matrix[i][1] == X[i][1])
                return mc->firstPlayer;

        if (mc->matrix[0][i] == X[0][i] && mc->matrix[2][i] == X[2][i])
            if (mc->matrix[1][i] == X[1][i])
                return mc->firstPlayer;

        if (mc->matrix[i][0] == O[i][0] && mc->matrix[i][2] == O[i][2])
            if (mc->matrix[i][1] == O[i][1])
                return mc->secondPlayer;

        if (mc->matrix[0][i] == O[0][i] && mc->matrix[2][i] == O[2][i])
            if (mc->matrix[1][i] == O[1][i])
                return mc->secondPlayer;
    }
    /* test diagonals first Player */
    if (mc->matrix[0][0] == X[0][0] &&
        mc->matrix[1][1] == X[1][1])
        if (mc->matrix[2][2] == X[2][2])
            return mc->firstPlayer;

    if (mc->matrix[0][2] == X[1][1] &&
        mc->matrix[1][1] == X[1][1])
        if (mc->matrix[2][0] == X[2][0])
            return mc->firstPlayer;

     /* test diagonals second Player */
    if (mc->matrix[0][0] == O[0][0] &&
        mc->matrix[1][1] == O[1][1])
        if (mc->matrix[2][2] == O[2][2])
            return mc->secondPlayer;

    if (mc->matrix[0][2] == O[1][1] &&
        mc->matrix[1][1] == O[1][1])
        if (mc->matrix[2][0] == O[2][0])
            return mc->secondPlayer;        
    return ' ';
}

int main(int argc, char const *argv[])
{
    struct matrix ma;
    char done;
    done = ' ';
    printf("Tic Tac Toe Game\n");
    init_players(&ma);
    init_matrix(&ma);

    do
    {
        drawBoad(&ma);
        get_player_move(&ma);
        done = check(&ma);
        get_computer_move(&ma);
        done = check(&ma);
    } while (done == ' ');

    if (done == ma.firstPlayer)
        printf("%c won! \n", ma.firstPlayer);
    if (done == ma.secondPlayer)
        printf("%c won! \n", ma.secondPlayer);
    drawBoad(&ma);
}
