// Problem: Given meeting intervals, find minimum number of rooms required.
// Sort by start time and use min-heap on end times.



#include <stdio.h>
#include <stdlib.h>

// Min-heap for end times
typedef struct {
    int *arr;
    int size;
    int capacity;
} MinHeap;

MinHeap* createHeap(int capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->arr = (int*)malloc(sizeof(int) * capacity);
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void swap(int *a, int *b) {
    int temp = *a; *a = *b; *b = temp;
}

void heapifyUp(MinHeap* heap, int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap->arr[parent] > heap->arr[i]) {
            swap(&heap->arr[parent], &heap->arr[i]);
            i = parent;
        } else break;
    }
}

void heapifyDown(MinHeap* heap, int i) {
    int left = 2*i + 1, right = 2*i + 2, smallest = i;
    if (left < heap->size && heap->arr[left] < heap->arr[smallest]) smallest = left;
    if (right < heap->size && heap->arr[right] < heap->arr[smallest]) smallest = right;
    if (smallest != i) {
        swap(&heap->arr[i], &heap->arr[smallest]);
        heapifyDown(heap, smallest);
    }
}

void push(MinHeap* heap, int val) {
    heap->arr[heap->size++] = val;
    heapifyUp(heap, heap->size - 1);
}

int pop(MinHeap* heap) {
    int root = heap->arr[0];
    heap->arr[0] = heap->arr[--heap->size];
    heapifyDown(heap, 0);
    return root;
}

int top(MinHeap* heap) {
    return heap->arr[0];
}

// Comparator for sorting intervals by start time
int cmp(const void *a, const void *b) {
    int *x = (int*)a;
    int *y = (int*)b;
    return x[0] - y[0];
}

// Function to find minimum rooms
int minMeetingRooms(int intervals[][2], int n) {
    qsort(intervals, n, sizeof(intervals[0]), cmp);

    MinHeap* heap = createHeap(n);
    push(heap, intervals[0][1]); // first meeting end time

    for (int i = 1; i < n; i++) {
        if (intervals[i][0] >= top(heap)) {
            pop(heap); // reuse room
        }
        push(heap, intervals[i][1]); // allocate room
    }

    int result = heap->size;
    free(heap->arr);
    free(heap);
    return result;
}

int main() {
    int n;
    scanf("%d", &n);
    int intervals[n][2];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &intervals[i][0], &intervals[i][1]);
    }

    printf("%d\n", minMeetingRooms(intervals, n));
    return 0;
}

