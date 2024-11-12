#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    int priority;
    struct Node* next;
};

struct Node* front = NULL;

void enqueue(int value, int priority) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->priority = priority;
    newNode->next = NULL;

    if (front == NULL || priority > front->priority) {
        newNode->next = front;
        front = newNode;
    } else {
        struct Node* temp = front;
        while (temp->next != NULL && temp->next->priority >= priority) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    printf("Enqueued %d with priority %d\n", value, priority);
}

void dequeue() {
    if (front == NULL) {
        printf("Priority Queue is empty!\n");
    } else {
        struct Node* temp = front;
        printf("Dequeued %d with priority %d\n", temp->data, temp->priority);
        front = front->next;
        free(temp);
    }
}

void display() {
    if (front == NULL) {
        printf("Priority Queue is empty!\n");
    } else {
        struct Node* temp = front;
        printf("Priority Queue elements:\n");
        while (temp != NULL) {
            printf("Value: %d, Priority: %d\n", temp->data, temp->priority);
            temp = temp->next;
        }
    }
}

int main() {
    int choice = 0, value, priority;

    while (choice != 4) {
        printf("\nPriority Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                printf("Enter priority of the value: ");
                scanf("%d", &priority);
                enqueue(value, priority);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}

