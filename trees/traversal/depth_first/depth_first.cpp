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

// Preorder is root -> left -> right
// space complexity of this algorithm will
// depend on the height of the tree, 
// as at any given time the stack
// will have at max the height number of
// nodes, hence, complexity is
// O(h) where h is the height of the tree.
void preorder(BSTNode* root) {
    // An exit condition for the recursion.
    // When the tree is empty, we return.
    if(root == NULL) return;

    // Read the data
    cout << root->data << " ";

    // traverse left subtree
    preorder(root->left);

    // traverse right subtree
    preorder(root->right);
}

// Inorder is left -> root -> right
// In a BST, or a binary search tree,
// inorder traversal can help us sort
// the results in ascending order
void inorder(BSTNode* root) {
    // An exit condition for the recursion.
    // When the tree is empty, we return.
    if(root == NULL) return;

    // Since we need to visit the left subtree,
    // before the root,
    // we call the inorder function on the left subtree.
    inorder(root->left);

    // Now we can print the root,
    cout << root->data << " ";

    // Finally, we can also traverse the
    // right subtree
    inorder(root->right);
}

// Postorder is left -> right -> root
void postorder(BSTNode* root) {
    // An exit condition for the recursion.
    // When the tree is empty, we return.
    if(root == NULL) return;

    // Since we need to visit the left subtree,
    // then the right subtree before the root,
    // we call the postorder function on the left subtree.
    postorder(root->left);

    // Now, we can also traverse the right subtree
    postorder(root->right);

    // and finally, we can print the root,
    cout << root->data << " ";

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

    printf("Preorder: \n");
    preorder(rootPointer);
    printf("\n");

    printf("Inorder: \n");
    inorder(rootPointer);
    printf("\n");

    printf("Postorder: \n");
    postorder(rootPointer);
    printf("\n");

    return 0;
}