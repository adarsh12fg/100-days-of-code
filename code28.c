// Problem: Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert nodes sequentially and make circular
struct Node* insertNodes(int arr[], int n) {
    struct Node* head = NULL;
    struct Node* tail = NULL;

    for (int i = 0; i < n; i++) {
        struct Node* newNode = createNode(arr[i]);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
     // Make it circular: last node points to head
    if (tail != NULL) {
        tail->next = head;
    }

    return head;
}

// Function to traverse circular linked list
void traverseCircular(struct Node* head, int n) {
    struct Node* temp = head;
    for (int i = 0; i < n; i++) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* head = insertNodes(arr, n);
    traverseCircular(head, n);

    return 0;
}



