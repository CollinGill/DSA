#include <assert.h>
#include <math.h>
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

// Prints the heap as an array
void printHeap(BinaryHeap* binaryHeap)
{
    printf("[");
    for (int i = 0; i < binaryHeap->capacity; i++) {
        if (i == binaryHeap->capacity - 1)
            printf("%d", binaryHeap->array[i]);
        else
            printf("%d, ", binaryHeap->array[i]);
    }
    printf("]\n");
}

// Prints the heap in a more tree-like appearance
// Doesn't print all the way to the left for some reason, not really an issue
void fancyPrint(BinaryHeap* binaryHeap)
{
    for (int i = 0; i < binaryHeap->lastPosition; i++) {
        for (int space = binaryHeap->lastPosition; space > i; space--)
            printf(" ");

        for (int j = 0; j < pow(2, i) && j + pow(2, i) <= binaryHeap->lastPosition + 1; j++) {
            //if (j + pow(2, i) >= binaryHeap->lastPosition + 2) {
            //    printf("\n");
            //    return;
            //}
            if ((int)(j + pow(2, i) - 1) >= binaryHeap->lastPosition) {
                int currentNumber = binaryHeap->array[(int)(j + pow(2, i) - 1)];
                printf("%d\n\n", currentNumber);
                return;
            }
            int currentNumber = binaryHeap->array[(int)(j + pow(2, i) - 1)];
            printf("%d ", currentNumber);
        }
        printf("\n");
    }
}

BinaryHeap* initializeHeap(int capacity)
{
    BinaryHeap* binaryHeap = malloc(sizeof(BinaryHeap*));
    assert(binaryHeap); // making sure memory allocated correctly

    binaryHeap->lastPosition = -1;
    binaryHeap->capacity = capacity;
    binaryHeap->array = malloc(sizeof(int) * capacity);
    assert(binaryHeap->array); // making sure memory allocated correctly
    
    return binaryHeap;
}

// Swaps two indices of the array
void swap(int* array, int from, int to)
{
    int temp = array[from];
    array[from] = array[to];
    array[to] = temp;
}

// Compares the last element to the parent
// If the item is greater than the parent, swap with parent
// Go until root position
void trickleUp(BinaryHeap* binaryHeap, int position)
{
    if (position == 0)
        return;
    int parent = floor((position - 1) / 2);
    if (binaryHeap->array[parent] < binaryHeap->array[position]) {
        swap(binaryHeap->array, position, parent);
        trickleUp(binaryHeap, parent);
    }
}

// Used in removing a value from the heap
void trickleDown(BinaryHeap* binaryHeap, int parent)
{
    int left = 2 * parent + 1;
    int right = 2 * parent + 2;

    if (left == binaryHeap->lastPosition && binaryHeap->array[parent] < binaryHeap->array[left]) {
        swap(binaryHeap->array, parent, left);
        return;
    }
    if (right == binaryHeap->lastPosition && binaryHeap->array[parent] < binaryHeap->array[right]) {
        swap(binaryHeap->array, parent, right);
        return;
    }
    if (left >= binaryHeap->lastPosition || right >= binaryHeap->lastPosition)
        return;
    if (binaryHeap->array[left] > binaryHeap->array[right] && binaryHeap->array[parent] < binaryHeap->array[left]){
        swap(binaryHeap->array, parent, left);
        trickleDown(binaryHeap, left);
    } else if (binaryHeap->array[right] > binaryHeap->array[left] && binaryHeap->array[parent] < binaryHeap->array[right]){
        swap(binaryHeap->array, parent, right);
        trickleDown(binaryHeap, right);
    }
}

// Resizes the heap array in the for the binary tree
void resizeHeap(BinaryHeap* binaryHeap)
{
    int tempArr[binaryHeap->capacity];
    int oldSize = binaryHeap->capacity;

    for (int i = 0; i < binaryHeap->capacity; i++)
        tempArr[i] = binaryHeap->array[i];

    binaryHeap->capacity = binaryHeap->capacity * 2;
    binaryHeap->array = realloc(binaryHeap->array, sizeof(int) * binaryHeap->capacity);

    for (int i = 0; i <= binaryHeap->capacity; i++)
        if (i >= oldSize)
            binaryHeap->array[i] = 0;
        else
            binaryHeap->array[i] = tempArr[i];
    assert(binaryHeap->array); // making sure memory allocated correctly
}

// Inserts the value at the end of the heap and then recursively trickles up to the top until
// the tree follows the rule of the heap (i.e. min/max)
void add(BinaryHeap* binaryHeap, int value)
{
    if (binaryHeap->lastPosition + 1 == binaryHeap->capacity) {
        printf("Heap too small...\nResizing...\n");
        resizeHeap(binaryHeap);
        printf("Done, recalling add...\n");
    }
    binaryHeap->array[++binaryHeap->lastPosition] = value;
    trickleUp(binaryHeap, binaryHeap->lastPosition);
}

// Removes and returns the first value of the heap
int heapRemove(BinaryHeap* binaryHeap)
{
    int temp = binaryHeap->array[0];
    swap(binaryHeap->array, 0, binaryHeap->lastPosition);
    binaryHeap->lastPosition--;
    trickleDown(binaryHeap, 0);
    return temp;
}

int main()
{
    BinaryHeap* mainHeap = initializeHeap(10);
    printf("Testing add...\n");
    add(mainHeap, 0);
    add(mainHeap, 1);
    add(mainHeap, 2);
    add(mainHeap, 3);
    add(mainHeap, 4);
    add(mainHeap, 5);
    add(mainHeap, 6);
    add(mainHeap, 7);
    add(mainHeap, 8);
    add(mainHeap, 9);
    printHeap(mainHeap);
    fancyPrint(mainHeap);

    printf("Testing remove...\n");
    heapRemove(mainHeap);
    heapRemove(mainHeap);
    heapRemove(mainHeap);
    heapRemove(mainHeap);
    heapRemove(mainHeap);
    heapRemove(mainHeap);
    fancyPrint(mainHeap);

    return 0;
}
