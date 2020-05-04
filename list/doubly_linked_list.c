#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
    struct Node* previous;
};

struct MyDoublyList
{
    struct Node* head;
    struct Node* tail;
    int count;
};


void printItem(struct Node* node)
{
    printf(" data:%d\n", node->data);
}

void printList(struct MyDoublyList* list) 
{
    struct Node* node = list->head;

    while (node)
    {
        printItem(node);

        node = node->next;
    }    

    printf("count: %d\n", list->count);
}

struct MyDoublyList* create()
{
    struct MyDoublyList* list = malloc(sizeof(struct MyDoublyList));

    return list;
}

int count(struct MyDoublyList* list)
{
    int count = list->count;

    return count;
}

struct Node* first(struct MyDoublyList* list)
{
    struct Node* firstItem = list->head;

    return firstItem;
}

struct Node* last(struct MyDoublyList* list)
{
    struct Node* lastItem = list->tail;

    return lastItem;
}

void insert(struct MyDoublyList* list, int data)
{
    struct Node* headNode = first(list);
    struct Node* tailNode = last(list);

    struct Node* newNode = malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;
    newNode->previous = NULL;

    if (!headNode)
    {
        list->head = newNode;
    }
    else if (!tailNode)
    {
        list->head->next = newNode;
        list->tail = newNode;
    }    
    else
    {
        tailNode->next = newNode;
        newNode->previous = tailNode;
        list->tail = newNode;
    }

    list->count++;
}

struct Node* get(struct MyDoublyList* list, int position)
{
    int i = 0;

    struct Node* item = list->head;

    while (i < position)
    {
        item = item->next;
        i++;
    }

    return item;
}

void removeAt(struct MyDoublyList* list, int position)
{
    int i = 0;
    struct Node* itemToRemove = get(list, position);    

    if (position == 0)
    {
      list->head = itemToRemove->next;
      list->head->previous = NULL;
      free(itemToRemove);
      return;
    }

    struct Node* previousItem = itemToRemove->previous;
    struct Node* nextItem = itemToRemove->next;

    if (previousItem)
        previousItem->next = nextItem;

    if (nextItem)    
        nextItem->previous = previousItem;

    free(itemToRemove);

    list->count--;
}

void main()
{
    struct MyDoublyList* list = create();

    for (int i = 0; i < 10; i++)
    {
        insert(list, i);
    }

    printList(list);

    // removeAt(list, 0);
    // removeAt(list, 2);
    // removeAt(list, 5);

    // printList(list);

    // struct Node* itemAt = get(list, 1);
    // struct Node* firstItem = first(list);    
    // struct Node* lastItem = last(list);    

    // printItem(itemAt);
    // printItem(firstItem);
    // printItem(lastItem);
}