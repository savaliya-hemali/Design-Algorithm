#include <stdio.h>
#include <limits.h>

#define MAX 100

int main() {
    int n, e;
    int cost[MAX][MAX];
    int dist[MAX];
    int path[MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Initialize cost matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cost[i][j] = 0;
        }
    }

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (source destination cost):\n");

    for (int i = 0; i < e; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        cost[u][v] = w;
    }

    // Destination is n-1
    dist[n - 1] = 0;

    // Calculate minimum cost from right to left
    for (int i = n - 2; i >= 0; i--) {
        dist[i] = INT_MAX;

        for (int j = i + 1; j < n; j++) {
            if (cost[i][j] != 0 && dist[j] != INT_MAX) {

                if (cost[i][j] + dist[j] < dist[i]) {
                    dist[i] = cost[i][j] + dist[j];
                    path[i] = j;
                }
            }
        }
    }

    if (dist[0] == INT_MAX) {
        printf("\nNo path exists.\n");
        return 0;
    }

    printf("\nMinimum cost = %d\n", dist[0]);

    printf("Minimum cost path: ");

    int current = 0;

    while (current != n - 1) {
        printf("%d -> ", current);
        current = path[current];
    }

    printf("%d\n", current);

    return 0;
}


/*
Enter number of vertices: 8
Enter number of edges: 12
Enter edges (source destination cost):
0 1 2
0 2 1
0 3 3
1 4 2
1 5 3
2 4 6
2 5 7
3 5 4
4 6 2
5 6 1
5 7 3
6 7 2

Minimum cost = 8
Minimum cost path: 0 -> 1 -> 4 -> 6 -> 7
*/