#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

// Hash table structure
typedef struct {
    int key;
    int data;
} HashTable;

// Function to calculate the first hash (using division method)
int hash1(int key) {
    return key % TABLE_SIZE;
}

// Function to calculate the second hash (using prime number)
int hash2(int key) {
    // Prime number smaller than TABLE_SIZE for best results
    return 7 - (key % 7);
}

// Function to insert into hash table using double hashing
void insert(HashTable table[], int key, int data) {
    int index = hash1(key);
    int step = hash2(key);
    
    while (table[index].key != -1) {
        index = (index + step) % TABLE_SIZE;
    }

    table[index].key = key;
    table[index].data = data;
}

// Function to search for a key in the hash table
int search(HashTable table[], int key) {
    int index = hash1(key);
    int step = hash2(key);
    
    while (table[index].key != key) {
        index = (index + step) % TABLE_SIZE;

        // If we reach an empty slot or complete a loop without finding the key
        if (table[index].key == -1) {
            return -1; // Key not found
        }
    }

    return index; // Return index where key is found
}

// Function to display the hash table
void display(HashTable table[]) {
    printf("     Hash Table:\n");
    printf("---------------------\n");
    printf("Index\tKey\tData\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("%d\t", i);
        if (table[i].key != -1) {
            printf("%d\t%d\n", table[i].key, table[i].data);
        } else {
            printf("Empty\n");
        }
    }
    printf("---------------------\n");
}

int main() {
    HashTable table[TABLE_SIZE];

    // Initializing hash table slots to -1 (indicating empty slots)
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i].key = -1;
        table[i].data = -1;
    }

    // Inserting records into the hash table using double hashing
    insert(table,  10,1);
    insert(table,  37,1);
    insert(table,  90,1);
    insert(table,  45,1);
    insert(table,  22,1);
    insert(table,  17,1);
    insert(table,  55,1);



    // Displaying the hash table
    display(table);

    // Searching for a key in the hash table
    int searchKey = 25;
    int result = search(table, searchKey);
    if (result != -1) {
        printf("Key %d found at index %d with data %d\n", searchKey, result, table[result].data);
    } else {
        printf("Key %d not found in the hash table\n", searchKey);
    }

    return 0;
}
