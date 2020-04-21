#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

void printList(struct Node* node) {
    //is it recursive function better than loops?
    // if(node != NULL) {
    //     printf("%d", node->data);
    //     printList(node->next);
    // }
    int i = 0;

    while (node != NULL) {
        printf(" data:%d ", node->data);
        node = node->next;
        i++;
    }
    
}

void createList(struct Node* node, int size) {
    struct Node* current = node;

    for (int i = 2; i < size + 1; i++)
    {
        struct Node* node = malloc(sizeof(struct Node));

        node->data = i;
        node->next = NULL;       
        current->next = node; 
        current = node;
    }
    
}

void main()
{
    struct Node* head = NULL;
    // struct Node* second = NULL;
    // struct Node* third = NULL;
    


    head = malloc(sizeof(struct Node));
    // second = malloc(sizeof(struct Node));
    // third = malloc(sizeof(struct Node));

    head->data = 1;
    // head->next = *current;

    // second->data = 2;
    // second->next = third;

    // third->data = 3;

    
    createList(head, 10);
    

    printList(head);
}