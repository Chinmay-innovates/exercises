#include <stdio.h>
#define TABLE_SIZE 13

// Hash function using division method
int hash(int key) {
    return key % TABLE_SIZE;
}

// Function to insert key into hash table
// void insert(int hashTable[], int key) {
//     int index = hash(key);
    
//     // Linear probing for collision resolution
//     while (hashTable[index] != -1) {
//         index = (index + 1) % TABLE_SIZE;
//     }
    
//     hashTable[index] = key;
// }

// Function to insert key into hash table using Quadratic probing
 void insert(int hashTable[], int key) {
    int index = hash(key);
    int i = 1;
    int originalIndex = index;

    while (hashTable[index] != -1) {
        index = (originalIndex + i * i) % TABLE_SIZE;
        i++;

        // If we traverse the entire table and don't find an empty slot
        if (index == originalIndex) {
            printf("Hash table is full. Cannot insert key %d\n", key);
            return;
        }
    }

    hashTable[index] = key;
}

// Function to search for a key in the hash table
int search(int hashTable[], int key)
 {
    int index = hash(key);
    int originalIndex = index;
    
    // Linear probing to find the key
    while (hashTable[index] != key) {
        index = (index + 1) % TABLE_SIZE;
    //Quadratic probing to find the key
    /* index = (hash(key) + i * i) % TABLE_SIZE;
        i++; */

        // If we reach an empty slot or complete a loop without finding the key
        if (hashTable[index] == -1 || index == originalIndex) 
        {
            return -1; // Key not found
        }
    } 
    return index; 
}

// Function to display the hash table
void display(int hashTable[]) {
    printf("Hash Table:\n");
    printf("---------------\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d: ", i);
        if (hashTable[i] != -1) {
            printf("%d", hashTable[i]);
        } else {
            printf("Empty");
        }
        printf("\n---------------\n");
    }
}

int main() {
    int hashTable[TABLE_SIZE];
    
    // Initializing hash table slots to -1 (indicating empty slots)
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = -1;
    }

    // Inserting elements into the hash table
    insert(hashTable,65);
    insert(hashTable,34);
    insert(hashTable,79);
    insert(hashTable,114);
    insert(hashTable,26);
    insert(hashTable,85);
    insert(hashTable,55);
    insert(hashTable,89);
    insert(hashTable,22);
    insert(hashTable,98);

    

    // Displaying the hash table
    display(hashTable);

    // Searching for elements in the hash table
    int keyToSearch = 0;
    int result = search(hashTable, keyToSearch);
    if (result != -1) {
        printf("Key %d found at index %d\n",keyToSearch, result);
    } else {
        printf("Key %d not found in the hash table\n",keyToSearch);
    }
    return 0;
}

