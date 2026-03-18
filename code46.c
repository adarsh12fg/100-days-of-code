// Problem: Level Order Traversal
// Implement the solution for this problem.


#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Queue structure for level order traversal
struct Queue {
    struct Node** arr;
    int front, rear, size;
    int capacity;
};

// Function to create a queue
struct Queue* createQueue(int capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->arr = (struct Node**)malloc(queue->capacity * sizeof(struct Node*));
    return queue;
}

// Check if queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

// Enqueue operation
void enqueue(struct Queue* queue, struct Node* item) {
    if (queue->size == queue->capacity) return; // Queue full
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->arr[queue->rear] = item;
    queue->size++;
}

// Dequeue operation
struct Node* dequeue(struct Queue* queue) {
    if (isEmpty(queue)) return NULL;
    struct Node* item = queue->arr[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

// Level Order Traversal function
void levelOrderTraversal(struct Node* root) {
    if (root == NULL) return;

    struct Queue* queue = createQueue(100); // capacity set to 100
    enqueue(queue, root);

    while (!isEmpty(queue)) {
        struct Node* current = dequeue(queue);
        printf("%d ", current->data);

        if (current->left != NULL)
            enqueue(queue, current->left);
        if (current->right != NULL)
            enqueue(queue, current->right);
    }
}

// Driver program
int main() {
    // Constructing a sample binary tree
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    printf("Level Order Traversal: ");
    levelOrderTraversal(root);

    return 0;
}
