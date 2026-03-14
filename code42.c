// Problem Statement:
// Given a queue of integers, reverse the queue using a stack.


#include <stdio.h>
#include <stdlib.h>

// Queue using linked list
struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL, *rear = NULL;

// Enqueue
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

// Dequeue
int dequeue() {
    if (front == NULL) return -1;
    int val = front->data;
    struct Node* temp = front;
    front = front->next;
    if (front == NULL) rear = NULL;
    free(temp);
    return val;
}

// Stack using array
void push(int stack[], int *top, int x) {
    stack[++(*top)] = x;
}

int pop(int stack[], int *top) {
    return stack[(*top)--];
}

int main() {
    int N;
    scanf("%d", &N);
    int x;
    for (int i = 0; i < N; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    // Transfer queue elements to stack
    int stack[N], top = -1;
    while (front != NULL) {
        push(stack, &top, dequeue());
    }

    // Pop from stack to print reversed queue
    while (top != -1) {
        printf("%d ", pop(stack, &top));
    }
    return 0;
}



