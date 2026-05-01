// Problem Statement
// Given n boards of different lengths and k painters, each painter paints contiguous boards. Painting a unit length of board takes one unit of time.

// Determine the minimum time required to paint all boards.





#include <stdio.h>

// Function to check if allocation is possible
int isPossible(int boards[], int n, int k, int maxTime) {
    int painters = 1;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        if (boards[i] > maxTime) return 0; // single board exceeds limit

        if (sum + boards[i] > maxTime) {
            painters++;
            sum = boards[i];
            if (painters > k) return 0; // too many painters needed
        } else {
            sum += boards[i];
        }
    }
    return 1;
}

// Function to find minimum time
int minTime(int boards[], int n, int k) {
    int low = boards[0], high = 0;
    for (int i = 0; i < n; i++) {
        if (boards[i] > low) low = boards[i];
        high += boards[i];
    }

    int result = high;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (isPossible(boards, n, k, mid)) {
            result = mid;
            high = mid - 1; // try smaller maximum
        } else {
            low = mid + 1;  // increase limit
        }
    }
    return result;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int boards[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
    }

    int ans = minTime(boards, n, k);
    printf("%d\n", ans);

    return 0;
}


