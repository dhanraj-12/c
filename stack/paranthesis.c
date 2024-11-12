#include <stdio.h>
#include <stdlib.h>

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

char peek(Stack* stack) {
   if (stack->top == NULL) {
       return '\0';
   }
   return stack->top->data;
}

int isEmpty(Stack* stack) {
   return stack->top == NULL;
}

int isValidParentheses(char* expression) {
   Stack stack;
   stack.top = NULL;
   int i = 0;
  
   while (expression[i] != '\0') {
       char ch = expression[i];
       if (ch == '(' || ch == '{' || ch == '[') {
           push(&stack, ch);
       } else if (ch == ')' || ch == '}' || ch == ']') {
           if (isEmpty(&stack)) {
               return 0;
           }
           char top = pop(&stack);
           if ((ch == ')' && top != '(') ||
               (ch == '}' && top != '{') ||
               (ch == ']' && top != '[')) {
               return 0;
           }
       }
       i++;
   }
  
   return isEmpty(&stack);
}

int main() {
   char expression[] = "{[()]}";
  
   if (isValidParentheses(expression)) {
       printf("Parentheses are balanced.\n");
   } else {
       printf("Parentheses are not balanced.\n");
   }
  
   return 0;
}
