#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* previous;
};


void printItem(int data)
{
    printf(" data:%d\n", data);
}

void printStack(struct Node* node) 
{
    while (node)
    {
        printItem(node->data);

        node = node->previous;
    }    
}

void push(struct Node** top, int data)
{
    struct Node* newTopNode = malloc(sizeof(struct Node));

    newTopNode->data = data;
    newTopNode->previous = *top;    

    *top = newTopNode;
}

int peek(struct Node* top)
{
    return top->data;
}

int pop(struct Node** top)
{
    struct Node* itemToPop = *top;
    struct Node* newTop = itemToPop->previous;

    int topValue = itemToPop->data;

    *top = newTop;

    free(itemToPop);

    return topValue;
}

void main()
{
    struct Node* top = NULL;

    for (int i = 0; i < 5; i++)
    {
        push(&top, i);
    }    

    printStack(top);

    int popedItem = pop(&top);
    int peekedItem = peek(top);

    printStack(top);

    printItem(popedItem);
    printItem(peekedItem);
}