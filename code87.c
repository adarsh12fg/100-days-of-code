// Problem: Implement Binary Search Iterative - Implement the algorithm.




#include <stdio.h>

// Simple Selection Sort to ensure array is sorted
void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

// Iterative Binary Search
int binarySearch(int arr[], int n, int x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == x)
            return mid; // found
        else if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1; // not found
}

int main() {
    int n, x;
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array first
    selectionSort(arr, n);

    // Print sorted array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Optional: search for a value
    // Uncomment below if you want to test search
    /*
    scanf("%d", &x);
    int result = binarySearch(arr, n, x);
    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");
    */

    return 0;
}



