#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// Queues are FIFO 
// Time complexity for queues
// Space: O(n)
// Search: O(n)
// Insert: O(1)
// Delete: O(1)
typedef struct Node
{
    int key;
    int data;
    struct Node* previous;
    struct Node* next;
} Node;

typedef struct Queue
{
    struct Node* head;
    struct Node* tail;
    int size;
} Queue;

Node* createNode(int key, int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node*));
    newNode->next = newNode->previous = 0;
    newNode->key = key;
    newNode->data = data;
    return newNode;
}

Queue* initializeQueue()
{
    Queue* newQueue = (Queue*)malloc(sizeof(Queue*));
    newQueue->head = newQueue->tail = NULL;
    newQueue->size = 0;
    return newQueue;
}

void printNode(Node* node)
{
    printf("\t(%d|%d)\n", node->key, node->data);
}

void printQueue(Queue* queue)
{
    Node* currentNode = queue->head;
    while (currentNode != NULL)
    {
        printNode(currentNode);
        currentNode = currentNode->next;
    }
    printf("Size: %d\n", queue->size);
}

void enQueue(Queue* queue, int key, int data)
{
    Node* node =  createNode(key, data);
    if (queue->head == NULL)
        queue->head = queue->tail = node;
    else //if(queue->head == queue->tail)
    {
        node->next = queue->head;
        queue->head->previous = node;
        queue->head = node;
    }
    queue->size++;
}

int deQueue(Queue* queue)
{
    assert(queue->head != NULL);
    int obsoleteData = queue->tail->data;
    Node* obsoleteNode = queue->tail;
    queue->tail = queue->tail->previous;
    queue->tail->next = NULL;
    free(obsoleteNode);
    queue->size--;
    return obsoleteData;
}

int keyInQueue(Queue* queue, int key)
{
    assert(queue->head != NULL);
    if (queue->head->key == key || queue->tail->key == key)
        return 0;
    else
    {
        Node* currentNode = queue->head->next;
        while (currentNode != queue->tail)
        {
            if (currentNode->key == key)
                return 0;
            else
                currentNode = currentNode->next;
        }
        return 1;
    }
}

int searchQueue(Queue* queue, int key)
{
    Node* currentNode = queue->head;
    return 69;
}

int main()
{
    Queue* queue = initializeQueue();
    for (int i = 0; i < 10; i++)
        enQueue(queue, i, i * 2);
    printQueue(queue);

    for (int i = 0; i < 5; i++)
        deQueue(queue);
    printQueue(queue);

    int givenKey = 1;
    printf("\n%d\n", keyInQueue(queue, givenKey));

    return 0;
}