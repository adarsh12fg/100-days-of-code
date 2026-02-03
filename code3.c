//Problem: Implement linear search to find key k in an array. Count and display the number of comparisons performed.

#include <stdio.h>

int main() {
    int n, k, comparisons = 0, found = -1;

    // Read size of array
    scanf("%d", &n);

    int arr[n];

    // Read array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Read key to search
    scanf("%d", &k);

    // Linear search
    for (int i = 0; i < n; i++) {
        comparisons++;
        if (arr[i] == k) {
            found = i; // store index if found
            break;
        }
    }

    // Output result
    if (found != -1) {
        printf("Found at index %d\n", found);
    } else {
        printf("Not Found\n");
    }
    printf("Comparisons = %d\n", comparisons);

    return 0;
}

