#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

typedef struct Stack 
{
    struct Node* head;
    int size;
} Stack;

Node* createNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node*));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Stack* initializeStack()
{
    Stack* newStack = (Stack*)malloc(sizeof(Stack*));
    newStack->head = NULL;
    newStack->size = 0;
    return newStack;
}

void printStack(Stack* stack)
{
    Node* currentNode = stack->head;
    while (currentNode != NULL)
    {
        printf("%d\n", currentNode->data);
        currentNode = currentNode->next;
    }
}

void push(Stack* stack, int data)
{
    Node* node = createNode(data);
    node->next = stack->head;
    stack->head = node;
    stack->size++;
}

int pop(Stack* stack)
{
    if (stack->head == NULL)
        exit(EXIT_FAILURE);
    else
    {
        int data = stack->head->data;
        Node* obsolete = stack->head;
        stack->head = stack->head->next;
        free(obsolete);
        stack->size--;
        return data;
    }
}

int main()
{
    Stack* stack = initializeStack();
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    int poppedValue = pop(stack);

    printStack(stack);
    printf("\nPopped value: %d\n", poppedValue);

    return 0;
}