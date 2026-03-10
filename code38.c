// Problem: Deque (Double-Ended Queue)
// A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Deque {
    struct Node* front;
    struct Node* rear;
    int size;
};

void initDeque(struct Deque* dq) { dq->front = dq->rear = NULL; dq->size = 0; }

void push_front(struct Deque* dq, int x) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = x; n->prev = NULL; n->next = dq->front;
    if (dq->front) dq->front->prev = n; dq->front = n;
    if (!dq->rear) dq->rear = n; dq->size++;
}

void push_back(struct Deque* dq, int x) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = x; n->next = NULL; n->prev = dq->rear;
    if (dq->rear) dq->rear->next = n; dq->rear = n;
    if (!dq->front) dq->front = n; dq->size++;
}
int pop_front(struct Deque* dq) {
    if (!dq->front) return -1;
    struct Node* t = dq->front; int v = t->data;
    dq->front = dq->front->next; if (dq->front) dq->front->prev = NULL; else dq->rear = NULL;
    free(t); dq->size--; return v;
}

int pop_back(struct Deque* dq) {
    if (!dq->rear) return -1;
    struct Node* t = dq->rear; int v = t->data;
    dq->rear = dq->rear->prev; if (dq->rear) dq->rear->next = NULL; else dq->front = NULL;
    free(t); dq->size--; return v;
}

int front(struct Deque* dq) { return dq->front ? dq->front->data : -1; }
int back(struct Deque* dq) { return dq->rear ? dq->rear->data : -1; }
int empty(struct Deque* dq) { return dq->size == 0; }
int size(struct Deque* dq) { return dq->size; }

void display(struct Deque* dq) {
    struct Node* t = dq->front;
    while (t) { printf("%d ", t->data); t = t->next; }
    printf("\n");
}

int main() {
    struct Deque dq; initDeque(&dq);
    push_back(&dq, 10); push_front(&dq, 20); push_back(&dq, 30);
    display(&dq);               // 20 10 30
    printf("Front=%d Back=%d Size=%d\n", front(&dq), back(&dq), size(&dq));
    pop_front(&dq); pop_back(&dq);
    display(&dq);               // 10
    return 0;
}

