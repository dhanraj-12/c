#include <stdio.h>

#define MAX 10

// Structure to represent a deque
struct Deque {
    int arr[MAX];
    int front, rear;
};

// Function to initialize the deque
void initDeque(struct Deque *dq) {
    dq->front = dq->rear = -1;
}

// Function to check if the deque is full
int isFull(struct Deque *dq) {
    return (dq->front == 0 && dq->rear == MAX - 1) || (dq->front == dq->rear + 1);
}

// Function to check if the deque is empty
int isEmpty(struct Deque *dq) {
    return dq->front == -1;
}

// Function to insert at the front
void insertFront(struct Deque *dq, int val) {
    if (isFull(dq)) {
        printf("Deque is full!\n");
        return;
    }

    if (dq->front == -1) {
        dq->front = dq->rear = 0;
    } else if (dq->front == 0) {
        dq->front = MAX - 1;
    } else {
        dq->front--;
    }
    dq->arr[dq->front] = val;
}

// Function to insert at the rear
void insertRear(struct Deque *dq, int val) {
    if (isFull(dq)) {
        printf("Deque is full!\n");
        return;
    }

    if (dq->front == -1) {
        dq->front = dq->rear = 0;
    } else if (dq->rear == MAX - 1) {
        dq->rear = 0;
    } else {
        dq->rear++;
    }
    dq->arr[dq->rear] = val;
}

// Function to delete from the front
int deleteFront(struct Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty!\n");
        return -1;
    }

    int val = dq->arr[dq->front];
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else if (dq->front == MAX - 1) {
        dq->front = 0;
    } else {
        dq->front++;
    }
    return val;
}

// Function to delete from the rear
int deleteRear(struct Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty!\n");
        return -1;
    }

    int val = dq->arr[dq->rear];
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else if (dq->rear == 0) {
        dq->rear = MAX - 1;
    } else {
        dq->rear--;
    }
    return val;
}

int main() {
    struct Deque dq;
    initDeque(&dq);

    insertRear(&dq, 10);
    insertRear(&dq, 20);
    insertFront(&dq, 5);
    insertRear(&dq, 30);

    printf("Deque after insertions: ");
    printf("%d ", deleteFront(&dq)); // Deleting from front
    printf("%d ", deleteRear(&dq));  // Deleting from rear

    return 0;
}
