#include<stdlib.h>
#include<stdio.h>
#include <stdbool.h>

// A macro to define the max function
// basically to find the max of 2 numbers
// In this program it is to find the
// maximum between the left and the right 
// height of the tree
#define max(a,b) (a>b?a:b)

struct BSTNode {
    int data;
    struct BSTNode* left;
    struct BSTNode* right;
};

struct BSTNode* createNewNode(int data) {
    struct BSTNode* newNode = (struct BSTNode*)malloc(sizeof(struct BSTNode));
    (*newNode).data = data;
    (*newNode).left = (*newNode).right = NULL;
    return newNode;
}

struct BSTNode* insert(struct BSTNode* root, int data) {
    if(root == NULL) {
        root = createNewNode(data); 
    } else if(data <= (*root).data) {
        (*root).left = insert((*root).left, data);
    } else {
        (*root).right = insert((*root).right, data);
    }
    return root;
}

int findHeight(struct BSTNode* root) {
    if(root == NULL) {
        return -1;
    }
    return max(findHeight((*root).left), findHeight((*root).right)) + 1;
}

int main() {
    // A pointer to the root node of the tree.
    struct BSTNode* rootPointer = NULL;
    int height;

    rootPointer = insert(rootPointer, 15);
    rootPointer = insert(rootPointer, 10);
    rootPointer = insert(rootPointer, 20);
    rootPointer = insert(rootPointer, 25);
    rootPointer = insert(rootPointer, 8);
    rootPointer = insert(rootPointer, 12);

    height = findHeight(rootPointer);

    printf("Height of tree: %d\n", height);

    return 0;
}