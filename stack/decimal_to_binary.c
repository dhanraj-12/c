#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
   int data;
   struct Node* next;
} Node;

typedef struct Stack {
   Node* top;
} Stack;

void push(Stack* stack, int value) {
   Node* newNode = (Node*)malloc(sizeof(Node));
   newNode->data = value;
   newNode->next = stack->top;
   stack->top = newNode;
}

int pop(Stack* stack) {
   if (stack->top == NULL) {
       return -1;  // Or some error code
   }
   Node* temp = stack->top;
   int value = temp->data;
   stack->top = stack->top->next;
   free(temp);
   return value;
}

int isEmpty(Stack* stack) {
   return stack->top == NULL;
}

void decimalToBinary(int decimal) {
   Stack stack;
   stack.top = NULL;
  
   if (decimal == 0) {
       printf("0");
       return;
   }
  
   while (decimal > 0) {
       push(&stack, decimal % 2);
       decimal /= 2;
   }
  
   while (!isEmpty(&stack)) {
       printf("%d", pop(&stack));
   }
   printf("\n");
}

int main() {
   int decimal;
  
   printf("Enter a decimal number: ");
   scanf("%d", &decimal);
   printf("Binary Representation: ");
   decimalToBinary(decimal);
  
   return 0;
}
