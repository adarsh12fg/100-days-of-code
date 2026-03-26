// Problem Statement:
// Perform zigzag (spiral) level order traversal of a binary tree. Alternate levels should be traversed left-to-right and right-to-left.



#include <stdio.h>
#include <stdlib.h>

// Define structure for tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Queue structure for level order traversal
struct Queue {
    struct Node **arr;
    int front, rear, size;
};

// Create a new node
struct Node* newNode(int data) {
    if (data == -1) return NULL;
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
    if (node) q->arr[q->rear++] = node;
}

// Dequeue
struct Node* dequeue(struct Queue* q) {
    if (q->front == q->rear) return NULL;
    return q->arr[q->front++];
}

// Check if queue is empty
int isEmpty(struct Queue* q) {
    return q->front == q->rear;
}

// Build tree from level order input
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = newNode(arr[0]);
    struct Queue* q = createQueue(n);
    enqueue(q, root);

    int i = 1;
    while (!isEmpty(q) && i < n) {
        struct Node* curr = dequeue(q);
        if (curr) {
            curr->left = newNode(arr[i++]);
            enqueue(q, curr->left);
            if (i < n) {
                curr->right = newNode(arr[i++]);
                enqueue(q, curr->right);
            }
        }
    }
    return root;
}

// Zigzag traversal
void zigzagTraversal(struct Node* root) {
    if (!root) return;

    struct Queue* q = createQueue(1000);
    enqueue(q, root);

    int level = 0;
    while (!isEmpty(q)) {
        int size = q->rear - q->front;
        int temp[size];
        for (int i = 0; i < size; i++) {
            struct Node* node = dequeue(q);
            temp[i] = node->data;
            if (node->left) enqueue(q, node->left);
            if (node->right) enqueue(q, node->right);
        }

        if (level % 2 == 0) { // left to right
            for (int i = 0; i < size; i++) printf("%d ", temp[i]);
        } else { // right to left
            for (int i = size - 1; i >= 0; i--) printf("%d ", temp[i]);
        }
        level++;
    }
}

int main() {
    int N;
    scanf("%d", &N);

    int arr[N];
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, N);
    zigzagTraversal(root);

    return 0;
}



