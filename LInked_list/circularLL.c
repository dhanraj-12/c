#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;             
    struct Node* next;    
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode;
    return newNode;
}

void insertAtBeg(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
     
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;  
        *head = newNode;        
    }
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;  
    }
}


void insertAtPosition(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);
    if (position == 0) {
        insertAtBeg(head, data);
        return;
    }
    struct Node* temp = *head;
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
        if (temp == *head) {
            break; 
        }
    }
    if (temp == NULL || temp->next == *head) {
        printf("Position out of range\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}


void deleteFromBeg(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (*head == (*head)->next) {
        free(*head);
        *head = NULL;
    } else {
        struct Node* temp = *head;
        struct Node* last = *head;
      
        while (last->next != *head) {
            last = last->next;
        }
        *head = (*head)->next;
        last->next = *head;
        free(temp);
    }
}

void deleteFromEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (*head == (*head)->next) {
        free(*head);
        *head = NULL;
    } else {
        struct Node* temp = *head;
        struct Node* prev = NULL;
        // Traverse to the second last node
        while (temp->next != *head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = *head;
        free(temp);
    }
}
void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (position == 0) {
        deleteFromBeg(head);
        return;
    }
    struct Node* temp = *head;
    struct Node* prev = NULL;
    for (int i = 0; temp != NULL && i < position; i++) {
        prev = temp;
        temp = temp->next;
        if (temp == *head) {
            break;  
        }
    }
    if (temp == NULL || temp == *head) {
        printf("Position out of range\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void print(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, position;

    do {
        printf("\nCircular Linked List Operations:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete at Position\n");
        printf("7. Print List\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insertAtBeg(&head, data);
                break;

            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;

            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert at: ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                break;

            case 4:
                deleteFromBeg(&head);
                break;

            case 5:
                deleteFromEnd(&head);
                break;

            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(&head, position);
                break;

            case 7:
                printf("Circular linked list: ");
                print(head);
                break;

            case 8:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 8);

    return 0;
}
