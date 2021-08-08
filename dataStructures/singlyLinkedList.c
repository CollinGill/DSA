#include "stdio.h"
#include "stdlib.h"

// Struct for a node in a singly linked list
struct Node
{
    int data;
    struct Node* next;
};

struct List
{
    struct Node* head;
};

struct List generateList()
{
    struct List list;

    // Inialize the nodes as pointers
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* final = NULL;

    // Allocate the memory in the heap
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    final = (struct Node*)malloc(sizeof(struct Node));

    // Set variables
    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = final;

    final->data = 3;
    final->next = NULL;

    list.head = head; 

    return list;
}

void printNode(struct Node* node)
{
    if (node->next != NULL)
        printf("%d -> ", node->data);
    else
        printf("%d", node->data);
}

void printList(struct List list)
{
    struct Node* currentNode = list.head;
    while (currentNode != NULL)
    {
        printNode(currentNode);
        currentNode = currentNode->next;
    }
    printf("\n");
}

// Unsure where to implement this
void insertAfter(struct Node* node, struct Node* newNode)
{
    newNode->next = node->next;
    node->next = newNode;
}

struct List insertBeginning(struct List list, struct Node* newNode)
{
    newNode->next = list.head;
    list.head = newNode;
    return list;
}

// Unsure where to implement this
void removeAfter(struct Node* node)
{
    struct Node* obsolete = node->next;
    node->next = node->next->next;
    free(obsolete);
}

struct List removeBeginning(struct List list)
{
    struct Node* obsolete = list.head;
    list.head = list.head->next;
    free(obsolete);
    return list;
}

int main()
{
    struct List list = generateList();
    printList(list);

    struct Node* random = NULL;
    random = (struct Node*)malloc(sizeof(struct Node*));
    random->data = 5;
    random->next = NULL;

    list = insertBeginning(list, random);
    printList(list);

    list = removeBeginning(list);
    printList(list);
    return 0;

    // When inserting or removing an element to the list the worst time is O(n) where n is the size of the list
    // This is due to the list being unable to iterate backwards causing you to iterate forwards untill you find 
    // the node you would like to insert or remove after
}
