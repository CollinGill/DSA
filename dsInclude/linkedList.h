#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct
{
    int data;
    struct Node* next;
} Node;

typedef struct
{
    struct Node* head;
    struct Node* tail;
    int size;
} LinkedList;

#endif