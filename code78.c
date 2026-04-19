// Problem Statement
// Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.




#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 1000

int adj[MAX][MAX];   // adjacency matrix

int primMST(int n) {
    int key[n+1];        // minimum weight edge to connect each vertex
    int parent[n+1];     // store MST edges
    int inMST[n+1];      // track included vertices

    for (int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        inMST[i] = 0;
        parent[i] = -1;
    }

    key[1] = 0;  // start from vertex 1
    int totalWeight = 0;

    for (int count = 1; count <= n; count++) {
        // pick vertex u not in MST with minimum key
        int min = INT_MAX, u = -1;
        for (int v = 1; v <= n; v++) {
            if (!inMST[v] && key[v] < min) {
                min = key[v];
                u = v;
            }
        }

        inMST[u] = 1;
        totalWeight += key[u];

        // update keys of adjacent vertices
        for (int v = 1; v <= n; v++) {
            if (adj[u][v] && !inMST[v] && adj[u][v] < key[v]) {
                key[v] = adj[u][v];
                parent[v] = u;
            }
        }
    }

    return totalWeight;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // initialize adjacency matrix
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            adj[i][j] = 0;
        }
    }

    // read edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
        adj[v][u] = w;  // undirected graph
    }

    int result = primMST(n);
    printf("%d\n", result);

    return 0;
}



