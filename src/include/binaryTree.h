#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct BinaryNode
{
    int value;
    struct BinaryNode* left;
    struct BinaryNode* right;
} BinaryNode;

typedef struct BinaryTree
{
    struct BinaryNode* root;
    int maxHeight;
} BinaryTree;

BinaryNode* createBinaryNode(int value);
BinaryTree* initializeBinaryTree();

void insertBT(BinaryTree* binaryTree, int value);

void printBT();

#endif
