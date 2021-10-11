#include "include/heap.h"

Heap* initializeHeap(int capacity)
{
    Heap* newHeap = malloc(sizeof(Heap*));
    newHeap->lastPosition = -1;
    newHeap->arrayCapacity = capacity;
    newHeap->heapArr = calloc(capacity, sizeof(int*));
    return newHeap;
}

void trickleUp(Heap* heap, int parent);

void trickleDown(Heap* heap, int parent);

void resizeHeap(Heap* heap);

void swap(int* array, int from, int to);

void heapAdd(Heap* heap, int value);

void heapRemove(Heap* heap);
