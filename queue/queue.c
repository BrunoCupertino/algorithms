#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct MyQueue
{
    struct Node* rear;
    struct Node* front;
    int count;
};


void printItem(struct Node* node)
{
    printf(" data:%d\n", node->data);
}

void printQueue(struct MyQueue* queue) 
{
    struct Node* node = queue->rear;

    while (node)
    {
        printItem(node);

        node = node->next;
    }    

    printf("count: %d\n", queue->count);
}

struct MyQueue* create()
{
    struct MyQueue* queue = malloc(sizeof(struct MyQueue));

    return queue;
}

int count(struct MyQueue* queue)
{
    int count = queue->count;

    return count;
}

void enqueue(struct MyQueue* queue, int data)
{
    struct Node* newNode = malloc(sizeof(struct Node));

    struct Node* rearNode = queue->rear;
    struct Node* frontNode = queue->front;

    newNode->data = data;
    newNode->next = NULL;

    if (!rearNode)//empty queue
    {
        queue->rear = newNode;
        queue->front = newNode;
    } 
    else
    {
        queue->front->next = newNode;
        queue->front = newNode;
    }

    queue->count++;
}

int dequeue(struct MyQueue* queue)
{
    struct Node* itemToDequeue = queue->rear; 

    int dequeuedData = itemToDequeue->data;

    queue->rear = itemToDequeue->next;   

    free(itemToDequeue);

    queue->count--;

    return dequeuedData;
}

void main()
{
    struct MyQueue* queue = create();

    for (int i = 0; i < 5; i++)
    {
        enqueue(queue, i);
    }

    printQueue(queue);

    int dequeed = dequeue(queue);
    dequeue(queue);
    dequeue(queue);

    printQueue(queue);
}