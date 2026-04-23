// Problem: Given a sorted array of integers and a target value x, implement the Lower Bound and Upper Bound operations using Binary Search.

// Lower Bound: The index of the first element in the array that is greater than or equal to x.
// Upper Bound: The index of the first element in the array that is strictly greater than x.


#include <stdio.h>

// Function to find Lower Bound
int lowerBound(int arr[], int n, int x) {
    int left = 0, right = n;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid;
    }
    return left; // First index where arr[index] >= x
}

// Function to find Upper Bound
int upperBound(int arr[], int n, int x) {
    int left = 0, right = n;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] <= x)
            left = mid + 1;
        else
            right = mid;
    }
    return left; // First index where arr[index] > x
}

int main() {
    int n, x;
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &x);

    int lb = lowerBound(arr, n, x);
    int ub = upperBound(arr, n, x);

    printf("%d %d\n", lb, ub);
    return 0;
}

