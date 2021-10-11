#include "include/stack.h"

Stack* initializeStack()
{
    Stack* newStack = (Stack*)malloc(sizeof(Stack*));
    newStack->head = NULL;
    newStack->size = 0;
    return newStack;
}

Frame* createFrame(int data)
{
    Frame* newFrame = (Frame*)malloc(sizeof(Frame*));
    newFrame->data = data;
    newFrame->next = NULL;
    return newFrame;
}

void printStack(Stack* stack)
{
    if (stack->head == NULL)
    {
        printf("\n");
        printf("Stack size: %d\n", stack->size);
    }
    else
    {
        Frame* currentFrame = stack->head;
        while (currentFrame != NULL)
        {
            printf("%d\n", currentFrame->data);
            currentFrame = currentFrame->next;
        }
        printf("Stack size: %d\n", stack->size);
    }
}

void push(Stack* stack, int data)
{
    Frame* newFrame = createFrame(data);
    newFrame->next = stack->head;
    stack->head = newFrame;
    stack->size++;
}

int pop(Stack* stack)
{
    assert(stack->head != NULL);

    int data = stack->head->data;
    Frame* obsolete = stack->head;
    stack->head = stack->head->next;
    free(obsolete);
    stack->size--;
    return data;
}