#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Array
{
    int* data;
    int capacity;
    int size;
};

struct Array* create(int size)
{
    struct Array* array = malloc(sizeof(struct Array));

    array->data = malloc(sizeof(int) * size);
    array->capacity = size;

    return array;
}

int get(struct Array* array, int position)
{
    int item = *(array->data + position);

    return item;
}

void set(struct Array* array, int position, int value)
{   
    int *item = &*(array->data + position);
    
    *item = value;

    array->size++;
}

int capacity(struct Array* array)
{
    return array->capacity;
}

int size(struct Array* array)
{
    return array->size;
}

bool isEmpty(struct Array* array)
{
    return array && array->size == 0;
}

void printArray(struct Array* array)
{
    int siz = size(array);

    for (int i = 0; i < siz; i++)
    {
        printf("data:%d at:%d\n", get(array, i), i);
    }   

    printf("capacity:%d\n", array->capacity);
    printf("size:%d\n", array->size);
    printf("isEmpty:%d\n", isEmpty(array));
}

void main()
{
    struct Array* array = create(5);

    int arrayCapacity = array->capacity;

    for (int i = 0; i < arrayCapacity; i++)
    {
        set(array, i, i + 1);  
    }

    printArray(array);
}