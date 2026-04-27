// Problem: Find the integer square root of a given non-negative integer using Binary Search. The integer square root of a number is defined as the greatest integer whose square is less than or equal to the given number.

#include <stdio.h>

int integerSqrt(int n) {
    if (n == 0 || n == 1) return n;

    int left = 0, right = n, ans = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (mid <= n / mid) { // avoid overflow: mid*mid <= n
            ans = mid;        // mid is a candidate
            left = mid + 1;   // search in right half
        } else {
            right = mid - 1;  // search in left half
        }
    }
    return ans;
}

int main() {
    int n;
    scanf("%d", &n);

    int result = integerSqrt(n);
    printf("%d\n", result);

    return 0;
}

