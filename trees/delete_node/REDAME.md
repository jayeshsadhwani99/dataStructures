# Delete a Node

There can be three cases when we try and delete a node, and we handle them all seperately:

1. The node has no child

   In this case, we just simply delete the link to the node and free up the memory.

2. The node has one child

   In this case, we can simply delete the node, and free the memory, but in addition to that, we can link to parent to the child node.

3. The node has 2 children

   This is the most complex case and has 2 solutions:

   1. We find the min value in the right subtree and copy the value in the targetted node. We now delete the duplicate node by a recursive function and reducing it to any of the above 2 conditions.

   2. We find the max value in the left subtree and copy the value in the targetted node. We now delete the duplicate node by a recursive function and reducing it to any of the above 2 conditions.
