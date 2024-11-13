#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} NODE;
typedef struct stack
{
    NODE *top;
} STACK;
void init(STACK *s)
{
    s->top = NULL;
}
NODE *createNode(int d)
{
    NODE *a = (NODE *)malloc(sizeof(NODE));
    a->data = d;
    a->next = NULL;
    return a;
}
void push(STACK *s, int d)
{
    NODE *a = createNode(d);
    if (a == NULL)
    {
        printf("\nOverflow");
    }
    a->next = s->top;
    s->top = a;
}
void pop(STACK *s)
{
    NODE *a = s->top;
    if (s->top == NULL)
    {
        printf("\nUnderflow");
        return;
    }
    s->top = a->next;
    free(a);
}
void display(STACK *s)
{
    NODE *a = s->top;
    if (s->top == NULL)
    {
        printf("\nEmpty Stack");
    }
    else
    {
        printf("\nStack Data\n");
        while (a != NULL)
        {
            printf(" %d", a->data);
            a = a->next;
        }
    }
}
void menu(STACK *s)
{
    int opt, d;

    while (1)
    {
        printf("\nMenu\n1.Push\n2.Pop\n3.Display\n4.Exit\nOption:");
        scanf("%d", &opt);
        if (opt > 3)
        {
            return;
        }
        switch (opt)
        {
        case 1:
            printf("\nEnter data:");
            scanf("%d", &d);
            push(s, d);
            break;
        case 2:
            pop(s);
            break;
        case 3:
            display(s);
            break;
        }
    }
}
