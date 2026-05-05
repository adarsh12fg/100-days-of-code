// Problem: For each element, count how many smaller elements appear on right side.
// Use merge sort technique or Fenwick Tree (BIT).


#include <stdio.h>
#include <stdlib.h>

// Merge function that counts smaller elements on right
void merge(int arr[], int counts[], int left, int mid, int right, int temp[]) {
    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            counts[i] += (j - mid - 1); // elements already moved from right side
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    while (i <= mid) {
        temp[k] = arr[i];
        counts[i] += (j - mid - 1);
        i++; k++;
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }
    for (i = left; i <= right; i++) arr[i] = temp[i];
}

void mergeSort(int arr[], int counts[], int left, int right, int temp[]) {
    if (left >= right) return;
    int mid = (left + right) / 2;
    mergeSort(arr, counts, left, mid, temp);
    mergeSort(arr, counts, mid + 1, right, temp);
    merge(arr, counts, left, mid, right, temp);
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n], counts[n], temp[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        counts[i] = 0;
    }

    mergeSort(arr, counts, 0, n - 1, temp);

    // Print counts for each element
    for (int i = 0; i < n; i++) {
        printf("%d ", counts[i]);
    }
    printf("\n");
    return 0;
}

