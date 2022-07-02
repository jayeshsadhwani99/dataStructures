#include<iostream>

using namespace std;

struct BSTNode {
    int data;
    BSTNode* left;
    BSTNode* right;
};

// Basic functions to test the tree
BSTNode* createNewNode(int data) {
    BSTNode* newNode = new BSTNode();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode* insert(BSTNode* root, int data) {
    if(root == NULL) {
        root = createNewNode(data); 
    } else if(data <= root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

void print(BSTNode* root) {
    if(root == NULL) return;
    print(root->left);
    cout << root->data << " ";
    print(root->right);
}

// This is to find the node we want to
// find the successor of. This will be 
// an operation with the complexity of
// O(h), where h is the height of the tree.
BSTNode* find(BSTNode* root, int data) {
    if(root == NULL) {
        return root;
    } else if(data < root->data) {
        return find(root->left, data);
    } else if(data > root->data) {
        return find(root->right, data);
    } else {
        return root;
    }
}

// This function will help to find the
// minimum value in a BST. This will help
// us to find the minimum value in the right
// sub-tree, which will be the next element 
// if the node has a right sub-tree.
BSTNode* findMin(BSTNode* root) {
    if(root == NULL) {
        return root;
    }

    // To find the minimum value
    // in the right sub-tree
    while(root->left != NULL) {
        root = root->left;
    }

    return root;
}

// The function to get the successor of 
// a node in a BST. Overall, the time
// complexity of this function is O(h),
// where h is the height of the tree.
BSTNode* getSuccessor(BSTNode* root, int data) {
    // The first step would be 
    // to search the tree and find
    // the node
    BSTNode* current = find(root, data);

    // If the node is not found,
    // return NULL
    if(current == NULL) {
        return NULL;
    }

    // Case 1: If the node has a right sub-tree
    if(current->right != NULL) {
        return findMin(current->right);
    }

    // Case 2: If the node has no right sub-tree
    else {
        BSTNode* successor = NULL;
        BSTNode* ancestor = root;

        // To find the ancestor, we'll
        // go through the tree and find the
        // node that is the parent of the
        // current node.

        // Here we are using the property of the BST
        // that the value in left is lesser and the
        // value in right is greater than the root.
        while(ancestor != current) {
            if(current->data < ancestor->data) {
                // The deepest node for which the 
                // current node is in left
                successor = ancestor;
                ancestor = ancestor->left;
            } else {
                ancestor = ancestor->right;
            }
        }

        // Here the successor will either be
        // NULL or it will be the address
        // of some node
        // NOTE: Node with the maximum value will not
        // have a successor.
        return successor;
    }

}

int main() {
    // A pointer to the root node of the tree.
    BSTNode* rootPointer = NULL;

    rootPointer = insert(rootPointer, 7);
    rootPointer = insert(rootPointer, 10);
    rootPointer = insert(rootPointer, 9);
    rootPointer = insert(rootPointer, 1);
    rootPointer = insert(rootPointer, 6);

    // Print the tree
    cout << "Inorder traversal of the given tree:" << "\n";
    print(rootPointer);

    // Find successor
    cout << "\n" << "The successor of 9 is " << getSuccessor(rootPointer, 9)->data << "\n";

    return 0;
}