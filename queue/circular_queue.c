#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    if (front == NULL) {
        front = newNode;
        rear = newNode;
        newNode->next = front;
    } else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }
    printf("Enqueued %d\n", value);
}

void dequeue() {
    if (front == NULL) {
        printf("Queue is empty!\n");
    } else if (front == rear) {
        printf("Dequeued %d\n", front->data);
        free(front);
        front = rear = NULL;
    } else {
        struct Node* temp = front;
        printf("Dequeued %d\n", front->data);
        front = front->next;
        rear->next = front;
        free(temp);
    }
}

void display() {
    if (front == NULL) {
        printf("Queue is empty!\n");
    } else {
        struct Node* temp = front;
        printf("Queue elements: ");
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != front);
        printf("\n");
    }
}

int main() {
    int choice = 0, value;

    while (choice != 4) {
        printf("\nCircular Queue Operations:\n");
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
                enqueue(value);
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
