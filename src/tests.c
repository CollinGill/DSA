#include <stdio.h>
#include "include/tests.h"

void linkedListTest()
{
    printf("Generating list and nodes...\n");
    LinkedList mainList = initializeList();

    LNode* node1 = createNode(1, 4);
    LNode* node2 = createNode(2, 9);
    LNode* node3 = createNode(3, 69);
    LNode* node4 = createNode(4, 33);
    LNode* node5 = createNode(5, 200);

    printf("Adding to list...\n");
    mainList = addFront(mainList, node1);
    mainList = addFront(mainList, node2);
    mainList = addLast(mainList, node3);
    mainList = addLast(mainList, node4);
    mainList = addLast(mainList, node5);

    printf("Original list:\n");
    printLinkedList(mainList);

    printf("Removing first and last nodes...\n");
    mainList = removeFront(mainList);
    mainList = removeLast(mainList);
    printLinkedList(mainList);

    printf("Removing the first node with a given key...\n");
    mainList = removeKey(mainList, 3);

    printLinkedList(mainList);
}