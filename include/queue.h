#ifndef QUEUE_H
#define QUEUE_H 

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct QNode
{
    int key;
    int data;
    struct QNode* previous;
    struct QNode* next;
} QNode;

typedef struct Queue
{
    struct QNode* head;
    struct QNode* tail;
    int size;
} Queue;

QNode* createQNode(int key, int data);
Queue* initializeQueue();
void printQNode(QNode* node);
void printQueue(Queue* queue);
void enQueue(Queue* queue, int key, int data);
int deQueue(Queue* queue);
int keyInQueue(Queue* queue, int key);

#endif
