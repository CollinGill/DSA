#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

typedef struct LinkedList
{
    struct Node* head;
    struct Node* tail;
    int size;
} LinkedList;

Node* createNode(int data);

LinkedList initializeList();

void printNode(Node* node);

void printLinkedList(LinkedList list);

Node* addFront(LinkedList list, Node* node);

#endif