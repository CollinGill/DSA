#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Struct for a node in a singly linked list
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

struct Node* createNode(int nodeData, char* nodeKey)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node*));
    node->data = nodeData;
    node->key = nodeKey;
    node->next = NULL;

    return node; 
}
struct List generateList()
{
    struct List list;
    list.size = 0;
    list.head = NULL;
    list.tail = NULL;

    return list;
}

void printNode(struct Node* node)
{
    if (node->next != NULL)
        printf("%s: %d -> ", node->key, node->data);
    else
        printf("%s: %d", node->key, node->data);
}

void printList(struct List list)
{
    if (list.head == NULL)
        printf("Empty list");
    else
    {
        struct Node* currentNode = list.head;
        while (currentNode != NULL)
        {
            printNode(currentNode);
            currentNode = currentNode->next;
        }
        currentNode = NULL;
        free(currentNode);
    }
    printf("\n");
}

struct List addFront(struct List list, struct Node* newNode)
{
    if (list.head == NULL)
    {
        list.head = list.tail = newNode;
        list.size++;
        return list;
    }
    else
    {
        newNode->next = list.head;
        list.head = newNode;
        list.size++;
        return list;
    }
}

// Complexity: O(1)
struct List addLast(struct List list, struct Node* newNode)
{
    if (list.head == NULL)
        list.head = list.tail = newNode;
    else
    {
        list.tail->next = newNode;
        list.tail = newNode;
    }

    list.size++;
    return list;
}

// Complexity: O(1)
struct List removeFirst(struct List list)
{
    if (list.head == NULL)
        return list;
    else if (list.head == list.tail)
    {
        list.head = list.tail = NULL;
        list.size--;
        return list;
    }
    else
    {
        struct Node* obsolete = list.head;
        list.head = list.head->next;
        free(obsolete);
        list.size--;
        return list;
    }
}

// Complexity: O(n)
struct List removeLast(struct List list)
{
    if (list.head == NULL)
        return list;
    else if (list.head == list.tail)
        return removeFirst(list);
    else
    {
        struct Node* previousNode = NULL;
        struct Node* currentNode = list.head;
        while (currentNode != list.tail)
        {
            previousNode = currentNode;
            currentNode = currentNode->next;
        }
        previousNode->next = NULL;
        list.tail = previousNode;
        list.size--;

        currentNode = NULL;
        free(currentNode);
        previousNode = NULL;
        free(previousNode);

        return list;
    }
}

// If there are nodes with duplicate keys, it will delete the first node with the key
// Complexity O(n)
struct List removeKey(struct List list, char* nodeKey)
{
    if (list.head == NULL)
        return list;
    else if (list.head == list.tail || list.head->key == nodeKey)
        return removeFirst(list);
    else if (list.tail->key == nodeKey)
        return removeLast(list);
    else 
    {
        // This portion of the code creates a seg fault
        // Creates two indexes to transverse the linked list
        struct Node* previousNode = list.head;
        struct Node* currentNode = list.head->next;
        
        // list.tail->key is already accounted for
        while(currentNode != list.tail)
        {
            if (currentNode->key == nodeKey)
            {
                previousNode->next = currentNode->next;
                free(currentNode);
                previousNode = NULL;
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
        // Garbage collection
        previousNode = currentNode = NULL;
        free(previousNode);
        free(currentNode);

        return list;
    }
}
bool findKey(struct List list, char* nodeKey)
{
    if (list.head == NULL)
        return false;
    else if ((list.head == list.tail && list.head->key == nodeKey) || list.head->key == nodeKey || list.tail->key == nodeKey)
        return true;
    else
    {
        struct Node* currentNode = list.head->next;

        while (currentNode != list.tail)
        {
            if (currentNode->key == nodeKey)
            {
                currentNode = NULL;
                free(currentNode);
                return true;
            }
        } 

        currentNode = NULL;
        free(currentNode);
    }

    return false;
}

// The code in the main function is used to test the above datastructures and associated functions
int main()
{
    // generate lists
    struct List list = generateList();
    struct List emptyList = generateList();
    struct List singleMember = generateList();

    // creating nodes
    struct Node* newNode = createNode(56, "dino");
    struct Node* newNode2 = createNode(2, "rainbow");
    struct Node* newNode3 = createNode(23, "spam");
    struct Node* newNode4 = createNode(69, "fish");
    struct Node* newNode5 = createNode(20, "dino");
    struct Node* newNode6 = createNode(37, "Japan");

    // removing/adding nodes to the list
    list = addLast(list, newNode);
    list = addFront(list, newNode3);
    list = addFront(list, newNode4);
    list = addLast(list, newNode6);
    list = addLast(list, newNode2);


    list = removeFirst(list);
    list = removeLast(list);
    list = removeKey(list, "spam");

    singleMember = addFront(singleMember, newNode5); 

    // print section
    printList(list);
    printf("Size: %d\n\n", list.size);

    printList(emptyList);
    printf("Size: %d\n\n", emptyList.size);

    printList(singleMember);
    printf("Size: %d\n\n", singleMember.size);

    if (findKey(list, "Japan"))
        printf("The key is in the list.\n");

    return 0;
}
