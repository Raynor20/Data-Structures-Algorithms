#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Open Hashing.h"

HashTable *create_table() {
    int i;
    HashTable *hashTable = (HashTable*) malloc(sizeof(HashTable));
    for (i = 0; i < MAX; i++) {
        hashTable->table[i] = NULL;
    }
    return hashTable;
}

unsigned int hash_function(char *hero) {
    unsigned int hash = 0;
    while (*hero) {
        hash = (hash << 5) + *hero++;
    }
    return hash % MAX;
}

void insert(HashTable *hashTable, char *hero) {
    unsigned int index = hash_function(hero);
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->hero = strdup(hero);
    newNode->next = hashTable->table[index];
    hashTable->table[index] = newNode;

    printf("Inserted %s at index %d\n", hero, index); // Debug print
}

void display_table(HashTable *hashTable) {
    int i;
    for (i = 0; i < MAX; i++) {
        printf("\n[%d]: ", i);
        Node *temp = hashTable->table[i];
        while (temp) {
            printf("%s -> ", temp->hero);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void free_table(HashTable *hashTable) {
    int i;
    for (i = 0; i < MAX; i++) {
        Node *temp = hashTable->table[i];
        while (temp) {
            Node *to_free = temp;
            temp = temp->next;
            free(to_free->hero);
            free(to_free);
        }
    }
    free(hashTable);
}

