// Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Node structure for stack
struct Node {
    int data;
    struct Node* next;
};

// Push operation
void push(struct Node** top, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
}

   // Pop operation
int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack underflow\n");
        exit(1);
    }
    struct Node* temp = *top;
    int value = temp->data;
    *top = temp->next;
    free(temp);
    return value;
}

// Function to evaluate postfix expression
int evaluatePostfix(char* expr) {
    struct Node* stack = NULL;
    char* token = strtok(expr, " ");

    while (token != NULL) {
        if (isdigit(token[0])) {
            // Operand → push
            push(&stack, atoi(token));
        } else {
            // Operator → pop two operands
            int val2 = pop(&stack);
            int val1 = pop(&stack);
            int result;

            switch (token[0]) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
                default:
                    printf("Invalid operator\n");
                    exit(1);
            }
            push(&stack, result);
        }
        token = strtok(NULL, " ");
    }

    return pop(&stack); // Final result
}

int main() {
    char expr[100];
    printf("Enter postfix expression: ");
    fgets(expr, sizeof(expr), stdin);

    // Remove newline if present
    expr[strcspn(expr, "\n")] = '\0';

    int result = evaluatePostfix(expr);
    printf("Result: %d\n", result);

    return 0;
}



