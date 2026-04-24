// Problem: Implement Selection Sort - Implement the algorithm.


#include <stdio.h>

void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;

    // Move boundary of unsorted subarray one by one
    for (i = 0; i < n - 1; i++) {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // Swap the found minimum element with the first element
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int n, i;
    scanf("%d", &n);
    int arr[n];

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    selectionSort(arr, n);

    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}

