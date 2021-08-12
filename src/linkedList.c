#include "include/linkedList.h"

LinkedList* initializeList()
{
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList*));
    list->head = list->tail = NULL;
    list->size = 0;
    return list;
}

Node* createNode(int key, int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node*));
    newNode->key = key;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printNode(Node* node)
{
    if (node->next != NULL)
        printf("(%d|%d) -> ", node->key, node->data);
    else
        printf("(%d|%d)", node->key, node->data);
}

void printList(LinkedList* list)
{
    if (list->head == NULL)
        printf("\n");
    else
    {
        Node* currentNode = list->head;
        while (currentNode != NULL)
        {
            printNode(currentNode);
            currentNode = currentNode->next;
        }
        currentNode = NULL;
        free(currentNode);
    }
    printf("Size: %d\n", list->size);
}

void addFront(LinkedList* list, int data, int key)
{
    Node* node = createNode(key, data);

    if (list->head == NULL)
        list->head = list->tail = node;
    else
    {
        node->next = list->head;
        list->head = node;
    }
    list->size++;
}

void addEnd(LinkedList* list, int data, int key)
{
    if (list->head == NULL)
        addFront(list, data, key);
    else
    {
        Node* node = createNode(key, data);
        list->tail->next = node;
        list->tail = list->tail->next;
        list->size++;
    }
}

void addAtIndex(LinkedList* list, int index, int data, int key)
{
    assert(list->size > 0 && list->size > index);
    int i = 0;
    Node* node = createNode(key, data);
    Node* currentNode = list->head;
    Node* previousNode = NULL;
    while (currentNode != NULL)
    {
        if (i == index)
        {
            previousNode->next = node;
            node->next = currentNode;
            list->size++;
            break;
        }
        else
        {
            previousNode = currentNode;
            currentNode = currentNode->next;
            i++;
        }
    }
    currentNode = previousNode = NULL;
    free(currentNode);
    free(previousNode);
}

int removeFront(LinkedList* list)
{
    assert(list->head != NULL);
    int obsoleteData = list->head->data;
    Node* obsolete = list->head;

    if (list->head = list->tail)
        list->head = list->tail = NULL;
    else
        list->head = list->head->next;

    free(obsolete);
    list->size--;
    return obsoleteData;
}

int removeLast(LinkedList* list)
{
    assert(list->head != NULL);
    if (list->head == list->tail)
        removeFront(list);
    else
    {
        int obsoleteData = list->tail->data;
        Node* previousNode = NULL;
        Node* currentNode = list->head;
        while (currentNode != NULL)
        {
            if (currentNode == list->tail)
            {
                previousNode->next = NULL;
                list->tail = previousNode;
                list->size--;
                previousNode = currentNode = NULL;
                free(previousNode);
                free(currentNode);
                return obsoleteData;
            }
            else
            {
                previousNode = currentNode;
                currentNode = currentNode->next;
            }
        }
        previousNode = currentNode = NULL;
        free(previousNode);
        free(currentNode);
    }
}

int removeAtIndex(LinkedList* list, int index)
{
    assert(list->size > 0 && list->size > index);
    int obsoleteData;
    if (list->head == list->tail)
    {
        obsoleteData = list->head->data;
        list->head = list->tail = NULL;
        list->size--;
        return obsoleteData;
    }
    else
    {
        int i = 0;
        Node* previousNode = NULL;
        Node* currentNode = list->head;
        while (currentNode != NULL)
        {
            if (i == index)
            {
                obsoleteData = currentNode->data;
                previousNode->next = currentNode->next;
                previousNode = currentNode = NULL;
                free(previousNode);
                free(currentNode);
                return obsoleteData;
            }
            else
            {
                previousNode = currentNode;
                currentNode = currentNode->next;
                i++;
            }
        }
    }
}