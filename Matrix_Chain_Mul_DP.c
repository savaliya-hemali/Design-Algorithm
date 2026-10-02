#include <stdio.h>
#include <limits.h>

#define MAX 100

// Matrix Chain Multiplication
void matrixChainMultiplication(int p[], int n)
{
    int m[MAX][MAX];
    int i, j, k, L, q;

    // Cost is 0 when multiplying one matrix
    for (i = 1; i <= n; i++)
        m[i][i] = 0;

    // L is chain length
    for (L = 2; L <= n; L++)
    {
        for (i = 1; i <= n - L + 1; i++)
        {
            j = i + L - 1;
            m[i][j] = INT_MAX;

            // Try every possible split
            for (k = i; k < j; k++)
            {
                q = m[i][k] +
                    m[k + 1][j] +
                    p[i - 1] * p[k] * p[j];

                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }

    printf("\nMinimum number of scalar multiplications = %d\n",
           m[1][n]);
}

int main()
{
    int n;
    int p[MAX];
    int i;

    printf("Enter number of matrices: ");
    scanf("%d", &n);

    printf("Enter dimensions of matrices:\n");

    printf("Enter %d dimensions: ", n + 1);

    for (i = 0; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }

    matrixChainMultiplication(p, n);

    return 0;
}