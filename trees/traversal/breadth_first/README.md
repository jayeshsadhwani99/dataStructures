# Breadth-First

This is called level-order traversal and here we traverse by levels.

Since we cannot move from
left to right without the parent
node, we use a queue to store the
nodes in the current level.

As we visit a node, we keep reference
to all it's children in a queue.
A node in a queue is called a discovered
node - The node we have discovered, but
not visited yet.

As long as the queue is not empty, we
can visit the next node in the queue and
enqueue all it's children.
