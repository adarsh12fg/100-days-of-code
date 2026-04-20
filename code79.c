// Problem Statement
// Find shortest distances from source vertex in a weighted graph with non-negative weights.


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXN 100005
#define INF INT_MAX

// Structure for adjacency list node
typedef struct Node {
    int v, w;
    struct Node* next;
} Node;

// Structure for adjacency list
Node* adj[MAXN];

// Min-heap node
typedef struct HeapNode {
    int v, dist;
} HeapNode;

// Min-heap
HeapNode heap[MAXN];
int heapSize;

// Function to add edge
void addEdge(int u, int v, int w) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->v = v;
    newNode->w = w;
    newNode->next = adj[u];
    adj[u] = newNode;
}

// Swap heap nodes
void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify up
void heapifyUp(int idx) {
    while (idx > 1 && heap[idx].dist < heap[idx/2].dist) {
        swap(&heap[idx], &heap[idx/2]);
        idx /= 2;
    }
}

// Heapify down
void heapifyDown(int idx) {
    int smallest = idx;
    int left = 2*idx, right = 2*idx+1;
    if (left <= heapSize && heap[left].dist < heap[smallest].dist) smallest = left;
    if (right <= heapSize && heap[right].dist < heap[smallest].dist) smallest = right;
    if (smallest != idx) {
        swap(&heap[idx], &heap[smallest]);
        heapifyDown(smallest);
    }
}

// Push into heap
void push(int v, int dist) {
    heapSize++;
    heap[heapSize].v = v;
    heap[heapSize].dist = dist;
    heapifyUp(heapSize);
}

// Pop from heap
HeapNode pop() {
    HeapNode top = heap[1];
    heap[1] = heap[heapSize];
    heapSize--;
    heapifyDown(1);
    return top;
}

// Dijkstra’s algorithm
void dijkstra(int n, int source) {
    int dist[n+1];
    for (int i = 1; i <= n; i++) dist[i] = INF;
    dist[source] = 0;
    heapSize = 0;
    push(source, 0);

    while (heapSize > 0) {
        HeapNode node = pop();
        int u = node.v;
        int d = node.dist;
        if (d > dist[u]) continue;

        for (Node* p = adj[u]; p != NULL; p = p->next) {
            int v = p->v, w = p->w;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(v, dist[v]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) printf("INF ");
        else printf("%d ", dist[i]);
    }
    printf("\n");
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
        addEdge(v, u, w); // If graph is undirected, keep this line. Remove for directed.
    }
    int source;
    scanf("%d", &source);
    dijkstra(n, source);
    return 0;
}

