#include <stdio.h>
#define TABLE_SIZE 10

// Function to generate hash key using mid-square method
int midSquareHash(int key) {
    long long squared = (long long)key * (long long)key;
    int numDigits = 0;
    int temp = key;

    // Count the number of digits in the squared result
    while (temp != 0) {
        numDigits++;
        temp /= 10;
    }

    // Extracting the middle digits as the hash value
    int numToExtract = (numDigits % 2 == 0) ? (numDigits - 2) / 2 : (numDigits - 1) / 2;
    int divisor = 1;

    while (numToExtract > 0) {
        divisor *= 10;
        numToExtract--;
    }

    int result = (squared / divisor) % TABLE_SIZE;
    return result;
}

// Function to insert key into hash table using mid-square method
void insert(int hashTable[], int key) {
    int index = midSquareHash(key);

    // Linear probing for collision resolution
    while (hashTable[index] != -1) {
        index = (index + 1) % TABLE_SIZE;
    }

    hashTable[index] = key;
}

// Function to search for a key in the hash table
int search(int hashTable[], int key) {
    int index = midSquareHash(key);
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
    printf("--------------\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d: ", i);
        if (hashTable[i] != -1) {
            printf("%d", hashTable[i]);
        } else {
            printf("Empty");
        }
        printf("\n");
    }printf("--------------\n");
}

int main() {
    int hashTable[TABLE_SIZE];

    // Initializing hash table slots to -1 (indicating empty slots)
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = -1;
    }

    // Inserting elements into the hash table using mid-square method
    insert(hashTable, 123);
    insert(hashTable, 486);
    insert(hashTable, 789);
    insert(hashTable, 787);

    // Displaying the hash table
    display(hashTable);

    // Searching for elements in the hash table
    int keyToSearch = 486;
    int result = search(hashTable, keyToSearch);
    if (result != -1) {
        printf("Key %d found at index %d\n", keyToSearch, result);
    } else {
        printf("Key %d not found in the hash table\n", keyToSearch);
    }
    return 0;
}
