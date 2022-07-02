# Binary Tree

A type of tree where each node can have _atmost_ 2 children.
One child is called the left child, the other, the right child.

# Binary Seach Tree (BST)

A type of binary tree in which each node, value of all the nodes in left subtree is lesser or equal(to handle duplicates) and value of all the nodes in right subtree is greater.

The search operation has the complexity of **O(log<sub>2</sub>n)**

> The search we perform in this tree is a binary search and hence, the name.
>
> To prevent the worst case, we can keep the tree balanced.
>
> To insert data, we search with log complexity, and we just add the place

During insertion and deletion, the balance of the tree is disturbed and there are ways of restoring it.

## Check for BST

There are multiple approaches to check if a given binary tree is a binary search tree:

1. The first approach is easy to think of, but inefficient.

   For a tree to be a binary search tree, it must have a recursive structure, wherein, both, the left and the right subtree are also BST's.

   Here, the elements in the left subtree must be lesser and the elements in the right subtree must be larger.

2. Another similar approach would be to find the maximum and minimum in the respective trees instead of checking if all the values would be lesser or greater.

> For the above 2 algorithms, the time complexity would be O(n<sup>2</sup>), which is not very good.

3. We have a better an more efficient solution than the ones stated above. What we can do is define a permissible _range_ for each node, and the data in that node, must be in that range.

   For the root node, we can start at -infinity and infinity, infinity here is just the max value that can be stored in int.

   Now, as we are traversing, we can set the range for that node.

   Here, we go through each node just once and at each node we take constant time to check if the data falls in that range.

> Time complexity will be O(n), where n is the number of nodes in a tree.

4. There can be another approach where we can perform inorder traversal of a tree(left -> root -> right) and if the tree is BST, the data would be sorted. This is because inorder traversal gives the list in ascending order for a BST.

   Here we only need to keep track of the previous node and check if the data in the current node is grater than the previous node.
