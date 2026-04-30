// Problem Statement
// Given an array of integers where each element represents the number of pages in a book, and m students, allocate books such that each student gets at least one book and the maximum number of pages assigned to a student is minimized.


#include <stdio.h>

// Function to check if allocation is possible with given maxPages
int isPossible(int arr[], int n, int m, int maxPages) {
    int students = 1;   // start with first student
    int sum = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxPages)
            return 0; // single book exceeds maxPages → not possible

        if (sum + arr[i] > maxPages) {
            students++;     // allocate to next student
            sum = arr[i];   // reset sum for new student
            if (students > m)
                return 0;   // more students needed than allowed
        } else {
            sum += arr[i];
        }
    }
    return 1;
}

// Function to find minimum possible maximum pages
int allocateBooks(int arr[], int n, int m) {
    if (m > n) return -1; // not enough books

    int low = arr[0], high = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < low) low = arr[i];
        high += arr[i]; // sum of all pages
    }

    int result = -1;
    while (low <= high) {
        int mid = (low + high) / 2;

        if (isPossible(arr, n, m, mid)) {
            result = mid;
            high = mid - 1; // try smaller maximum
        } else {
            low = mid + 1;  // increase limit
        }
    }
    return result;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int ans = allocateBooks(arr, n, m);
    printf("%d\n", ans);

    return 0;
}



