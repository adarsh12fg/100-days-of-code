// Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).


#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Node structure for adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Graph structure
struct Graph {
    int numVertices;
    struct Node** adjLists;
    int* inDegree;
};

// Create a node
struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Create a graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(struct Node*));
    graph->inDegree = malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->inDegree[i] = 0;
    }
    return graph;
}

// Add edge (directed graph)
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    graph->inDegree[dest]++; // increase in-degree of destination
}

// Queue implementation
struct Queue {
    int items[MAX];
    int front, rear;
};

struct Queue* createQueue() {
    struct Queue* q = malloc(sizeof(struct Queue));
    q->front = 0;
    q->rear = -1;
    return q;
}

int isEmpty(struct Queue* q) {
    return q->rear < q->front;
}

void enqueue(struct Queue* q, int value) {
    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(struct Queue* q) {
    int item = q->items[q->front];
    q->front++;
    return item;
}

// Topological Sort using Kahn's Algorithm
void topologicalSort(struct Graph* graph) {
    struct Queue* q = createQueue();

    // Enqueue all vertices with in-degree 0
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->inDegree[i] == 0) {
            enqueue(q, i);
        }
    }

    int count = 0; // count of visited vertices

    printf("Topological Ordering:\n");
    while (!isEmpty(q)) {
        int v = dequeue(q);
        printf("%d ", v);
        count++;

        // Reduce in-degree of neighbors
        struct Node* temp = graph->adjLists[v];
        while (temp) {
            int adjVertex = temp->vertex;
            graph->inDegree[adjVertex]--;
            if (graph->inDegree[adjVertex] == 0) {
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }

    // If count != numVertices → cycle exists
    if (count != graph->numVertices) {
        printf("\nGraph has a cycle, topological ordering not possible.\n");
    }
}

int main() {
    int n, e;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    struct Graph* graph = createGraph(n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v) for directed graph:\n");
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    topologicalSort(graph);

    return 0;
}

