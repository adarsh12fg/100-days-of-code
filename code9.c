// Problem: A secret system stores code names in forward order. To display them in mirror format, you must transform the given code name so that its characters appear in the opposite order.

#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    scanf("%s", str);  // Input string (no spaces)

    int len = strlen(str);

    // Print characters in reverse order
    for (int i = len - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }

    return 0;
}

