#ifndef OPENHASHING_H
#define OPENHASHING_H

#define MAX 10

typedef struct Node {
    char *hero;
    struct Node *next;
} Node;

typedef struct HashTable {
    Node *table[MAX];
} HashTable;

HashTable *create_table();
unsigned int hash_function(char *hero);
void insert(HashTable *hashTable, char *hero);
void display_table(HashTable *hashTable);
void free_table(HashTable *hashTable);

#endif

