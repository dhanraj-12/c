#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    void **data;
    int top;
    int capacity;
} Stack;

Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->data = (void**)malloc(stack->capacity * sizeof(void*));
    return stack;
}

int isStackFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

int isStackEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, void* item) {
    if (isStackFull(stack)) {
        printf("Stack overflow\n");
        return;
    }
    stack->data[++stack->top] = item;
}

void* pop(Stack* stack) {
    if (isStackEmpty(stack)) {
        printf("Stack underflow\n");
        return NULL;
    }
    return stack->data[stack->top--];
}

void* peek(Stack* stack) {
    if (isStackEmpty(stack)) {
        printf("Stack is empty\n");
        return NULL;
    }
    return stack->data[stack->top];
}

void freeStack(Stack* stack) {
    free(stack->data);
    free(stack);
}
