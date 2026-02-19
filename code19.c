// Problem: Given an array of integers, find two elements whose sum is closest to zero.


#include <stdio.h>
#include <stdlib.h>

// Function to compare for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array
    qsort(arr, n, sizeof(int), compare);

    int left = 0, right = n - 1;
    int minSum = __INT_MAX__;
    int ansLeft = left, ansRight = right;

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (abs(sum) < abs(minSum)) {
            minSum = sum;
            ansLeft = left;
            ansRight = right;
        }

        if (sum < 0)
            left++;
        else
            right--;
    }

    printf("%d %d\n", arr[ansLeft], arr[ansRight]);

    return 0;
}


