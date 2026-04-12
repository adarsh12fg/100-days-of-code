// Problem Statement
// Implement a hash table using quadratic probing with formula:

// h(k, i) = (h(k) + i*i) % m




#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EMPTY -1

int m; // table size
int *table;

// Hash function
int hash(int key) {
    return key % m;
}

// Insert function
void insert(int key) {
    int h = hash(key);
    for (int i = 0; i < m; i++) {
        int pos = (h + i * i) % m;
        if (table[pos] == EMPTY) {
            table[pos] = key;
            return;
        }
    }
    printf("Table is full, cannot insert %d\n", key);
}

// Search function
void search(int key) {
    int h = hash(key);
    for (int i = 0; i < m; i++) {
        int pos = (h + i * i) % m;
        if (table[pos] == key) {
            printf("FOUND\n");
            return;
        }
        if (table[pos] == EMPTY) break; // stop if empty slot
    }
    printf("NOT FOUND\n");
}

int main() {
    int n; // number of operations
    scanf("%d", &m);
    scanf("%d", &n);

    table = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) table[i] = EMPTY;

    char op[10];
    int key;
    for (int i = 0; i < n; i++) {
        scanf("%s %d", op, &key);
        if (strcmp(op, "INSERT") == 0) {
            insert(key);
        } else if (strcmp(op, "SEARCH") == 0) {
            search(key);
        }
    }

    free(table);
    return 0;
}



