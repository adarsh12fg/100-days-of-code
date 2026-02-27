// Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.


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

// Function to insert nodes sequentially
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
    return head;
}

// Function to calculate length of linked list
int getLength(struct Node* head) {
    int length = 0;
    while (head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}

// Function to find intersection point
int findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    // Advance longer list by difference
    int diff = abs(len1 - len2);
    if (len1 > len2) {
        for (int i = 0; i < diff; i++) head1 = head1->next;
    } else {
        for (int i = 0; i < diff; i++) head2 = head2->next;
    }

    // Traverse both simultaneously
    while (head1 != NULL && head2 != NULL) {
        if (head1->data == head2->data) {
            return head1->data; // Intersection found
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return -1; // No intersection
}


int main() {
    int n, m;
    scanf("%d", &n);
    int arr1[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr1[i]);

    scanf("%d", &m);
    int arr2[m];
    for (int i = 0; i < m; i++) scanf("%d", &arr2[i]);

    struct Node* head1 = insertNodes(arr1, n);
    struct Node* head2 = insertNodes(arr2, m);

    int result = findIntersection(head1, head2);
    if (result != -1)
        printf("%d\n", result);
    else
        printf("No Intersection\n");

    return 0;
}

