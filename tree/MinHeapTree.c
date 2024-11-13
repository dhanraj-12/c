#include <stdio.h>

#define MAX_SIZE 100

int heap[MAX_SIZE];
int heapSize = 0;

// Function to swap two elements in the heap
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Function to insert an element into the Min-Heap
void insertMinHeap(int value) {
    if (heapSize >= MAX_SIZE) {
        printf("Heap is full\n");
        return;
    }

    // Insert the new value at the end of the heap
    heap[heapSize] = value;
    int currentIndex = heapSize;
    heapSize++;

    // Heapify upwards
    while (currentIndex > 0 && heap[currentIndex] < heap[(currentIndex - 1) / 2]) {
        swap(&heap[currentIndex], &heap[(currentIndex - 1) / 2]);
        currentIndex = (currentIndex - 1) / 2;
    }
}

// Function to heapify downwards
void minHeapify(int index) {
    int smallest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (leftChild < heapSize && heap[leftChild] < heap[smallest]) {
        smallest = leftChild;
    }
    if (rightChild < heapSize && heap[rightChild] < heap[smallest]) {
        smallest = rightChild;
    }

    if (smallest != index) {
        swap(&heap[index], &heap[smallest]);
        minHeapify(smallest);
    }
}

// Function to delete and return the minimum element (root) from the Min-Heap
int deleteMin() {
    if (heapSize <= 0) {
        printf("Heap is empty\n");
        return -1;
    }

    int minElement = heap[0];
    heap[0] = heap[heapSize - 1];
    heapSize--;
    minHeapify(0);

    return minElement;
}

// Function to display the heap
void displayHeap() {
    for (int i = 0; i < heapSize; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int main() {
    insertMinHeap(10);
    insertMinHeap(20);
    insertMinHeap(15);
    insertMinHeap(30);
    insertMinHeap(40);

    printf("Min-Heap: ");
    displayHeap();

    printf("Deleted min element: %d\n", deleteMin());
    printf("Min-Heap after deletion: ");
    displayHeap();

    return 0;
}
