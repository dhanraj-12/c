#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Stack structure
char stack[MAX];
int top = -1;

// Function to push an element onto the stack
void push(char c) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = c;
    }
}

// Function to pop an element from the stack
char pop() {
    if (top == -1) {
        return '\0'; // Stack is empty
    } else {
        return stack[top--];
    }
}

// Function to check if the parentheses are valid
int isValidParentheses(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];

        // If it's an opening parenthesis, push to stack
        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        }
        // If it's a closing parenthesis, check if it matches the top of the stack
        else if (ch == ')' || ch == '}' || ch == ']') {
            char topChar = pop();
            if ((ch == ')' && topChar != '(') || (ch == '}' && topChar != '{') || (ch == ']' && topChar != '[')) {
                return 0; // Mismatched parentheses
            }
        }
    }

    // If stack is empty, parentheses are balanced
    return top == -1;
}

int main() {
    char str[100];

    // Input the string with parentheses
    printf("Enter a string with parentheses: ");
    fgets(str, sizeof(str), stdin);

    // Check if the parentheses are valid
    if (isValidParentheses(str)) {
        printf("The parentheses are valid.\n");
    } else {
        printf("The parentheses are not valid.\n");
    }

    return 0;
}
