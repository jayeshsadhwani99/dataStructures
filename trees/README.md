# Tree

A collection of entities called nodes, linked together to simulate a heirarchy.

- It is a non-linear, heirarchial data structure
- Top-most node is called the **root** of the tree, it is the only node without a parent.
- Each node contains data and link/reference to some other node, called it's **Children**
- Node which has children is called a **Parent Node**.
- Nodes with the same parent are called **Sibling Nodes**
- When a node has a direct link to another node, we have a **parent-child** relationship
- Nodes that do not have children are called **Leaf Nodes**. All other nodes are called **Internal Nodes**
- We can only move from parent -> Child in a tree
- If we can go from A to B, A is the **Ancestor** of B and B is the **Descendant** of A.

### Properties

1. It can be called a **recursive data structure**.

   It consists of a distinguished node called root and some sub-trees, and the arrangement is such that root of the tree contains link to all of the root's sub-trees.

   > Recursion is basically reducing something in a self similar manner. This property of trees is used everywhere.

2. In a tree with N nodes, there will exactly be **(N-1) links/ edges**

   All nodes will have exactly _one_ incoming edge/link, except the root.

3. Depth of x: Length of the path from root to x, or, number of edges in path from root to x.

   > The depth for root node will be 0.

4. Height of x: Number of edges in longest path from x to a leaf.

   > Height of tree is the height of the root node.

   > Height of an empty tree is -1.

   > Height of a tree with 1 node is 0.

### Applications

- Storing naturally heirarichal data, like file system.
- Organize data for quick search, insertion and deletion.
- A special kind of tree, **Trie** is used to store a dictionary and is used for dynamic spell checking.
- Used in Network Routing Algorithms.

## Binary Tree

A type of tree where each node can have _atmost_ 2 children.
One child is called the left child, the other, the right child.

### Strict binary tree

A binary tree where each node has either 2 or 0 child nodes.

### Complete binary tree

A binary tree where all levels except the possibly last are completely filled and all nodes are as far left as possible.

> Max number of nodes at level i = 2^i

### Perfect Binary tree

A binary tree where all levels will be completely filled.

Maximum number of nodes in a binary tree with height h will be

= 2<sup>0</sup> + 2<sup>1</sup> + 2<sup>2</sup> + .... + 2<sup>h</sup>

= 2<sup>h+1</sup> - 1

= 2<sup>number of levels</sup> - 1

> Height of a complete binary tree with _n_ nodes,
>
> log<sub>2</sub>(n+1) - 1

> Min height possible:
> log<sub>2</sub>n
>
> Max height possible:
> n-1

### Balanced binary tree

For a binary tree, if the height of left and right subtree for every node is not more than K (mostly 1).

> difference = h<sub>left</sub> - h<sub>right</sub>

### Implementation

We can implement binary trees in the following ways:

1. **Dynamically created nodes** linked to each other using pointers or references.
2. In some special cases, we can use **arrays** - They are used to implement heaps.
   > For node at index i, for a complete binary tree,
   >
   > left-child-index = 2i + 1
   >
   > right-child-index = 2i + 2

## Binary Seach Tree (BST)

A type of binary tree in which each node, value of all the nodes in left subtree is lesser or equal(to handle duplicates) and value of all the nodes in right subtree is greater.

The search operation has the complexity of **O(log<sub>2</sub>n)**

> The search we perform in this tree is a binary search and hence, the name.

> To prevent the worst case, we can keep the tree balanced.

> To insert data, we search with log complexity, and we just add the place

During insertion and deletion, the balance of the tree is disturbed and there are ways of restoring it.

## Tree Traversal

It is the process of visiting(reading/ processing data in the node) each node in the tree exactly once in some order.

Based on the order in which nodes are visited, they can be classified into:

1. Breadth-First

   This is called level-order traversal and here we traverse by levels.

2. Depth-First

   Here the core idea is that when we visit a child, we visit the whole sub-tree. The code here is relatively simple, and very intuitive through recursion.

   Time complexity of all these algorithms is O(n).

   Space complexity of all these algorithms is O(h). Where, h is the height of the binary tree.

   > In the worst case, O(n)
   >
   > In the best/average case, O(log n)

   Based on the relative order of left sub-tree, right sub-tree and root, we have different depth-first approaches:

   1. **Preorder Traversal**

      root -> left -> right

   2. **Inorder Traversal**

      left -> root -> right

      > Inorder traversal of a binary search tree will give us a sorted list. This is because the left data is lesser and in Inorder traversal we start traversing from the left, that is ascending order.

   3. **Postorder Traversal**

      left -> right -> root

## Delete a Node

There can be three cases when we try and delete a node, and we handle them all seperately:

1. The node has no child

   In this case, we just simply delete the link to the node and free up the memory.

2. The node has one child

   In this case, we can simply delete the node, and free the memory, but in addition to that, we can link to parent to the child node.

3. The node has 2 children

   This is the most complex case and has 2 solutions:

   1. We find the min value in the right subtree and copy the value in the targetted node. We now delete the duplicate node by a recursive function and reducing it to any of the above 2 conditions.

   2. We find the max value in the left subtree and copy the value in the targetted node. We now delete the duplicate node by a recursive function and reducing it to any of the above 2 conditions.

## Inorder Successor

The next element we get when we are performing inorder traversal of the tree, that is find the next gratest element in the tree.

There are 2 possiblities when finding the inorder successor:

1. The target node has a right subtree

   To find the next element, we can just go the deepest in the right sub-tree, or, find the min value in the right sub-tree.

2. There is no right subtree

   In this case, the parent node might already have been visited, so, we go to the nearest ancestor for which the given node would be in the left subtree.
