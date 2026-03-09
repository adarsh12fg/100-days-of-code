// Problem Statement:Implement a Priority Queue using an array. An element with smaller value has higher priority.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int pq[MAX];   // priority queue array
int size = 0;  // current number of elements

// Insert operation
void insert(int x) {
    if (size == MAX) {
        printf("Queue overflow\n");
        return;
    }
    pq[size++] = x;
}

// Find index of element with highest priority (smallest value)
int getHighestPriorityIndex() {
    if (size == 0) return -1;
    int minIndex = 0;
    for (int i = 1; i < size; i++) {
        if (pq[i] < pq[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

// Delete operation
void delete() {
    if (size == 0) {
        printf("-1\n");
        return;
    }

 int minIndex = getHighestPriorityIndex();
    int deleted = pq[minIndex];
    printf("%d\n", deleted);

    // Shift elements left
    for (int i = minIndex; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }
    size--;
}

// Peek operation
void peek() {
    if (size == 0) {
        printf("-1\n");
        return;
    }
    int minIndex = getHighestPriorityIndex();
    printf("%d\n", pq[minIndex]);
}

int main() {
    int N;
    scanf("%d", &N);
    char operation[20];
    int value;
    for (int i = 0; i < N; i++) {
        scanf("%s", operation);
        if (strcmp(operation, "insert") == 0) {
            scanf("%d", &value);
            insert(value);
        } else if (strcmp(operation, "delete") == 0) {
            delete();
        } else if (strcmp(operation, "peek") == 0) {
            peek();
        }
    }

    return 0;
}





