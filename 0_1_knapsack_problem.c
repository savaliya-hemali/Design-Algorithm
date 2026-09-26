#include <stdio.h>

struct Item {
    int weight;
    int profit;
    float ratio;
};

int main() {
    int n, capacity;
    struct Item item[20], temp;
    int i, j, totalWeight = 0, totalProfit = 0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weight and profit of each item:\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d", &item[i].weight, &item[i].profit);
        item[i].ratio = (float)item[i].profit / item[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    /* Sort items by profit/weight ratio */
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (item[i].ratio < item[j].ratio) {
                temp = item[i];
                item[i] = item[j];
                item[j] = temp;
            }
        }
    }

    /* Select items greedily */
    for (i = 0; i < n; i++) {
        if (totalWeight + item[i].weight <= capacity) {
            totalWeight += item[i].weight;
            totalProfit += item[i].profit;
        }
    }

    printf("\nTotal Weight = %d", totalWeight);
    printf("\nTotal Profit = %d\n", totalProfit);

    return 0;
}
/*
Enter number of items: 3
Enter weight and profit of each item:
10 60
20 100
30 120
Enter knapsack capacity: 50

Total Weight = 50
Total Profit = 220
*/