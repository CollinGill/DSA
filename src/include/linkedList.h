#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct LNode
{
    int key;
    int data;
    struct LNode* next;
} LNode;

typedef struct LinkedList
{
    struct LNode* head;
    struct LNode* tail;
    int size;
} LinkedList;

LNode* createNode(int key, int data);

LinkedList initializeList();

void printNode(LNode* node);

void printLinkedList(LinkedList list);

LinkedList addFront(LinkedList list, LNode* node);

LinkedList addLast(LinkedList list, LNode* node);

LinkedList removeFront(LinkedList list);

LinkedList removeLast(LinkedList list);

LinkedList removeKey(LinkedList list, int key);

#endif