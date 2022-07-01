// There are 2 approaches to find 
// the max and min in a binary tree:
// 1. Recursive approach
// 2. Iterative approach
#include<stdlib.h>
#include<stdio.h>
#include <stdbool.h>

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

// Minimum

// Approach 1: Recursive approach
// We keep checking if the left node 
// is NULL, until we reach there.
int min_recursive(struct BSTNode* root) {
    if(root == NULL) {
        return -1;
    }
    if((*root).left == NULL) {
        return (*root).data;
    }
    return min_recursive((*root).left);
}

// Approach 2: Iterative approach
// Here we iterate through all the
// elements in the tree, and go as
// left as we can
int min_iterative(struct BSTNode* root) {
    struct BSTNode* current = root;
    while((*current).left != NULL) {
        current = (*current).left;
    }

    return (*current).data;
}

// Maximum

// Approach 1: Recursive approach
// We keep checking if the left node 
// is NULL, until we reach there.
int max_recursive(struct BSTNode* root) {
    if(root == NULL) {
        return -1;
    }
    if((*root).right == NULL) {
        return (*root).data;
    }

    return max_recursive((*root).right);
}

// Approach 2: Iterative approach
// Here we iterate through all the
// elements in the tree, and go as
// left as we can
int max_iterative(struct BSTNode* root) {
    struct BSTNode* current = root;
    while((*current).right != NULL) {
        current = (*current).right;
    }

    return (*current).data;
}


int main() {
    // A pointer to the root node of the tree.
    struct BSTNode* rootPointer = NULL;
    int min_i, min_r, max_i, max_r;

    rootPointer = insert(rootPointer, 15);
    rootPointer = insert(rootPointer, 10);
    rootPointer = insert(rootPointer, 20);
    rootPointer = insert(rootPointer, 25);
    rootPointer = insert(rootPointer, 8);
    rootPointer = insert(rootPointer, 12);

    min_i = min_iterative(rootPointer);
    max_i = max_iterative(rootPointer);

    min_r = min_recursive(rootPointer);
    max_r = max_recursive(rootPointer);

    printf("Min Iterative: %d\n", min_i);
    printf("Max Iterative: %d\n", max_i);

    printf("Min Recursive: %d\n", min_r);
    printf("Max Recursive: %d\n", max_r);

    return 0;
}