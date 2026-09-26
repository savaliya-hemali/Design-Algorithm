#include <stdio.h>

#define MAX 8

int board[MAX][MAX];

/* Check whether a queen can be placed */
int isSafe(int row, int col, int n)
{
    int i, j;

    /* Check column */
    for (i = 0; i < row; i++)
        if (board[i][col] == 1)
            return 0;

    /* Check left diagonal */
    for (i = row - 1, j = col - 1;
         i >= 0 && j >= 0;
         i--, j--)
        if (board[i][j] == 1)
            return 0;

    /* Check right diagonal */
    for (i = row - 1, j = col + 1;
         i >= 0 && j < n;
         i--, j++)
        if (board[i][j] == 1)
            return 0;

    return 1;
}

/* Backtracking function */
int solve(int row, int n)
{
    int col;

    /* All queens are placed */
    if (row == n)
        return 1;

    for (col = 0; col < n; col++)
    {
        if (isSafe(row, col, n))
        {
            board[row][col] = 1;

            if (solve(row + 1, n))
                return 1;

            /* Backtrack */
            board[row][col] = 0;
        }
    }

    return 0;
}

/* Display chessboard */
void display(int n)
{
    int i, j;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (board[i][j])
                printf(" 1 ");
            else
                printf(" 0 ");
        }
        printf("\n");
    }
}

int main()
{
    int n;

    printf("Enter number of queens (4 or 8): ");
    scanf("%d", &n);

    if (n != 4 && n != 8)
    {
        printf("Please enter only 4 or 8.\n");
        return 0;
    }

    if (solve(0, n))
    {
        printf("\nSolution for %d-Queens:\n\n", n);
        display(n);
    }
    else
    {
        printf("No solution exists.\n");
    }

    return 0;
}