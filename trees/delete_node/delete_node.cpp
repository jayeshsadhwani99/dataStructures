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


// The function to find the minimum value 
// in a tree, this can help is find the
// minimum value in the right-subtree while
// deleting the node having 2 children.
BSTNode* findMin(struct BSTNode* root) {
    if(root == NULL) {
        return root;
    }
    if((*root).left == NULL) {
        return root;
    }
    return findMin(root->left);
}


// The actual deletion function of the node
// through recursion.
BSTNode* deleteNode(BSTNode* root, int data) {
    // Just to handle a corner case.
    if (root == NULL) return root;
    else if(data < root->data) {
        // Since the data is smaller than
        // the data in root, we'll search in the 
        // left subtree.

        // The root of the left sub-tree may
        // change, when we delete the node,
        // so, we can set the left root as the 
        // value we return
        root->left = deleteNode(root->left, data);
    } else if(data > root->data) {
        // Similar to the previous case,
        // Since the data is greater than
        // the data in root,
        // We search in the right sub-tree
        
        // The root of the right sub-tree may
        // change, when we delete the node,
        // so, we can set the right root as the 
        // value we return
        root->right = deleteNode(root->right, data);
    } else {
        // We found the node to be deleted.
        // This case is data == root->data

        // Here we can handle the 3 cases:
        // 1. The node to be deleted has no children
        // 2. The node to be deleted has one child
        // 3. The node to be deleted has 2 children

        // Case 1-
        if(root->left == NULL && root->right == NULL) {
            // Deallocate the memory
            delete root;

            // But now, the root will still have
            // it's address, so we set the root to
            // NULL
            root = NULL;
        }

        // Case 2-
        else if(root->left == NULL) {
            BSTNode* temp = root;

            // Since the left child is NULL,
            // and we have data in the right tree,
            // We can set the root to the right tree

            // Here we are basically linking the
            // parent to the child node.
            root = root->right;

            // Free up the memory
            delete temp;
        }
        else if(root->right == NULL) {
            // Similar to the previous case,
            // here the only difference will be
            // that we the right node is NULL
            BSTNode* temp = root;

            // Since the right child is NULL,
            // and we have data in the left tree,
            // We can set the root to the left tree

            // Here we are basically linking the
            // parent to the child node.
            root = root->left;

            // Free up the memory
            delete temp;
        }

        // CASE 3-
        else {
            // We are going with the first
            // solution here - finding the min in 
            // the right subtree and deleting the
            // duplicate
            BSTNode* temp = findMin(root->right);
            root->data = temp->data;

            // Calling the loop recursively to delete
            // the duplicate node by reducing it to 
            // other 2 cases.
            root->right = deleteNode(root->right, temp->data);
        }
    }

    // Since we are just passing the value
    // of the root in the function, we have
    // to modify it in the parent function
    // to reflect the changes. So, we 
    // return the new root, the one we get 
    // after deleting the node.
    return root;
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

    cout << "\n" << "Deleting Node... 7" << "\n";

    rootPointer = deleteNode(rootPointer, 7);

    cout << "Node Deleted" << "\n";

    // Print the tree
    cout << "Inorder traversal of the given tree:" << "\n";
    print(rootPointer);

    return 0;
}