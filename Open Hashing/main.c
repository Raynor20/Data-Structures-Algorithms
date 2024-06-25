#include <stdio.h>
#include "Open Hashing.h"

int main() {
    int n, i;
    HashTable *hashTable = create_table();
    
    char *heroes[] = {"Axe", "Anti Mage", "Bloodseeker", "Bane", "Centaur Warruner", "Crystal Maiden",
                      "Drow Ranger", "Earthshaker", "Juggernaut", "Mirana", "Morphling",
                      "Shadow Fiend", "Phantom Lancer", "Riki", "Sand King", "Sniper",
                      "Storm Spirit", "Sven", "Tiny", "Vengeful Spirit", "Windranger"
    };
    
    n = sizeof(heroes) / sizeof(heroes[0]);
    for (i = 0; i < n; i++) {
        insert(hashTable, heroes[i]);
    }
    
    display_table(hashTable);
    free_table(hashTable);
    
    return 0;
}

