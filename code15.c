// Problem: Given a matrix, calculate the sum of its primary diagonal elements. The primary diagonal consists of elements where row index equals column index.


#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int matrix[m][n];
    int sum = 0;

    // Input matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
            if (i == j) {   // Primary diagonal condition
                sum += matrix[i][j];
            }
        }
    }

    printf("%d\n", sum);

    return 0;
}

