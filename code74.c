// Problem Statement
// Given an array of candidate names where each name represents a vote cast for that candidate, determine the candidate who received the maximum number of votes. In case of a tie, return the lexicographically smallest candidate name.




#include <stdio.h>
#include <string.h>

#define MAX 1000   // maximum number of votes
#define LEN 50     // maximum length of candidate name

// Function to find the winner
void findWinner(char votes[][LEN], int n) {
    char candidates[MAX][LEN];
    int count[MAX];
    int unique = 0;

    // Count votes
    for (int i = 0; i < n; i++) {
        int found = -1;
        for (int j = 0; j < unique; j++) {
            if (strcmp(candidates[j], votes[i]) == 0) {
                found = j;
                break;
            }
        }
        if (found != -1) {
            count[found]++;
        } else {
            strcpy(candidates[unique], votes[i]);
            count[unique] = 1;
            unique++;
        }
    }

    // Find max votes
    int maxVotes = 0;
    char winner[LEN];
    for (int i = 0; i < unique; i++) {
        if (count[i] > maxVotes) {
            maxVotes = count[i];
            strcpy(winner, candidates[i]);
        } else if (count[i] == maxVotes) {
            if (strcmp(candidates[i], winner) < 0) {
                strcpy(winner, candidates[i]);
            }
        }
    }

    printf("%s %d\n", winner, maxVotes);
}

int main() {
    int n;
    scanf("%d", &n);

    char votes[MAX][LEN];
    for (int i = 0; i < n; i++) {
        scanf("%s", votes[i]);
    }

    findWinner(votes, n);

    return 0;
}


