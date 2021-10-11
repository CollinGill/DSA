#include "include/heap.h"

Heap* initializeHeap(int capacity)
{
    Heap* newHeap = malloc(sizeof(Heap*));
    newHeap->lastPosition = -1;
    newHeap->arrayCapacity = capacity;
    newHeap->heapArr = calloc(capacity, sizeof(int*));
    assert(newHeap);
    return newHeap;
}

void trickleUp(Heap* heap, int position)
{
    if (position == 0)
	return;
    int parent = floor((position - 1) / 2);
    if (heap->heapArr[parent] < heap->heapArr[position]) {
	swap(heap->heapArr, position, parent);
	trickleUp(heap, parent);
    }
}

void trickleDown(Heap* heap, int parent)
{
    left = 2 * parent + 1;
    right = 2 * parent + 2;

    if (left == heap->lastPosition && heap->heapArr[parent] < heap->heapArr[left])
	swap(heap->heapArr, parent, left); return;
    if (right == heap->lastPosition && heap->heapArr[parent] < heap->heapArr[right])
	swap(heap->heapArr, parent, right); return;
    if (left >= heap->lastPosition || right >= heap->lastPosition)
	return;
    if (heap->heapArr[left] > heap->heapArr[right] && heap->heapArr[parent] < heap->heapArr[left]) {
	swap(heap->heapArr, parent, left);
	trickleDown(heap, left);
    } else if (heap->heapArr[right] > heap->heapArr[left] && heap->heapArr[parent] < heap->heapArr[right]) {
	swap(heap->heapArr, parent, right);
	trickleDown(heap, right);
    }
}

void resizeHeap(Heap* heap)
{
    int* tempArray = malloc(sizeof(int*) * heap->arrayCapacity);
    for (int i = 0; i < heap->arrayCapacity; i++)
        tempArray[i] = heap->heapArr[i];
    int oldCapacity = heap->arrayCapacity;

    heap->arrayCapacity = heap->arrayCapacity * 2;
    heap->heapArr = calloc(heap->arrayCapacity, sizeof(int*));
    for (int i = 0; i < heap->arrayCapacity; i++)
        heap->heapArr[i] = tempArray[i];
    assert(heap->heapArr);
}

void swap(int* array, int from, int to)
{
    int temp = array[from];
    array[from] = array[to];
    array[to] = temp;
}

void heapAdd(Heap* heap, int value)
{
    if (heap->lastPosition == heap->arrayCapacity)
        resizeHeap(heap);
    heap->heapArr[++heap->lastPosition] = value;
    trickleDown(heap, heap->lastPosition);
}

int heapRemove(Heap* heap)
{
    int temp = heap->heapArr[0];

    swap(heap, 0, heap->lastPosition);
    heap->lastPosition--;
    trickleDown(heap, 0);
    
    return temp;
}
