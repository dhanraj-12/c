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

// Function to insert an element into the Max-Heap
void insertMaxHeap(int value) {
    if (heapSize >= MAX_SIZE) {
        printf("Heap is full\n");
        return;
    }

    // Insert the new value at the end of the heap
    heap[heapSize] = value;
    int currentIndex = heapSize;
    heapSize++;

    // Heapify upwards
    while (currentIndex > 0 && heap[currentIndex] > heap[(currentIndex - 1) / 2]) {
        swap(&heap[currentIndex], &heap[(currentIndex - 1) / 2]);
        currentIndex = (currentIndex - 1) / 2;
    }
}

// Function to heapify downwards
void maxHeapify(int index) {
    int largest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (leftChild < heapSize && heap[leftChild] > heap[largest]) {
        largest = leftChild;
    }
    if (rightChild < heapSize && heap[rightChild] > heap[largest]) {
        largest = rightChild;
    }

    if (largest != index) {
        swap(&heap[index], &heap[largest]);
        maxHeapify(largest);
    }
}

// Function to delete and return the maximum element (root) from the Max-Heap
int deleteMax() {
    if (heapSize <= 0) {
        printf("Heap is empty\n");
        return -1;
    }

    int maxElement = heap[0];
    heap[0] = heap[heapSize - 1];
    heapSize--;
    maxHeapify(0);

    return maxElement;
}

// Function to display the heap
void displayHeap() {
    for (int i = 0; i < heapSize; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int main() {
    insertMaxHeap(10);
    insertMaxHeap(20);
    insertMaxHeap(15);
    insertMaxHeap(30);
    insertMaxHeap(40);

    printf("Max-Heap: ");
    displayHeap();

    printf("Deleted max element: %d\n", deleteMax());
    printf("Max-Heap after deletion: ");
    displayHeap();

    return 0;
}
