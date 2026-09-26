#include <stdio.h>
#include <limits.h>

#define MAX 100

int main() {
    int n, e;
    int graph[MAX][MAX] = {0};
    int key[MAX], parent[MAX], mstSet[MAX];
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (source destination weight):\n");

    for (i = 0; i < e; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        graph[u][v] = w;
        graph[v][u] = w;   // Undirected graph
    }

    // Initialize
    for (i = 0; i < n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
        parent[i] = -1;
    }

    // Start from vertex 0
    key[0] = 0;

    // Prim's algorithm
    for (i = 0; i < n - 1; i++) {
        int min = INT_MAX;
        int u = -1;

        // Find minimum key vertex
        for (j = 0; j < n; j++) {
            if (mstSet[j] == 0 && key[j] < min) {
                min = key[j];
                u = j;
            }
        }

        if (u == -1) {
            printf("\nGraph is not connected.\n");
            return 0;
        }

        mstSet[u] = 1;

        // Update adjacent vertices
        for (j = 0; j < n; j++) {
            if (graph[u][j] != 0 &&
                mstSet[j] == 0 &&
                graph[u][j] < key[j]) {

                parent[j] = u;
                key[j] = graph[u][j];
            }
        }
    }

    // Print MST
    int total = 0;

    printf("\nMinimum Spanning Tree:\n");
    printf("Edge\tWeight\n");

    for (i = 1; i < n; i++) {
        printf("%d - %d\t%d\n",
               parent[i], i, graph[i][parent[i]]);

        total += graph[i][parent[i]];
    }

    printf("\nTotal MST weight = %d\n", total);

    return 0;
}
/*
Enter number of vertices: 5
Enter number of edges: 7
Enter edges (source destination weight):
0 1 2
0 3 6
1 2 3
1 3 8
1 4 5
2 4 7
3 4 9

Minimum Spanning Tree:
Edge	Weight
0 - 1	2
1 - 2	3
0 - 3	6
1 - 4	5

Total MST weight = 16
*/