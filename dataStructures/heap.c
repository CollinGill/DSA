#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// -- Binary Heap -- //

// Heaps either be implement by a linked list
// Or as an array where the relation between children and parent (For indices) is
// children: 2 * index of parrent + 1, 2 * index of parent + 2
// parent: floor((child - 1)/2)

typedef struct BinaryHeap
{
    int* array;
    int lastPosition;
    int capacity;
} BinaryHeap;

BinaryHeap* initializeHeap(int capacity)
{
    BinaryHeap* binaryHeap = malloc(sizeof(BinaryHeap*));
    assert(binaryHeap); // making sure memory allocated correctly

    binaryHeap->lastPosition = 0;
    binaryHeap->capacity = capacity;
    binaryHeap->array = malloc(sizeof(int) * capacity);
    assert(binaryHeap->array); // making sure memory allocated correctly
    
    return binaryHeap;
}

// Inserts the value at the end of the heap and then recursively trickles up to the top until
// the tree follows the rule of the heap (i.e. min/max)
void insertValue(BinaryHeap* binaryHeap, int value)
{
    for (int i = 0; i < binaryHeap->capacity; i++) {
        binaryHeap->array[i] = i; 
    }
    for (int i = 0; i < binaryHeap->capacity; i++) {
        printf("%d\n", binaryHeap->array[i]);
    }
}

int main(int argc, char* argv[])
{
    BinaryHeap* mainHeap = initializeHeap(15);
    insertValue(mainHeap, 15);

    return 0;
}
