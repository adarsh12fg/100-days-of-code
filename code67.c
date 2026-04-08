// Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.



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
    int* visited;
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
    graph->visited = malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

// Add edge (directed graph)
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

// DFS utility for topological sort
void dfsTopo(struct Graph* graph, int v, int* stack, int* top) {
    graph->visited[v] = 1;

    struct Node* temp = graph->adjLists[v];
    while (temp) {
        int adjVertex = temp->vertex;
        if (!graph->visited[adjVertex]) {
            dfsTopo(graph, adjVertex, stack, top);
        }
        temp = temp->next;
    }

    // push vertex onto stack after visiting neighbors
    stack[++(*top)] = v;
}

// Topological sort wrapper
void topologicalSort(struct Graph* graph) {
    int stack[MAX];
    int top = -1;

    for (int i = 0; i < graph->numVertices; i++) {
        if (!graph->visited[i]) {
            dfsTopo(graph, i, stack, &top);
        }
    }

    printf("Topological Ordering:\n");
    while (top >= 0) {
        printf("%d ", stack[top--]);
    }
    printf("\n");
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


