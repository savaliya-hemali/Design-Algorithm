
#include <stdio.h>
#include <time.h>

int main() {
    int n, amount, i, j, temp;

    printf("Enter number of coin denominations: ");
    scanf("%d", &n);

    int coins[n];

    printf("Enter coin denominations:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }

    printf("Enter amount: ");
    scanf("%d", &amount);

    // Sort coins in descending order
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (coins[i] < coins[j]) {
                temp = coins[i];
                coins[i] = coins[j];
                coins[j] = temp;
            }
        }
    }

    clock_t start = clock();

    printf("Coins used: ");

    for (i = 0; i < n; i++) {
        while (amount >= coins[i]) {
            printf("%d ", coins[i]);
            amount -= coins[i];
        }
    }

    if (amount != 0) {
        printf("\nExact change is not possible.");
    }

    clock_t end = clock();

    printf("\nCPU Execution Time: %f seconds\n",
           (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}
