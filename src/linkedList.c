#include <stdio.h>
#include <stdlib.h>
#include "include/linkedList.h"

Node* createNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node*));
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

void printNode(Node* node)
{
    if (node->next != NULL)
        printf("%d -> ", node->data);
    else
        printf("%d", node->data);
}

void printLinkedList(LinkedList list)
{
    if (list.head == list.head)
        printf("");
    Node* currentNode = list.head;
    while (currentNode != NULL)
    {
        printNode(currentNode);
        currentNode = currentNode->next;
    }

    printf("\nSize: %d\n", list.size);
}

LinkedList addFront(LinkedList list, Node* node)
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

LinkedList addLast(LinkedList list, Node* node)
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