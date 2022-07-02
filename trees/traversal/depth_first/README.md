# Depth-First

Here the core idea is that when we visit a child, we visit the whole sub-tree. The code here is relatively simple, and very intuitive through recursion.

Time complexity of all these algorithms is O(n).

Space complexity of all these algorithms is O(h). Where, h is the height of the binary tree.

> In the worst case, O(n)
>
> In the best/average case, O(log n)

Based on the relative order of left sub-tree, right sub-tree and root, we have different depth-first approaches:

## Preorder Traversal

root -> left -> right

## Inorder Traversal

left -> root -> right

> Inorder traversal of a binary search tree will give us a sorted list. This is because the left data is lesser and in Inorder traversal we start traversing from the left, that is ascending order.

## Postorder Traversal

left -> right -> root
