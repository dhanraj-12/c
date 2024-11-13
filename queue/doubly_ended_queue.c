#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* front = NULL;
Node* rear = NULL;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

void insertFront(int data) {
    Node* newNode = createNode(data);
    if (front == NULL) {
        front = rear = newNode;
    } else {
        newNode->next = front;
        front->prev = newNode;
        front = newNode;
    }
    printf("Inserted %d at the front\n", data);
}

void insertRear(int data) {
    Node* newNode = createNode(data);
    if (rear == NULL) {
        front = rear = newNode;
    } else {
        newNode->prev = rear;
        rear->next = newNode;
        rear = newNode;
    }
    printf("Inserted %d at the rear\n", data);
}

void deleteFront() {
    if (front == NULL) {
        printf("Deque is empty\n");
        return;
    }
    Node* temp = front;
    printf("Deleted %d from the front\n", temp->data);
    front = front->next;
    if (front == NULL) {
        rear = NULL;
    } else {
        front->prev = NULL;
    }
    free(temp);
}

void deleteRear() {
    if (rear == NULL) {
        printf("Deque is empty\n");
        return;
    }
    Node* temp = rear;
    printf("Deleted %d from the rear\n", temp->data);
    rear = rear->prev;
    if (rear == NULL) {
        front = NULL;
    } else {
        rear->next = NULL;
    }
    free(temp);
}

void display() {
    if (front == NULL) {
        printf("Deque is empty\n");
        return;
    }
    Node* temp = front;
    printf("Deque elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice = 0, data;

    while (choice != 6) {
        printf("\n1. Insert at Front\n2. Insert at Rear\n3. Delete from Front\n4. Delete from Rear\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at front: ");
                scanf("%d", &data);
                insertFront(data);
                break;
            case 2:
                printf("Enter data to insert at rear: ");
                scanf("%d", &data);
                insertRear(data);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
