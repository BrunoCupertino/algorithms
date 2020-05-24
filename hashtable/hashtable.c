#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define M 8

struct Hashtable
{
    struct KeyValuePair** data;
    int size;
};

struct KeyValuePair
{
    char* key;
    int value;
    struct KeyValuePair* next;
};

struct Hashtable* create()
{
    struct Hashtable* hashTable = malloc(sizeof(struct Hashtable));

    hashTable->data = malloc(sizeof(struct KeyValuePair*) * M);

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

    struct KeyValuePair **item = (hashTable->data) + position;

    while (*item)
    {
        if (strcmp((*item)->key, key) == 0)
            return (*item)->value;
        
        item = &(*item)->next;
    }

    return -1;
}

void add(struct Hashtable* hashTable, char* key, int value)
{   
    int hashCode = hash(key);

    int position = hashCode % M;

    struct KeyValuePair **item = (hashTable->data) + position;

    struct KeyValuePair* newKeyValuePair = malloc(sizeof(struct KeyValuePair));

    newKeyValuePair->key = key;
    newKeyValuePair->value = value;
    newKeyValuePair->next = *item;
    
    *item = newKeyValuePair;

    hashTable->size++;
}

bool containsKey(struct Hashtable* hashTable, char* key)
{
    int hashCode = hash(key);

    int position = hashCode % M;

    struct KeyValuePair **item = (hashTable->data) + position;

    while (*item)
    {
        if (strcmp((*item)->key, key) == 0)
            return true;

        item = &(*item)->next;
    }    

    return false;
}

void removeItem(struct Hashtable* hashTable, char* key)
{
    int hashCode = hash(key);

    int position = hashCode % M;

    struct KeyValuePair **item = (hashTable->data) + position;
    struct KeyValuePair **previousItem = item;

    while (*item)
    {
        if (strcmp((*item)->key, key) == 0)
        {
            (*previousItem)->next = (*item)->next;

            if (previousItem == item)
                *previousItem = NULL;

            free(*item);

            hashTable->size--;

            return;
        }        
        
        previousItem = item;
        item = &(*item)->next;
    }    
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

    char* corinthians = "corinthians";
    char* barcelona = "barcelona";
    char* realMadrid = "real madrid";
    char* liverpool = "liverpool";
    char* milan = "milan";
    char* lazio = "lazio";
    char* bayernMunich = "bayern munich";
    char* palmeiras = "palmeiras";

    add(hashTable, corinthians, 2);
    add(hashTable, barcelona, 3);
    add(hashTable, realMadrid, 4);
    add(hashTable, liverpool, 1);
    add(hashTable, bayernMunich, 1);
    add(hashTable, palmeiras, 0);

    printf("key: %s - value: %d\n", corinthians, get(hashTable, corinthians));
    printf("key: %s - value: %d\n", barcelona, get(hashTable, barcelona));
    printf("key: %s - value: %d\n", realMadrid, get(hashTable, realMadrid));
    printf("key: %s - value: %d\n", liverpool, get(hashTable, liverpool));
    printf("key: %s - value: %d\n", milan, get(hashTable, milan));
    printf("key: %s - value: %d\n", bayernMunich, get(hashTable, bayernMunich));
    printf("key: %s - value: %d\n", palmeiras, get(hashTable, palmeiras));

    printf("contains key %s? %d\n", corinthians, containsKey(hashTable, corinthians));
    printf("contains key %s? %d\n", barcelona, containsKey(hashTable, barcelona));
    printf("contains key %s? %d\n", lazio, containsKey(hashTable, lazio));

    removeItem(hashTable, bayernMunich);
    printf("contains key %s? %d\n", bayernMunich, containsKey(hashTable, bayernMunich));
}