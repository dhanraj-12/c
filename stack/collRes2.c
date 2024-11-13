#include <stdio.h>
#define SIZE 10

int hashTable[SIZE];

// Initialize hash table to -1 (indicating empty slots)
void initialize() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = -1;
    }
}

// Hash function using modulo division
int hashFunction(int key) {
    return key % SIZE;
}

// Insert function using linear probing for collision resolution
void insert(int key) {
    int index = hashFunction(key);

    // Linear probing in case of collision
    while (hashTable[index] != -1) {
        index = (index + 1) % SIZE;
    }
    hashTable[index] = key;
}

// Search function
int search(int key) {
    int index = hashFunction(key);

    // Search using linear probing
    while (hashTable[index] != -1) {
        if (hashTable[index] == key) {
            return index;
        }
        index = (index + 1) % SIZE;
    }
    return -1;
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

    printf("Hash Table (Linear Probing):\n");
    display();

    return 0;
}
