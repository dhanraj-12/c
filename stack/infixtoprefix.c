#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack structure for characters
typedef struct {
    char items[MAX];
    int top;
} Stack;

// Initialize the stack
void init(Stack *s) {
    s->top = -1;
}

// Check if the stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Check if the stack is full
int isFull(Stack *s) {
    return s->top == MAX - 1;
}

// Push an element to the stack
void push(Stack *s, char value) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->items[++(s->top)] = value;
}

// Pop an element from the stack
char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return '\0';
    }
    return s->items[(s->top)--];
}

// Peek at the top element of the stack
char peek(Stack *s) {
    if (isEmpty(s)) {
        return '\0';
    }
    return s->items[s->top];
}

// Function to check if a character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Function to return precedence of operators
int precedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

// Function to reverse a string
void reverse(char *exp) {
    int length = strlen(exp);
    for (int i = 0; i < length / 2; i++) {
        char temp = exp[i];
        exp[i] = exp[length - 1 - i];
        exp[length - 1 - i] = temp;
    }
}

// Function to convert infix to postfix
void infixToPostfix(char infix[], char postfix[]) {
    Stack s;
    init(&s);
    int k = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        // If the character is an operand, add it to the result
        if (isalnum(ch)) {
            postfix[k++] = ch;
        }
        // If the character is '(', push it to the stack
        else if (ch == '(') {
            push(&s, ch);
        }
        // If the character is ')', pop and add to the result until '(' is encountered
        else if (ch == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[k++] = pop(&s);
            }
            pop(&s);  // Pop '('
        }
        // If the character is an operator
        else if (isOperator(ch)) {
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(ch)) {
                postfix[k++] = pop(&s);
            }
            push(&s, ch);
        }
    }

    // Pop all remaining operators in the stack
    while (!isEmpty(&s)) {
        postfix[k++] = pop(&s);
    }
    postfix[k] = '\0';  // Null-terminate the postfix expression
}

// Function to convert infix to prefix
void infixToPrefix(char infix[], char prefix[]) {
    // Step 1: Reverse the infix expression
    reverse(infix);

    // Step 2: Swap '(' with ')' and vice versa
    for (int i = 0; infix[i] != '\0'; i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
        } else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }

    // Step 3: Convert the modified infix to postfix
    char postfix[MAX];
    infixToPostfix(infix, postfix);

    // Step 4: Reverse the postfix expression to get the prefix expression
    reverse(postfix);
    strcpy(prefix, postfix);  // Copy postfix to prefix after reversing
}

int main() {
    char infix[MAX], prefix[MAX];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);

    printf("The prefix expression is: %s\n", prefix);

    return 0;
}
