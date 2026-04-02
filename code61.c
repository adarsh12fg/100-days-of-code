// Problem: Build a graph with n vertices and m edges using adjacency matrix representation.
// The graph may be directed or undirected.

#include <stdio.h>

int main() {
    int n, m, i;
    int u, v;
    int directed;


    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);


    printf("Is the graph directed? (1 for Yes, 0 for No): ");
    scanf("%d", &directed);


    int adj[n][n];
    for (i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }


    printf("Enter %d edges (u v):\n", m);
    for (i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;   // mark edge u → v
        if (!directed) {
            adj[v][u] = 1; // for undirected graph
        }
    }


    printf("\nAdjacency Matrix:\n");
    for (i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}

