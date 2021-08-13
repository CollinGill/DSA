#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Frame
{
    int data;
    struct Frame* next;
} Frame;

typedef struct Stack
{
    struct Frame* head;
    int size;
} Stack;

Stack* initializeStack();

Frame* createFrame(int data);

void printStack(Stack* stack);

void push(Stack* stack, int data);

int pop(Stack* stack);

#endif