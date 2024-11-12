#include <stdio.h>
#include <ctype.h> 
#include <stdlib.h>
#include <string.h>

#define MAX 100


typedef struct Stack {
   int top;
   char arr[MAX];
} Stack;


void init(Stack* stack) {
   stack->top = -1;
}


int isEmpty(Stack* stack) {
   return stack->top == -1;
}


int isFull(Stack* stack) {
   return stack->top == MAX - 1;
}


void push(Stack* stack, char c) {
   if (isFull(stack)) {
       printf("Stack overflow\n");
       return;
   }
   stack->arr[++(stack->top)] = c;
}


char pop(Stack* stack) {
   if (isEmpty(stack)) {
       printf("Stack underflow\n");
       return -1;
   }
   return stack->arr[(stack->top)--];
}


char peek(Stack* stack) {
   if (isEmpty(stack)) {
       return -1;
   }
   return stack->arr[stack->top];
}


int precedence(char c) {
   if (c == '+' || c == '-') {
       return 1;
   }
   if (c == '*' || c == '/') {
       return 2;
   }
   if (c == '^') {
       return 3;
   }
   return 0;
}


int isOperator(char c) {
   return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}


void infixToPostfix(char* infix, char* postfix) {
   Stack stack;
   init(&stack);
   int i = 0, j = 0;

   while (infix[i] != '\0') {
      
       if (isalnum(infix[i])) {
           postfix[j++] = infix[i];
       }
     
       else if (infix[i] == '(') {
           push(&stack, infix[i]);
       }
      
       else if (infix[i] == ')') {
           while (!isEmpty(&stack) && peek(&stack) != '(') {
               postfix[j++] = pop(&stack);
           }
           pop(&stack); 
       }
      
       else if (isOperator(infix[i])) {
           while (!isEmpty(&stack) && precedence(peek(&stack)) >= precedence(infix[i])) {
               postfix[j++] = pop(&stack);
           }
           push(&stack, infix[i]);
       }
       i++;
   }

 
   while (!isEmpty(&stack)) {
       postfix[j++] = pop(&stack);
   }

   postfix[j] = '\0';
}
int main() {
   char infix[MAX], postfix[MAX];

   printf("Enter infix expression: ");
   scanf("%s", infix);

   infixToPostfix(infix, postfix);

   printf("Postfix expression: %s\n", postfix);

   return 0;
}
