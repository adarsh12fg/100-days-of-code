// Problem: Implement a stack data structure using an array with the following operations: push, pop, and display.


#include <stdio.h>
#define MAX 100   // maximum size of stack

int stack[MAX];
int top = -1;

// Function to push an element
void push(int val) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = val;
    }
}

// Function to pop an element
void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
    } else {
        printf("%d\n", stack[top--]);
    }
}

// Function to display stack elements
void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int n, choice, val;
    scanf("%d", &n);   // number of operations

    for (int i = 0; i < n; i++) {
        scanf("%d", &choice);
        if (choice == 1) {
            scanf("%d", &val);
            push(val);
        } else if (choice == 2) {
            pop();
        } else if (choice == 3) {
            display();
        }
    }
    return 0;
}

