#include <stdio.h>

#define MAX 100

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n, capacity;
    int weight[MAX], value[MAX];
    int dp[MAX][MAX];

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter capacity of knapsack: ");
    scanf("%d", &capacity);

    printf("Enter weight and value of each item:\n");

    for (int i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &weight[i], &value[i]);
    }

    // Initialize DP table
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {

            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            }
            else if (weight[i - 1] <= w) {

                dp[i][w] = max(
                    value[i - 1] + dp[i - 1][w - weight[i - 1]],
                    dp[i - 1][w]
                );

            }
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    printf("\nMaximum profit = %d\n", dp[n][capacity]);

    // Find selected items
    printf("Selected items: ");

    int w = capacity;

    for (int i = n; i > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            printf("%d ", i);
            w = w - weight[i - 1];
        }
    }

    printf("\n");

    return 0;
}
/*
Enter number of items: 4
Enter capacity of knapsack: 7
Enter weight and value of each item:
Item 1: 1 1
Item 2: 3 4
Item 3: 4 5
Item 4: 5 7

Maximum profit = 9
Selected items: 3 2 

*/