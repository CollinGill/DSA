#ifndef HEAP_H
#define HEAP_H

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Heap
{
    int lastPosition;
    int arrayCapacity;
    int* heapArr;
} Heap;

Heap* initializeHeap(int capacity);

void trickleUp(Heap* heap, int position);

void trickleDown(Heap* heap, int position);

void resizeHeap(Heap* heap);

void swap(int* array, int from, int to);

void heapAdd(Heap* heap, int value);

int heapRemove(Heap* heap);

#endif
