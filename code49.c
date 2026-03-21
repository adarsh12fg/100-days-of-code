// Problem: BST Insert

// Implement the solution for this problem.


#include <stdio.h>
#include <stdlib.h>

// Define BST node
struct Node {
    int key;
    struct Node *left, *right;
};

// Create new node
struct Node* newNode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

// Insert into BST
struct Node* insert(struct Node* root, int key) {
    if (root == NULL) return newNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);

    return root;
}

// Inorder traversal
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

int main() {
    int n, i, key;
    scanf("%d", &n);

    struct Node* root = NULL;
    for (i = 0; i < n; i++) {
        scanf("%d", &key);
        root = insert(root, key);
    }

    inorder(root);
    return 0;
}



