#include <stdio.h>

#define MAX 100

// Structure for an edge
struct Edge {
    int u, v, weight;
};

// Find parent of a vertex
int find(int parent[], int i) {
    if (parent[i] == i)
        return i;

    return find(parent, parent[i]);
}

// Union of two sets
void unionSet(int parent[], int rank[], int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);

    if (rank[rootX] < rank[rootY])
        parent[rootX] = rootY;
    else if (rank[rootX] > rank[rootY])
        parent[rootY] = rootX;
    else {
        parent[rootY] = rootX;
        rank[rootX]++;
    }
}

int main() {
    int n, e;
    struct Edge edges[MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (source destination weight):\n");

    for (int i = 0; i < e; i++) {
        scanf("%d %d %d",
              &edges[i].u,
              &edges[i].v,
              &edges[i].weight);
    }

    // Sort edges by weight
    for (int i = 0; i < e - 1; i++) {
        for (int j = 0; j < e - i - 1; j++) {

            if (edges[j].weight > edges[j + 1].weight) {
                struct Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    int parent[MAX], rank[MAX];

    // Initialize sets
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    int count = 0;
    int total = 0;

    printf("\nMinimum Spanning Tree:\n");
    printf("Edge\tWeight\n");

    // Kruskal's algorithm
    for (int i = 0; i < e && count < n - 1; i++) {

        int u = edges[i].u;
        int v = edges[i].v;

        int rootU = find(parent, u);
        int rootV = find(parent, v);

        // If adding edge does not create cycle
        if (rootU != rootV) {

            printf("%d - %d\t%d\n",
                   u, v, edges[i].weight);

            total += edges[i].weight;
            count++;

            unionSet(parent, rank, rootU, rootV);
        }
    }

    if (count != n - 1) {
        printf("\nGraph is not connected.\n");
    } else {
        printf("\nTotal MST weight = %d\n", total);
    }

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
1 - 4	5
0 - 3	6

Total MST weight = 16
*/  