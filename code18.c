// Problem: Given an array of integers, rotate the array to the right by k positions.



#include <stdio.h>

int main() {
    int n, k;

    // Input size of array
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input k
    scanf("%d", &k);

    // Normalize k (in case k > n)
    k = k % n;

    // Temporary array to store rotated result
    int rotated[n];

    // Place elements in rotated positions
    for (int i = 0; i < n; i++) {
        rotated[(i + k) % n] = arr[i];
    }

    // Print rotated array
    for (int i = 0; i < n; i++) {
        printf("%d ", rotated[i]);
    }

    return 0;
}

