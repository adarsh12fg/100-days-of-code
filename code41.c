// Problem Statement:
// Implement a Queue using a linked list supporting enqueue and dequeue operations.





#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL, *rear = NULL;

// Enqueue operation
void enqueue(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    if (rear == NULL) {
        front = rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }
}

// Dequeue operation
int dequeue() {
    if (front == NULL) return -1;
    int val = front->data;
    struct Node* temp = front;
    front = front->next;
    if (front == NULL) rear = NULL;
    free(temp);
    return val;
}

int main() {
    int N;
    scanf("%d", &N);
    while (N--) {
        char op[20];
        scanf("%s", op);
        if (strcmp(op, "enqueue") == 0) {
            int x;
            scanf("%d", &x);
            enqueue(x);
        } else if (strcmp(op, "dequeue") == 0) {
            printf("%d\n", dequeue());
        }
    }
    return 0;
}



