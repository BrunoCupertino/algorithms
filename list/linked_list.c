#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

void printItem(struct Node* node) {
    printf(" data:%d ", node->data);
}

void printList(struct Node* node) {
    //is it recursive function better than loops?
    // if(node != NULL) {
    //     printf("%d", node->data);
    //     printList(node->next);
    // }
    int i = 0;

    while (node != NULL) {
        printItem(node);
        node = node->next;
        i++;
    }    
}

void createList(struct Node* node, int size) {
    struct Node* current = node;

    for (int i = 1; i < size + 1; i++)
    {
        struct Node* node = malloc(sizeof(struct Node));

        node->data = i;
        node->next = NULL;    

        current->next = node; 
        current = node;
    }
    
}

struct Node* last(struct Node* head)
{
    struct Node* lastItem = head;

    while (lastItem->next != NULL)
    {
       lastItem = lastItem->next;
    }
    
    return lastItem;
}

void add(struct Node* head, int data)
{
    struct Node* lastNode = last(head);

    struct Node* newLastNode = malloc(sizeof(struct Node));

    newLastNode->data = data;
    newLastNode->next = NULL;    

    lastNode->next = newLastNode;
}

struct Node* get(struct Node* head, int position)
{
    int i = 0;

    struct Node* item = head;

    while (i < position)
    {
        item = item->next;
        i++;
    }

    return item;
}

void removeAt(struct Node* head, int position)
{
    int i = 0;
    struct Node* previousItem = head;
    struct Node* itemToRemove = head;

    while (i < position)
    {
        previousItem = itemToRemove;
        itemToRemove = itemToRemove->next;
        i++;
    }  

    previousItem->next = itemToRemove->next;

    free(itemToRemove);
}

void main()
{
    struct Node* head = NULL;

    head = malloc(sizeof(struct Node));
    head->data = 0;

    add(head, 1);
    add(head, 2);
    add(head, 3);

    printList(head);

    removeAt(head, 2);

    printList(head);

    struct Node* itemAt = get(head, 1);
    struct Node* lastItem = last(head);    

    printItem(itemAt);
    printItem(lastItem);
}