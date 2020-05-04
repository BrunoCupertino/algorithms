#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

void printItem(struct Node* node)
{
    printf(" data:%d\n", node->data);
}

void printList(struct Node* node) 
{
    while (node)
    {
        printItem(node);

        node = node->next;
    }    
}

struct Node* last(struct Node* head)
{
    struct Node* lastItem = head;

    while (lastItem && lastItem->next)
    {
       lastItem = lastItem->next;
    }
    
    return lastItem;
}

void insert(struct Node** head, int data)
{
    struct Node* lastNode = last(*head);

    struct Node* newLastNode = malloc(sizeof(struct Node));

    newLastNode->data = data;
    newLastNode->next = NULL;    

    if (!lastNode)
        *head = newLastNode;        
    else
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

void removeAt(struct Node **head, int position)
{
    int i = 0;
    struct Node* previousItem = *head;
    struct Node* itemToRemove = *head;

    if (position == 0)
    {
      *head = itemToRemove->next;
      free(itemToRemove);
      return;
    }

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

    for (int i = 0; i < 10; i++)
    {
        insert(&head, i);
    }

    printList(head);

    removeAt(&head, 0);
    removeAt(&head, 2);
    removeAt(&head, 5);

    printList(head);

    struct Node* itemAt = get(head, 1);
    struct Node* lastItem = last(head);    

    printItem(itemAt);
    printItem(lastItem);
}