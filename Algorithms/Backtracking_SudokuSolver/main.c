#include <stdio.h>
#include <stdlib.h>

#include "struct_and_prototypes.h"

#define TRUE 1
#define FALSE 0

int board[9][9] =
    {{7, 8, 0, 4, 0, 0, 1, 2, 0},
     {6, 0, 0, 0, 7, 5, 0, 0, 9},
     {0, 0, 0, 6, 0, 1, 0, 7, 8},
     {0, 0, 7, 0, 4, 0, 2, 6, 0},
     {0, 0, 1, 0, 5, 0, 9, 3, 0},
     {9, 0, 4, 0, 6, 0, 0, 0, 5},
     {0, 7, 0, 3, 0, 0, 0, 1, 2},
     {1, 2, 0, 0, 0, 7, 4, 0, 0},
     {0, 4, 9, 2, 0, 6, 0, 0, 7}};
int board2[9][9] =
    {{3, 0, 6, 5, 0, 8, 4, 0, 0},
     {5, 2, 0, 0, 0, 0, 0, 0, 0},
     {0, 8, 7, 0, 0, 0, 0, 3, 1},
     {0, 0, 3, 0, 1, 0, 0, 8, 0},
     {9, 0, 0, 8, 6, 3, 0, 0, 5},
     {0, 5, 0, 0, 9, 0, 6, 0, 0},
     {1, 3, 0, 0, 0, 0, 2, 5, 0},
     {0, 0, 0, 0, 0, 0, 0, 7, 4},
     {0, 0, 5, 2, 0, 6, 3, 0, 0}};

int board3[9][9] =
    {{8, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 3, 6, 0, 0, 0, 0, 0},
     {0, 7, 0, 0, 9, 0, 2, 0, 0},
     {0, 5, 0, 0, 0, 7, 0, 0, 0},
     {0, 0, 0, 0, 4, 5, 7, 0, 0},
     {0, 0, 0, 1, 0, 0, 0, 3, 0},
     {0, 0, 1, 0, 0, 0, 0, 6, 8},
     {0, 0, 8, 5, 0, 0, 0, 1, 0},
     {0, 9, 0, 0, 0, 0, 4, 0, 0}};

int board4[9][9] =
    {{8, 5, 0, 0, 0, 2, 4, 0, 0},
     {7, 2, 0, 0, 0, 0, 0, 0, 9},
     {0, 0, 4, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 1, 0, 7, 0, 0, 2},
     {3, 0, 5, 0, 0, 0, 9, 0, 0},
     {0, 4, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 8, 0, 0, 7, 0},
     {0, 1, 7, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 3, 6, 0, 4, 0}};


//////////////////////
//main function
//////////////////////

int main()
{
    // Print_board(board3, 9);
    puts("-----------------------------");
    Solve(board3, 9);
    Print_board(board3, 9);
    return 0;
}

//////////////////////
//functions for solving sudoku
//////////////////////

void Print_board(int (*board)[9], int array_length)
{
    for (int i = 0; i < array_length; i++)
    {
        if ((i % 3 == 0) && (i != 0))
        {
            printf("---------------------\n");
        }
        for (int j = 0; j < array_length; j++)
        {
            if ((j % 3 == 0) && (j != 0))
            {
                printf("| ");
            }
            printf("%d ", board[i][j]);
            if (j == 8)
            {
                printf("\n");
            }
        }
    }
}

Coordinate Find_first_empty_square(int (*board)[9], int array_length)
{
    Coordinate zero_coordinate;
    for (int i = 0; i < array_length; i++)
    {
        for (int j = 0; j < array_length; j++)
        {
            if (board[i][j] == 0)
            {
                zero_coordinate.completed = 0;
                zero_coordinate.y_coordinate = i;
                zero_coordinate.x_coordinate = j;
                return zero_coordinate;
            }
        }
    }
    zero_coordinate.completed = 1;
    return zero_coordinate;
}

int Validate_value(int (*board)[9], int value, Coordinate coordinate, int array_length)
{
    //Validate row
    for (int j = 0; j < array_length; j++)
    {
        if (board[coordinate.y_coordinate][j] == value && coordinate.x_coordinate != j)
        {
            return FALSE;
        }
    }

    //Validate column
    for (int i = 0; i < array_length; i++)
    {
        if (board[i][coordinate.x_coordinate] == value && coordinate.y_coordinate != i)
        {
            return FALSE;
        }
    }

    //check square
    int square_x = coordinate.x_coordinate / 3;
    int square_y = coordinate.y_coordinate / 3;

    for (int i = square_y * 3; i < square_y * 3 + 3; i++)
    {
        for (int j = square_x * 3; j < square_x * 3 + 3; j++)
        {
            if (board[i][j] == value && board[coordinate.y_coordinate][coordinate.x_coordinate] != board[i][j])
            {
                return FALSE;
            }
        }
    }

    return TRUE;
}

int Solve(int (*board)[9], int array_length)
{
    Coordinate zero_coordinate = Find_first_empty_square(board, array_length);

    if (zero_coordinate.completed == 1)
    {
        return TRUE;
    }
    else
    {
        for (int i = 1; i < 10; i++)
        {
            if (Validate_value(board, i, zero_coordinate, 9) == TRUE)
            {
                board[zero_coordinate.y_coordinate][zero_coordinate.x_coordinate] = i;
                if (Solve(board, 9) == TRUE)
                {
                    return TRUE;
                }
                board[zero_coordinate.y_coordinate][zero_coordinate.x_coordinate] = 0;
            }
        }
        return FALSE;
    }
}


