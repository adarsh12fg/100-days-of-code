// Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.


#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Queue structure
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Initialize queue
void initQueue(struct Queue* q) {
    q->front = q->rear = NULL;
}

// Enqueue operation
void enqueue(struct Queue* q, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;

    if (q->front == NULL) {
        q->front = q->rear = newNode;
        q->rear->next = q->front; // circular link
    } else {
    q->rear->next = newNode;
        q->rear = newNode;
        q->rear->next = q->front; // maintain circularity
    }
}

// Dequeue operation
int dequeue(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue underflow\n");
        exit(1);
    }

    int value;
    if (q->front == q->rear) {
        value = q->front->data;
        free(q->front);
        q->front = q->rear = NULL;
    } else {
        struct Node* temp = q->front;
        value = temp->data;
        q->front = q->front->next;
        q->rear->next = q->front; // maintain circularity
        free(temp);
    }
    return value;
}
// Display queue elements
void display(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct Node* temp = q->front;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != q->front);
    printf("\n");
}

int main() {
    struct Queue q;
    initQueue(&q);

    int n, m, value;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        enqueue(&q, value);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        dequeue(&q);
    }

    display(&q);

    return 0;
}






