#include "include/binaryTree.h"

BinaryNode* createBinaryNode(int value)
{
    BinaryNode* newNode = malloc(sizeof(BinaryNode*));
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BinaryTree* initializeBinaryTree()
{
    BinaryTree* newBT = malloc(sizeof(BinaryTree*));
    newBT->root = NULL;
    newBT->maxHeight = 0;
    return newBT;
}

void insertBT(BinaryTree* binaryTree, int value)
{
    BinaryNode* newNode = createBinaryNode(value);
    if (binaryTree->root == NULL)
    {
        binaryTree->root = newNode;
        binaryTree->maxHeight++;
        return;
    }
    else
    {
        // TODO: Implemet the rest of the function
        printf("NOT IMPLEMENTED YET - INSERT BINARY TREE\n");
        return;
    }
}

void printBT();
