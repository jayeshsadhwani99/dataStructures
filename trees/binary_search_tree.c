// The implementation will be quite
// similar to the linked list implementation.
// Cause the tree is just a non-linear 
// linked list.
#include<stdlib.h>
#include<stdio.h>

// bool does not exist as a keyword pre-C99.
// It's a macro declared in <stdbool.h>.
#include <stdbool.h>

// A structure for a tree,
// which contains a data and a 
// pointer to the left and the right node.
struct BSTNode {
    int data;
    struct BSTNode* left;
    struct BSTNode* right;
};

// This is just to create a new node
// and allocate memory for it.
struct BSTNode* createNewNode(int data) {
    // We allocate a new memory space for the node.
    struct BSTNode* newNode = (struct BSTNode*)malloc(sizeof(struct BSTNode));

    // Add the data and set the left and right nodes as NULL
    (*newNode).data = data;
    (*newNode).left = (*newNode).right = NULL;

    return newNode;
}

// Insert data in the tree
struct BSTNode* insert(struct BSTNode* root, int data) {
    // We need to handle various cases
    // 1. The tree is empty.
    // 2. The data is less than or equal to the root.
    // 3. The data is greater than the root.

    // Tree is empty
    if(root == NULL) {
        root = createNewNode(data); 
    } else if(data <= (*root).data) {
        // Case 2 - less than or equal to
        // Since the tree is a recursive
        // data structure, we can call the same
        // function again.
        (*root).left = insert((*root).left, data);
    } else {
        // Case 3 - greater than, would
        // execute just like the case 2
        (*root).right = insert((*root).right, data);
    }

    // return the root
    return root;
}

// To search the data in the binary tree,
// if the data is present, this function 
// will return true, else false.
bool search(struct BSTNode* root, int data) {
    // We can have multiple cases
    // 1. The tree is empty - root = NULL
    // 2. The data is equal to the root
    // 3. The data is less than the root- 
    //    Here, we recusively call the function
    //    again with the root as left node.
    // 4. The data is greater than the root-
    //    Here, we recusively call the function
    //    again with the root as right node.

    // We need to check if the root is NULL
    if(root == NULL) {
        return false;
    } else if((*root).data == data) {
        // Case 2 -
        // If root is the data
        return true;
    } else if((*root).data < data) {
        // Case 3 - 
        // If data is lesser than the 
        // root data
        return search((*root).right, data);
    } else {
        return search((*root).left, data);
    }
}

int main() {
    // A pointer to the root node of the tree.
    struct BSTNode* rootPointer = NULL;
    int number;

    rootPointer = insert(rootPointer, 15);
    rootPointer = insert(rootPointer, 10);
    rootPointer = insert(rootPointer, 20);
    rootPointer = insert(rootPointer, 25);
    rootPointer = insert(rootPointer, 8);
    rootPointer = insert(rootPointer, 12);

    printf("Enter the number to search: ");
    scanf("%d", &number);

    if(search(rootPointer, number)) {
        printf("The number is present in the tree\n");
    } else {
        printf("The number is not present in the tree\n");
    }

    return 0;
}