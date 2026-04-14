// Problem Statement
// Given a string s consisting of lowercase English letters, find and return the first character that does not repeat in the string. If all characters repeat, return '$'.




#include <stdio.h>
#include <string.h>

char firstNonRepeatingChar(char *s) {
    int freq[26] = {0};  // frequency array for lowercase letters
    int i;

    // Count frequency of each character
    for (i = 0; s[i] != '\0'; i++) {
        freq[s[i] - 'a']++;
    }

    // Find the first character with frequency 1
    for (i = 0; s[i] != '\0'; i++) {
        if (freq[s[i] - 'a'] == 1) {
            return s[i];
        }
    }

    return '$';  // if no non-repeating character found
}

int main() {
    char s[100];
    scanf("%s", s);

    char result = firstNonRepeatingChar(s);
    printf("%c\n", result);

    return 0;
}

