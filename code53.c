// Problem Statement:
// Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.



#include <stdio.h>
#include <stdlib.h>

// Define structure for Binary Tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Queue structure for building tree
struct Queue {
    struct Node** arr;
    int front, rear, size;
};

// Create new node
struct Node* newNode(int data) {
    if (data == -1) return NULL;  // NULL marker
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Initialize queue
struct Queue* createQueue(int size) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->arr = (struct Node**)malloc(size * sizeof(struct Node*));
    q->front = q->rear = 0;
    q->size = size;
    return q;
}

// Enqueue
void enqueue(struct Queue* q, struct Node* node) {
    q->arr[q->rear++] = node;
}

// Dequeue
struct Node* dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

// Build tree from level-order input
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = newNode(arr[0]);
    struct Queue* q = createQueue(n);
    enqueue(q, root);

    int i = 1;
    while (i < n) {
        struct Node* curr = dequeue(q);
        if (curr != NULL) {
            // Left child
            curr->left = newNode(arr[i++]);
            if (curr->left) enqueue(q, curr->left);

            if (i < n) {
                // Right child
                curr->right = newNode(arr[i++]);
                if (curr->right) enqueue(q, curr->right);
            }
        }
    }
    return root;
}

// Structure for storing nodes with horizontal distance
struct HDNode {
    struct Node* node;
    int hd;
};

// Map structure for vertical order
struct Map {
    int hd;
    int values[100];
    int count;
};

// Recursive function to fill vertical order
void fillVertical(struct Node* root, int hd, struct Map maps[], int* size) {
    if (root == NULL) return;

    // Find if hd already exists
    int idx = -1;
    for (int i = 0; i < *size; i++) {
        if (maps[i].hd == hd) {
            idx = i;
            break;
        }
    }

    // If not found, create new entry
    if (idx == -1) {
        idx = (*size)++;
        maps[idx].hd = hd;
        maps[idx].count = 0;
    }

    maps[idx].values[maps[idx].count++] = root->data;

    // Recurse left and right
    fillVertical(root->left, hd - 1, maps, size);
    fillVertical(root->right, hd + 1, maps, size);
}

// Sort maps by hd
void sortMaps(struct Map maps[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (maps[i].hd > maps[j].hd) {
                struct Map temp = maps[i];
                maps[i] = maps[j];
                maps[j] = temp;
            }
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);

    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, N);

    struct Map maps[100];
    int size = 0;

    fillVertical(root, 0, maps, &size);
    sortMaps(maps, size);

    // Print vertical order
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < maps[i].count; j++) {
            printf("%d ", maps[i].values[j]);
        }
        printf("\n");
    }

    return 0;
}

