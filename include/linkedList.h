#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int key;
    int data;
    struct Node* next;
} Node;

typedef struct LinkedList
{
    struct Node* head;
    struct Node* tail;
    int size;
} LinkedList;

LinkedList* initializeList();

Node* createNode(int key, int data);

void printNode(Node* node);

void printList(LinkedList* list);

void addFront(LinkedList* list, int data, int key);

void addLast(LinkedList* list, int data, int key);

void addAtIndex(LinkedList* list, int index, int data, int key);

int removeFront(LinkedList* list);

int removeLast(LinkedList* list);

int removeAtIndex(LinkedList* list, int index);

int removeKey(LinkedList* list, int key);

int keyExists(LinkedList* list, int key);

#endif