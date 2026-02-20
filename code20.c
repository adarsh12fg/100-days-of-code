// Problem: Given an array of integers, count the number of subarrays whose sum is equal to zero.






#include <stdio.h>
#include <stdlib.h>

// Hash map node
typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

// Simple hash function
int hash(int key, int size) {
    return (key % size + size) % size;
}

// Insert or update key in hash map
void insert(Node** table, int size, int key) {
    int h = hash(key, size);
    Node* curr = table[h];
    while (curr) {
        if (curr->key == key) {
            curr->value++;
            return;
        }
        curr = curr->next;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = 1;
    newNode->next = table[h];
    table[h] = newNode;
}

// Get frequency of key
int get(Node** table, int size, int key) {
    int h = hash(key, size);
    Node* curr = table[h];
    while (curr) {
        if (curr->key == key) return curr->value;
        curr = curr->next;
    }
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    int size = 10007; // hash table size
    Node** table = (Node**)calloc(size, sizeof(Node*));

    int prefixSum = 0, count = 0;
    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        // If prefix sum is zero, subarray [0..i] has sum zero
        if (prefixSum == 0) count++;

        // If prefix sum seen before, add its frequency
        count += get(table, size, prefixSum);

        // Insert/update prefix sum in hash map
        insert(table, size, prefixSum);
    }

    printf("%d\n", count);
    return 0;
}



