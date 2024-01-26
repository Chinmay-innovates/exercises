#include <stdio.h>
#define TABLE_SIZE 10
#define MULTIPLICATION_FACTOR 0.6180339887

// Function to generate hash key using multiplication method
int multiplicationHash(int key) {
    double product = key * MULTIPLICATION_FACTOR;
    double fractionalPart = product - (int)product; // Extracting fractional part

    return (int)(TABLE_SIZE * fractionalPart);
}

// Function to insert key into hash table using multiplication method
void insert(int hashTable[], int key) {
    int index = multiplicationHash(key);

    // Linear probing for collision resolution
    while (hashTable[index] != -1) {
        index = (index + 1) % TABLE_SIZE;
    }

    hashTable[index] = key;
}

// Function to search for a key in the hash table
int search(int hashTable[], int key) {
    int index = multiplicationHash(key);
    int originalIndex = index;

    // Linear probing to find the key
    while (hashTable[index] != key) {
        index = (index + 1) % TABLE_SIZE;

        // If we reach an empty slot or complete a loop without finding the key
        if (hashTable[index] == -1 || index == originalIndex) {
            return -1; // Key not found
        }
    }

    return index; // Return index where key is found
}

// Function to display the hash table
void display(int hashTable[]) {
    printf("Hash Table:\n");
    printf("-----------\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d: ", i);
        if (hashTable[i] != -1) {
            printf("%d", hashTable[i]);
        } else {
            printf("Empty");
        }
        printf("\n");
    }
    printf("-----------\n");
}

int main() {
    int hashTable[TABLE_SIZE];

    // Initializing hash table slots to -1 (indicating empty slots)
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = -1;
    }

    // Inserting elements into the hash table using multiplication method
    insert(hashTable, 123);
    insert(hashTable, 456);
    insert(hashTable, 789);
    insert(hashTable, 987);

    // Displaying the hash table
    display(hashTable);

    // Searching for elements in the hash table
    int keyToSearch = 456;
    int result = search(hashTable, keyToSearch);
    if (result != -1) {
        printf("Key %d found at index %d\n", keyToSearch, result);
    } else {
        printf("Key %d not found in the hash table\n", keyToSearch);
    }

    return 0;
}
