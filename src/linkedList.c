#include <stdio.h>
#include <stdlib.h>
#include "include/linkedList.h"

LNode* createNode(int key, int data)
{
    LNode* newNode = (LNode*)malloc(sizeof(LNode*));

    newNode->key = key;
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

LinkedList initializeList()
{
    LinkedList list;
    list.head = NULL;
    list.tail = NULL;
    list.size = 0;

    return list;
}

void printNode(LNode* node)
{
    if (node->next != NULL)
        printf("(%d|%d) -> ", node->key, node->data);
    else
        printf("(%d|%d)", node->key, node->data);
}

void printLinkedList(LinkedList list)
{
    if (list.head == list.head)
        printf("");
    LNode* currentNode = list.head;
    while (currentNode != NULL)
    {
        printNode(currentNode);
        currentNode = currentNode->next;
    }

    printf("\nSize: %d\n", list.size);
}

LinkedList addFront(LinkedList list, LNode* node)
{
    if (list.head == NULL)
    {
        list.head = list.tail = node;
        list.size++;
        return list;
    }
    else
    {
        node->next = list.head;
        list.head = node;
        list.size++;
        return list;
    }
}

LinkedList addLast(LinkedList list, LNode* node)
{
    if (list.head == NULL)
        return addFront(list, node);
    else
    {
        list.tail->next = node;
        list.tail = list.tail->next;
        list.size++;
        return list;
    }
}

LinkedList removeFront(LinkedList list)
{
    if (list.head == NULL)
        return list;
    else if (list.head == list.tail)
    {
        LNode* obsolete = list.head;
        list.head = list.tail = NULL;
        list.size--;
        free(obsolete);
        return list;
    }
    else
    {
        LNode* obsolete = list.head;
        list.head = list.head->next;
        free(obsolete);
        list.size--;
        return list;
    }
}

LinkedList removeLast(LinkedList list)
{
    if (list.head == NULL)
        return list;
    else if (list.head == list.tail)
        return removeFront(list);
    else
    {
        LNode* currentNode = list.head;
        while (currentNode != list.tail)
        {
            if (currentNode->next == list.tail)
            {
                LNode* obsolete = currentNode->next;
                list.tail = currentNode;
                currentNode->next = NULL;
                free(obsolete);
                list.size--;
                return list;
            }
            else
                currentNode = currentNode->next;
        }
    }
}

LinkedList removeKey(LinkedList list, int key)
{
    if (list.head == NULL)
        return list;
    else if (list.head == list.tail || list.head->key == key)
        return removeFront(list);
    else if(list.tail->key == key)
        return removeLast(list);
    else
    {
        LNode* currentNode = list.head->next;
        LNode* previousNode = list.head;

        while(currentNode != list.tail)
        {
            if (currentNode->key == key)
            {
                previousNode->next = currentNode->next;
                previousNode = NULL;
                free(currentNode);
                free(previousNode);
                list.size--;
                return list;
            }
            else
            {
                previousNode = currentNode;
                currentNode = currentNode->next;
            }
        }

        currentNode = previousNode = NULL;
        free(currentNode);
        free(previousNode);
        return list;
    }
}