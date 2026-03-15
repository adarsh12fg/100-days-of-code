// Problem Statement:
// Construct a Binary Tree from the given level-order traversal.


#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Queue for building tree
struct QNode {
    struct Node* node;
    struct QNode* next;
};

struct QNode *front = NULL, *rear = NULL;

void enqueue(struct Node* node) {
    struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode));
    temp->node = node;
    temp->next = NULL;
    if (rear == NULL) {
        front = rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }
}

struct Node* dequeue() {
    if (front == NULL) return NULL;
    struct QNode* temp = front;
    struct Node* node = temp->node;
    front = front->next;
    if (front == NULL) rear = NULL;
    free(temp);
    return node;
}

// Inorder traversal
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    int N;
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);

    if (N == 0 || arr[0] == -1) return 0;

    // Create root
    struct Node* root = (struct Node*)malloc(sizeof(struct Node));
    root->data = arr[0];
    root->left = root->right = NULL;
    enqueue(root);

    int i = 1;
    while (i < N) {
        struct Node* parent = dequeue();
        if (parent == NULL) continue;

        // Left child
        if (arr[i] != -1) {
            struct Node* leftChild = (struct Node*)malloc(sizeof(struct Node));
            leftChild->data = arr[i];
            leftChild->left = leftChild->right = NULL;
            parent->left = leftChild;
            enqueue(leftChild);
        }
        i++;

        // Right child
        if (i < N && arr[i] != -1) {
            struct Node* rightChild = (struct Node*)malloc(sizeof(struct Node));
            rightChild->data = arr[i];
            rightChild->left = rightChild->right = NULL;
            parent->right = rightChild;
            enqueue(rightChild);
        }
        i++;
    }

    inorder(root);
    return 0;
}

