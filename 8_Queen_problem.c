#include <stdio.h>

#define N 8

int board[N][N] = {0};

// Check whether queen can be placed
int isSafe(int row, int col)
{
    int i, j;

    // Check column
    for (i = 0; i < row; i++)
        if (board[i][col])
            return 0;

    // Check upper-left diagonal
    for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return 0;

    // Check upper-right diagonal
    for (i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++)
        if (board[i][j])
            return 0;

    return 1;
}

// Solve the problem
int solve(int row)
{
    int col;

    if (row == N)
        return 1;

    for (col = 0; col < N; col++)
    {
        if (isSafe(row, col))
        {
            board[row][col] = 1;

            if (solve(row + 1))
                return 1;

            board[row][col] = 0;
        }
    }

    return 0;
}

// Display chessboard
void printBoard()
{
    int i, j;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (board[i][j])
                printf(" Q ");
            else
                printf(" . ");
        }
        printf("\n");
    }
}

int main()
{
    if (solve(0))
        printBoard();
    else
        printf("No solution exists.");

    return 0;
}