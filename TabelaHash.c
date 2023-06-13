#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

typedef struct {
    char key[50];
    char value[50];
} Animal;

typedef struct {
    Animal *table[TABLE_SIZE];
} HashTable;

int hashFunction(char *key) {
    int sum = 0;
    int len = strlen(key);
    
    for (int i = 0; i < len; i++) {
        sum += key[i];
    }
    
    return sum % TABLE_SIZE;
}

HashTable* createHashTable() {
    HashTable *hashTable = (HashTable*) malloc(sizeof(HashTable));
    
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable->table[i] = NULL;
    }
    
    return hashTable;
}

void insertAnimal(HashTable *hashTable, char *key, char *value) {
    int index = hashFunction(key);
    
    Animal *animal = (Animal*) malloc(sizeof(Animal));
    strcpy(animal->key, key);
    strcpy(animal->value, value);
    
    hashTable->table[index] = animal;
}

Animal* searchAnimal(HashTable *hashTable, char *key) {
    int index = hashFunction(key);
    
    Animal *animal = hashTable->table[index];
    
    if (animal != NULL && strcmp(animal->key, key) == 0) {
        return animal;
    }
    
    return NULL;
}

void displayHashTable(HashTable *hashTable) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Animal *animal = hashTable->table[i];
        
        if (animal != NULL) {
            printf("Index %d: %s - %s\n", i, animal->key, animal->value);
        }
    }
}

int main() {
    HashTable *hashTable = createHashTable();
    
    insertAnimal(hashTable, "cat", "Felis catus");
    insertAnimal(hashTable, "dog", "Canis lupus familiaris");
    insertAnimal(hashTable, "elephant", "Elephas maximus");
    insertAnimal(hashTable, "lion", "Panthera leo");
    
    displayHashTable(hashTable);
    
    char searchKey[50];
    printf("\nEnter an animal to search: ");
    scanf("%s", searchKey);
    
    Animal *foundAnimal = searchAnimal(hashTable, searchKey);
    
    if (foundAnimal != NULL) {
        printf("Animal found: %s - %s\n", foundAnimal->key, foundAnimal->value);
    } else {
        printf("Animal not found!\n");
    }
    
    return 0;
}
