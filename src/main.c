#include "include/linkedList.h"

int main()
{
    LinkedList mainList = initializeList();

    Node* node1 = createNode(4);
    Node* node2 = createNode(9);
    Node* node3 = createNode(69);
    Node* node4 = createNode(33);

    mainList = addFront(mainList, node1);
    mainList = addFront(mainList, node2);
    mainList = addLast(mainList, node3);
    mainList = addLast(mainList, node4);

    printLinkedList(mainList);

    return 0;
}