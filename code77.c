// Problem Statement
// Using BFS or DFS, check if the entire graph is connected.


#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int adj[MAX][MAX];   // adjacency matrix
int visited[MAX];
int queue[MAX];
int front = -1, rear = -1;

void enqueue(int v) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = v;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

void bfs(int start, int n) {
    enqueue(start);
    visited[start] = 1;

    while (front <= rear) {
        int node = dequeue();
        for (int i = 1; i <= n; i++) {
            if (adj[node][i] && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // initialize adjacency matrix
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            adj[i][j] = 0;
        }
        visited[i] = 0;
    }

    // read edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;  // undirected graph
    }

    // run BFS from node 1
    bfs(1, n);

    // check if all nodes are visited
    int connected = 1;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            connected = 0;
            break;
        }
    }

    if (connected)
        printf("CONNECTED\n");
    else
        printf("NOT CONNECTED\n");

    return 0;
}


