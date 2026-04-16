// Problem Statement
// Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.





#include <stdio.h>
#include <stdlib.h>

// A structure for hash map node
struct HashNode {
    int sum;
    int index;
    struct HashNode* next;
};

// Hash map size
#define TABLE_SIZE 1000

// Hash function
int hash(int sum) {
    return abs(sum) % TABLE_SIZE;
}

// Insert into hash map
void insert(struct HashNode* table[], int sum, int index) {
    int h = hash(sum);
    struct HashNode* newNode = (struct HashNode*)malloc(sizeof(struct HashNode));
    newNode->sum = sum;
    newNode->index = index;
    newNode->next = table[h];
    table[h] = newNode;
}

// Search in hash map
int search(struct HashNode* table[], int sum) {
    int h = hash(sum);
    struct HashNode* temp = table[h];
    while (temp) {
        if (temp->sum == sum)
            return temp->index;
        temp = temp->next;
    }
    return -1;
}

// Function to find length of longest subarray with sum 0
int longestZeroSumSubarray(int arr[], int n) {
    struct HashNode* table[TABLE_SIZE] = {NULL};
    int sum = 0;
    int maxLen = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum == 0) {
            if (i + 1 > maxLen)
                maxLen = i + 1;
        }

        int prevIndex = search(table, sum);
        if (prevIndex != -1) {
            if (i - prevIndex > maxLen)
                maxLen = i - prevIndex;
        } else {
            insert(table, sum, i);
        }
    }
    return maxLen;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = longestZeroSumSubarray(arr, n);
    printf("%d\n", result);

    return 0;
}

