// Problem: Given intervals, merge all overlapping ones.
// Sort first, then compare with previous.


#include <stdio.h>
#include <stdlib.h>

// Comparator for sorting intervals by start time
int cmp(const void *a, const void *b) {
    int *x = (int*)a;
    int *y = (int*)b;
    return x[0] - y[0];
}

// Function to merge intervals
void mergeIntervals(int intervals[][2], int n) {
    // Step 1: Sort by start time
    qsort(intervals, n, sizeof(intervals[0]), cmp);

    // Step 2: Traverse and merge
    int merged[n][2];
    int idx = 0; // index for merged array

    merged[0][0] = intervals[0][0];
    merged[0][1] = intervals[0][1];

    for (int i = 1; i < n; i++) {
        if (intervals[i][0] <= merged[idx][1]) {
            // Overlap → extend the end time
            if (intervals[i][1] > merged[idx][1])
                merged[idx][1] = intervals[i][1];
        } else {
            // No overlap → move to next slot
            idx++;
            merged[idx][0] = intervals[i][0];
            merged[idx][1] = intervals[i][1];
        }
    }

    // Print merged intervals
    for (int i = 0; i <= idx; i++) {
        printf("%d %d\n", merged[i][0], merged[i][1]);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int intervals[n][2];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &intervals[i][0], &intervals[i][1]);
    }

    mergeIntervals(intervals, n);
    return 0;
}



