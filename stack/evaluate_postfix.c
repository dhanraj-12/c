#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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
       return 0;
   }
   Node* temp = stack->top;
   int value = temp->data;
   stack->top = stack->top->next;
   free(temp);
   return value;
}

int peek(Stack* stack) {
   if (stack->top == NULL) {
       return 0;
   }
   return stack->top->data;
}

int isEmpty(Stack* stack) {
   return stack->top == NULL;
}

int evaluatePostfix(char* expression) {
   Stack stack;
   stack.top = NULL;
   int i = 0;
  
   while (expression[i] != '\0') {
       if (isdigit(expression[i])) {
           push(&stack, expression[i] - '0');
       } else {
           int val2 = pop(&stack);
           int val1 = pop(&stack);
           switch (expression[i]) {
               case '+': push(&stack, val1 + val2); break;
               case '-': push(&stack, val1 - val2); break;
               case '*': push(&stack, val1 * val2); break;
               case '/': push(&stack, val1 / val2); break;
               case '%': push(&stack, val1 % val2); break;
           }
       }
       i++;
   }
  
   return pop(&stack);
}

int main() {
   char expression[] = "231*+9-";
   int result = evaluatePostfix(expression);
  
   printf("Postfix Expression: %s\n", expression);
   printf("Evaluation Result: %d\n", result);
  
   return 0;
}
