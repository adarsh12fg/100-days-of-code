// Problem Statement
// Given a string s consisting of lowercase letters, find the first repeated character in the string. A character is considered repeated if it appears more than once, and among all such characters, the one whose second occurrence has the smallest index should be returned.

#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    scanf("%s", s);

    int freq[26] = {0};  // frequency array for lowercase letters

    for (int i = 0; i < strlen(s); i++) {
        freq[s[i] - 'a']++;
        if (freq[s[i] - 'a'] == 2) {  // second occurrence found
            printf("%c\n", s[i]);
            return 0;
        }
    }

    printf("-1\n");  // no repeated character
    return 0;
}

