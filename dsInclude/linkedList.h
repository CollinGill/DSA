#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct Node
{
    int data;
    char* key;
    struct Node* next;
};

struct List
{
    struct Node* head;
    struct Node* tail;
    int size;
};

#endif