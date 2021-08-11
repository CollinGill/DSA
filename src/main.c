#include "include/linkedList.h"

int main()
{
    LinkedList mainList = initializeList();

    Node* node1 = createNode(4);
    Node* node2 = createNode(9);

    mainList = addFront(mainList, node1);
    mainList = addFront(mainList, node2);

    printLinkedList(mainList);

    return 0;
}