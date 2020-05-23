#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define M 8

struct Hashtable
{
    int* data;
    int size;
};

struct Hashtable* create()
{
    struct Hashtable* hashTable = malloc(sizeof(struct Hashtable));

    hashTable->data = malloc(sizeof(int) * M);

    return hashTable;
}

int hash(char* key)
{
    int keyLength = strlen(key);

    int hash  = 0;

    for (int i = 0; i < keyLength; i++)
    {
        hash += (int)key[i];
    }    

    return hash;
}

int get(struct Hashtable* hashTable, char* key)
{
    int hashCode = hash(key);

    int position = hashCode % M;

    int value = *(hashTable->data + position);

    return value;
}

void add(struct Hashtable* hashTable, char* key, int value)
{   
    int hashCode = hash(key);

    int position = hashCode % M;

    printf("position %d\n", position);

    int *item = &*(hashTable->data + position);

    //TODO: handle collisions, add linked list
    
    *item = value;

    hashTable->size++;
}

bool containsKey(struct Hashtable* hashTable, char* key)
{
    int hashCode = hash(key);

    int position = hashCode % M;

    int value = *(hashTable->data + position);
}

int size(struct Hashtable* hashTable)
{
    return hashTable->size;
}

bool isEmpty(struct Hashtable* hashTable)
{
    return !hashTable || hashTable->size == 0;
}

void main()
{
    struct Hashtable* hashTable = create();

    add(hashTable, "corinthians", 2);
    add(hashTable, "barcelona", 3);
    add(hashTable, "real madrid", 4);
    add(hashTable, "liverpool", 1);
    add(hashTable, "palmeiras", 0);

    printf("corinthians: %d\n", get(hashTable, "corinthians"));
    printf("barcelona: %d\n", get(hashTable, "barcelona"));
    printf("real madrid: %d\n", get(hashTable, "real madrid"));
    printf("liverpool: %d\n", get(hashTable, "liverpool"));
    printf("palmeiras: %d\n", get(hashTable, "palmeiras "));
}