#include<stdlib.h>
#include<stdio.h>
#include <stdbool.h>

// These ranges are for approach 3,
// wherein we define the range in
// which the data in the node can be in.
#define INT_MAX 2147483647
#define INT_MIN -2147483648

struct BTNode {
    int data;
    struct BTNode* left;
    struct BTNode* right;
};

// Basic functions to test the tree
struct BTNode* createNewNode(int data) {
    struct BTNode* newNode = (struct BTNode*)malloc(sizeof(struct BTNode));
    (*newNode).data = data;
    (*newNode).left = (*newNode).right = NULL;
    return newNode;
}

struct BTNode* insert(struct BTNode* root, int data) {
    if(root == NULL) {
        root = createNewNode(data); 
    } else if(data <= (*root).data) {
        (*root).left = insert((*root).left, data);
    } else {
        (*root).right = insert((*root).right, data);
    }
    return root;
}

// Approach 1
// To have the first approach, we'll need 
// to check for the conditions it dictates
// so, we'll write a function for each of these
// conditions.

// Condition 1:
// To check if all the elements in the 
// left subtree(generally any tree) are lesser
// This function will return true if 
// the condition is satisfied, else false
bool isSubtreeLesser(struct BTNode* root, int value) {
    // The exit condition for recusrion
    if(root == NULL) {
        return true;
    }

    // Since we need to check for the whole tree,
    // we'll call this function recursively for
    // both the left and right subtrees
    bool left_subtree_lesser = isSubtreeLesser((*root).left, value);
    bool right_subtree_lesser = isSubtreeLesser((*root).right, value);

    // We obviously also have to check for the root node
    bool root_lesser = (*root).data < value;

    if (root_lesser && left_subtree_lesser && right_subtree_lesser) {
        return true;
    } else {
        return false;
    }
}

// Condition 2:
// To check if all the elements in the 
// right subtree(generally any tree) are greater
// Similar to condition 1, this function 
// will return true if 
// the condition is satisfied, else false
bool isSubtreeGreater(struct BTNode* root, int value) {
    // The exit condition for recusrion
    if(root == NULL) {
        return true;
    }

    // Since we need to check for the whole tree,
    // we'll call this function recursively for
    // both the left and right subtrees
    bool left_subtree_greater = isSubtreeGreater((*root).left, value);
    bool right_subtree_greater = isSubtreeGreater((*root).right, value);

    // We obviously also have to check for the root node
    bool root_greater = (*root).data > value;

    if (root_greater && left_subtree_greater && right_subtree_greater) {
        return true;
    } else {
        return false;
    }
}

// This is the function to wrap the
// conditions and return the actual
// result - whether the tree is a BST or not
bool isBST_1(struct BTNode* root) {
    // The 4 conditions are:
    // 1. All the elements in the left 
    //    subtree are lesser
    // 2. All the elements in the right
    //    subtree are greater
    // 3. The left sub-tree is BST
    // 4. The right sub-tree is BST

    // The base case,
    // to end the recursion
    if(root == NULL) {
        return true;
    }
    
    bool condition_1 = isSubtreeLesser((*root).left, (*root).data);
    bool condition_2 = isSubtreeGreater((*root).right, (*root).data);

    bool condition_3 = isBST_1((*root).left);
    bool condition_4 = isBST_1((*root).right);

    if(condition_1 && condition_2 && condition_3 && condition_4) {
        return true;
    } else {
        return false;
    }
    
}

// Approach 3
// It will be a recursive function and
// would check for the permissible range
// for each node
bool isBSTUtil(struct BTNode* root, int maxValue, int minValue) {
    // The exit condition, for recursion
    if(root == NULL) {
        return true;
    }

    bool check_range_root = ((*root).data > minValue) && ((*root).data < maxValue);

    // We supply the upper bound when checking for 
    // the left sub-tree
    bool check_range_left = isBSTUtil((*root).left, (*root).data, minValue);

    // We supply the lower bound when checking for 
    // the right sub-tree
    bool check_range_right = isBSTUtil((*root).right, maxValue, (*root).data);

    if(check_range_root && check_range_left && check_range_right) {
        return true;
    } else {
        return false;
    }

}

bool isBST_3(struct BTNode* root) {
    return isBSTUtil(root, INT_MAX, INT_MIN);
}

int main() {
    // A pointer to the root node of the tree.
    struct BTNode* rootPointer = NULL;

    // Since we are using these functions to test,
    // ideally all of the trees we test will be
    // BSTs.
    rootPointer = insert(rootPointer, 7);
    rootPointer = insert(rootPointer, 10);
    rootPointer = insert(rootPointer, 9);
    rootPointer = insert(rootPointer, 1);
    rootPointer = insert(rootPointer, 6);

    // Check for BST
    // Approach 1:
    printf("Approach 1:\n");
    if(isBST_1(rootPointer)) {
        printf("The tree is a BST\n");
    } else {
        printf("The tree is not a BST\n");
    }

    // Approach 3:
    printf("Approach 3:\n");
    if(isBST_3(rootPointer)) {
        printf("The tree is a BST\n");
    } else {
        printf("The tree is not a BST\n");
    }

    return 0;
}