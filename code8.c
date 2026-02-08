// Problem: Given integers a and b, compute a^b using recursion without using pow() function.


#include <stdio.h>

// Recursive function to calculate a^b
int power(int a, int b) {
    // Base case: anything raised to 0 is 1
    if (b == 0)
        return 1;
    // Recursive case: a^b = a * a^(b-1)
    return a * power(a, b - 1);
}

int main() {
    int a, b;
    // Input
    scanf("%d %d", &a, &b);

    // Output
    printf("%d\n", power(a, b));

    return 0;
}


