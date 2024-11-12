#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
   char data;
   struct Node* next;
} Node;

typedef struct Stack {
   Node* top;
} Stack;

void push(Stack* stack, char value) {
   Node* newNode = (Node*)malloc(sizeof(Node));
   newNode->data = value;
   newNode->next = stack->top;
   stack->top = newNode;
}

char pop(Stack* stack) {
   if (stack->top == NULL) {
       return '\0';
   }
   Node* temp = stack->top;
   char value = temp->data;
   stack->top = stack->top->next;
   free(temp);
   return value;
}

int isEmpty(Stack* stack) {
   return stack->top == NULL;
}

void reverseString(char* str) {
   Stack stack;
   stack.top = NULL;
  
   int length = strlen(str);
   for (int i = 0; i < length; i++) {
       push(&stack, str[i]);
   }
  
   for (int i = 0; i < length; i++) {
       str[i] = pop(&stack);
   }
}

int main() {
   char str[] = "Hello, World!";
  
   reverseString(str);
  
   printf("Reversed String: %s\n", str);
  
   return 0;
}
