//  Problem: Create and Traverse Singly Linked List

#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to traverse and print the linked list
void traverseList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int n, i, value;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    // Input size
    scanf("%d", &n);

    // Input elements and create linked list
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        newNode = createNode(value);

        if (head == NULL) {
            head = newNode;  // First node
            temp = head;
        } else {
            temp->next = newNode;  // Link new node
            temp = temp->next;
        }
    }

    // Traverse and print

      traverseList(head);

    return 0;
}


