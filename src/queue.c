#include "include/queue.h"

QNode* createQNode(int key, int data)
{
    QNode* newNode = (QNode*)malloc(sizeof(QNode*));
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

void printQNode(QNode* node)
{
    printf("\t(%d|%d)\n", node->key, node->data);
}

void printQueue(Queue* queue)
{
    QNode* currentNode = queue->head;
    while (currentNode != NULL)
    {
        printQNode(currentNode);
        currentNode = currentNode->next;
    }
    printf("Size: %d\n", queue->size);
}

void enQueue(Queue* queue, int key, int data)
{
    QNode* node =  createQNode(key, data);
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
    QNode* obsoleteNode = queue->tail;
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
        QNode* currentNode = queue->head->next;
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
