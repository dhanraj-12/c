#include <stdio.h>
#define SIZE 10

int hashTable[SIZE];

// Initialize hash table to -1 (indicating empty slots)
void initialize() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = -1;
    }
}

// Hash function using the mid-square method
int hashFunction(int key) {
    int square = key * key;
    int mid = (square / 10) % SIZE;  // Extract the middle digit(s) for the index
    return mid;
}

// Insert function
void insert(int key) {
    int index = hashFunction(key);

    // Linear probing in case of collision
    while (hashTable[index] != -1) {
        index = (index + 1) % SIZE;
    }
    hashTable[index] = key;
}

// Display the hash table
void display() {
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] != -1) {
            printf("Index %d: %d\n", i, hashTable[i]);
        } else {
            printf("Index %d: \n", i);
        }
    }
}

int main() {
    initialize();

    // Example keys to insert
    insert(23);
    insert(43);
    insert(13);
    insert(27);

    printf("Hash Table (Mid-Square Method):\n");
    display();

    return 0;
}
