// Problem: Count Leaf Nodes

// Implement the solution for this problem.


#include <stdio.h>
#include <stdlib.h>

// Define structure for a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to count leaf nodes
int countLeafNodes(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1; // Leaf node
    }
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int main() {
    int n, value;
    struct Node* root = NULL;

    // Input number of nodes
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Input node values
    printf("Enter node values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    // Output number of leaf nodes
    printf("Number of leaf nodes: %d\n", countLeafNodes(root));

    return 0;
}



