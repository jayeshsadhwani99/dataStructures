// Since we cannot move from 
// left to right without the parent
// node, we use a queue to store the
// nodes in the current level.

// As we visit a node, we keep reference
// to all it's children in a queue.
// A node in a queue is called a discovered
// node - The node we have discovered, but
// not visited yet.

// As long as the queue is not empty, we
// can visit the next node in the queue and
// enqueue all it's children.
#include<iostream>

// In this program we won't implement 
// queues from scratch but use the
// built-in standard library queue.
#include<queue>

using namespace std;

struct BSTNode {
    int data;
    BSTNode* left;
    BSTNode* right;
};

// Basic functions to test the BST
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

void levelOrder(BSTNode* root) {
    // If the tree is empty
    if(root == NULL) return;
    queue<BSTNode*> q;

    // initially, we'll start with just
    // one discovered node, the root node
    q.push(root);

    // We run a loop while there is atleast
    // one discovered node in the queue.
    while(!q.empty()) {
        // We take out the element in the
        // front of the queue.
        BSTNode* current = q.front();
         
        // We can now visit the node
        cout<< current->data << " ";

        // Push the children in the queue
        // Left first, then right.
        if(current->left != NULL) {
            q.push(current->left);
        }
        if(current->right != NULL) {
            q.push(current->right);
        }


        // Remove the current element
        // from the queue.
        q.pop();
    }
}

int main() {
    // A pointer to the root node of the tree.
    BSTNode* rootPointer = NULL;

    rootPointer = insert(rootPointer, 15);
    rootPointer = insert(rootPointer, 10);
    rootPointer = insert(rootPointer, 20);
    rootPointer = insert(rootPointer, 25);
    rootPointer = insert(rootPointer, 8);
    rootPointer = insert(rootPointer, 12);

    levelOrder(rootPointer);

    return 0;
}