#include "include/tests.h"

void linkedListTest()
{
    printf("Generating list...\n");
    LinkedList* mainList = initializeList();

    printf("Adding to list...\n");
    for (int i = 0; i < 10; i++)
    {
        if (i % 2 == 0)
            addFront(mainList, i * 2, i);
        else
            addLast(mainList, i * 2, i);    
    }

    printf("Original list:\n");
    printList(mainList);

    printf("Removing first and last nodes...\n");
    int firstData = removeFront(mainList);
    int lastData = removeLast(mainList);
    printf("The new list is...\n");
    printList(mainList);
    printf("The removed values are %d and %d for the first and last node respectively\n", firstData, lastData);

    int givenIndex = 5;
    printf("Adding at index %d...\n", givenIndex);
    addAtIndex(mainList, givenIndex, 5, 20);
    printf("New list:\n");
    printList(mainList);

    givenIndex = 3;
    printf("Removing at index %d...\n", givenIndex);
    removeAtIndex(mainList, givenIndex);
    printf("New list:\n");
    printList(mainList);

    int givenKey = 1;
    printf("Removing the first node with a the key %d...\n", givenKey);
    removeKey(mainList, givenKey);
    printf("New list:\n");
    printList(mainList);

}

void stackTest()
{
    printf("Initializing stack...\n");
    Stack* stack = initializeStack();

    printf("Pushing values to the stack...\n");
    for (int i = 0; i < 10; i++)
        push(stack, i * 2);

    printf("Original stack:\n");
    printStack(stack);

    printf("Popping down to nothing...\n");
    for (int i = 9; i >= 0; i--)
        printf("Popped value: %d\n", pop(stack));

    printf("New stack:\n");
    printStack(stack);
}

void queueTest()
{
    printf("Hello Queue!\n");
}

void runTests()
{
    printf("Running test: Linked List...\n\n");
    linkedListTest();

    printf("\n\nRunning test: Stack...\n\n");
    stackTest();

    printf("\n\nRunning test: Queue...\n\n");
    queueTest();
}