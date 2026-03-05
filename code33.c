// Problem: Convert an infix expression to postfix notation using stack.



#include <stdio.h>
#include <ctype.h>   // for isalnum()
#include <string.h>  // for strlen()

#define MAX 100

char stack[MAX];
int top = -1;

// Push to stack
void push(char c) {
    stack[++top] = c;
}

// Pop from stack
char pop() {
    return stack[top--];
}

// Peek top of stack
char peek() {
    return stack[top];
}

// Check if stack is empty
int isEmpty() {
    return top == -1;
}
// Operator precedence
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// Associativity: returns 1 if right-associative
int isRightAssociative(char op) {
    return (op == '^');
}

// Convert infix to postfix
void infixToPostfix(char* infix) {
    char postfix[MAX];
    int k = 0;

    for (int i = 0; i < strlen(infix); i++) {
        char c = infix[i];

        // If operand → add to postfix
        if (isalnum(c)) {
            postfix[k++] = c;
        }
        // If '(' → push
        else if (c == '(') {
            push(c);
        }
        // If ')' → pop until '('
        else if (c == ')') {
            while (!isEmpty() && peek() != '(') {
                postfix[k++] = pop();
            }
            pop(); // remove '('
        }
        // If operator
        else {
            while (!isEmpty() && precedence(peek()) > precedence(c)) {
                postfix[k++] = pop();
            }
            // Handle equal precedence with associativity
            while (!isEmpty() && precedence(peek()) == precedence(c) && !isRightAssociative(c)) {
                postfix[k++] = pop();
            }
            push(c);
        }
    }

    // Pop remaining operators
    while (!isEmpty()) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';
    printf("%s\n", postfix);
}

int main() {
    char infix[MAX];
    scanf("%s", infix);
    infixToPostfix(infix);
    return 0;
}




