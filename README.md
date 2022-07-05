# Data Structures

This document accompanies and was written with the help of this [video](https://www.youtube.com/watch?v=B31LgI4Y4DQ).

I'll add the timestamps for the snippets too.

A data structure is a way to store and organinze data
in a computer, so that it can be used effectively

We can talk about them as:

- Abstract Data Types (ADTS): Mathematical/Logical models
- Implementation

Whenever we talk about a data structure, we talk about:

1. Logical view
2. Operations
3. Cost of operations
4. Implementation

## List

- Store a given number of elements of a given data type.
- We should be able to write/modify element at a position
- Read element at a position

A data structure that gives us implementation for this is: **Array**

### Dynamic List

- Empty when size is 0
- Insert elements in a list
- Remove elements
- Count the number of elements
- Read/Modify element at a position
- Specify the data-type of the list (int, char etc.)

These features can also be implemented in an **Array**. But, we need to define a max-size. We can always exhaust the list.

To add more elements, when the array is full, we create a new larger array, copy previous elements into new array and free the memory or the previous array.

Now what should be the best size to increase the array by?

We create the new array, double the size of the previous array and copy previous items in the array

### Time complexity

1. Access - Read/ Write element at an index

   This would take **Constant Time O(1)**

   Address of A[i] = base_address + i \* bytes_taken

2. Insert -

- When adding at the end, it would take constant time, when full, **O(n)**
- When adding at a position,

  The worst case would be to add the elements at the start and shift all the elements, this would make the insert operation proportional to the length of the list. Hence the time taken would be **O(n)**

3. Remove -

   Similar to insert, so, **O(n)**

Though good enough, **Arrays** aren't the best implementation of a dynamic list

## Linked Lists

A linked list is a sequence of data structures, which are connected together via links. Linked List is a sequence of links which contains items. Each link contains a connection to another link.

**Head Node**: The first element of a linked list

Address of the head node gives us the access to the complete list

- Access:

  Unlike an array we cannot access elements in constant time

  The time taken to access the elements would be proportional to the size of the array, **O(n)**

- Insertion:

  **O(n)** complexity, but we won't have to shift the elements like in an array

While traversing the elements of a linked list,
it's better to iterate over them, than to print them recursively, because,

1. When we print iteratively, we only use one temporary variable.
2. When we print using recursion, we use a lot of memory in the stack.

## Doubly Linked List

A doubly linked list is a linked data structure that consists of a set of sequentially linked records called nodes. Each node contains three fields: two link fields and one data field.

It is just like a linked list or singly linked list, except it has a pointer for the previous node too.

### Advantages

- Reverse lookup

### Disadvantages

- Use extra memory for pointer at previous node

## Stack (LIFO)

A list with a restriction that insertion and deletion
can be performed only from one end, called the top

### Operations

1. Push -

   This is basically insertion

2. Pop -

   This is removing the most recent item from the stack

3. Top -

   Returns element at the top of the stack

4. isEmpty -

   Check if a stack if empty

All of the operations in a stack take constant time,
or their big O notation is **O(n)**

> Stack is called a Last In First Out (LIFO) structure

### Applications

- Function calls/Recursion
- Perform undo in an editor
- Balenced paranthesis in a compiler

### Infix, Prefix and Postfix

#### Infix

> \<operand> \<operator> \<operand>

Infix notation is the notation commonly used in arithmetical and logical formulae and statements. It is characterized by the placement of operators between operands

> Example:
>
> 2 + 2
>
> 3 \* 4 + a

We can't use this while programming. This is because this notation has a lot of ambiguity, or doubt that which operation do we apply first. We have better options - Prefix and Postfix

> Order of operations:
>
> 1. Parenthesis
> 2. Exponents (in case of multiple - right to left)
> 3. Multiplication and Division
> 4. Addition and Substraction

#### Prefix

> \<operator> \<operand> \<operand>

Also known as **Polish Notion** and was introduced in 1924.

Here, operator is placed operands

> Example:
>
> \+ 2 2
>
> \+ \* 3 4 a

In this type of notation, one operand is only associated with one operator

#### Postfix

> \<operand> \<operand> \<operator>

Also known as the **Reverse Polish Notation**

Programaticaly, this expression is the easiest to parse and least time and memory consuming.

Prefix can also be executed in a similar complexity, but the algorithm to evaluate postfix expressions is quite intuitive and easy.

> Example:
>
> 2 2 +
>
> 3 4 a + \*

## Queues (FIFO)

A list with a restriction that insertion can be performed only from one end, called the rear and deletion can be performed at the other end, called the front.

1. Enqueue / Push -

   This is basically insertion

2. Dqueue/ Pop -

   This is removing the first item from the queue

3. Front/ Peek -

   Returns element at the front of the queue

4. isEmpty -

   Check if a queue if empty

5. isFull -

   Check if a queue if full

All of the operations in a queue take constant time,
or their big O notation is **O(n)**

> Queue is called a First In First Out (FIFO) structure

### Applications

- We have a shared resource but it can only take one request at a time
- Process Scheduling

## Tree

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
>
> To prevent the worst case, we can keep the tree balanced.
>
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

## Graphs

This is a non-linear data strcuture, just like a tree, and is a collection of objects or entities, called nodes/vertices that are connected by edges.

In a tree, there are rules dictating the conections of various nodes, for instance, in a tree with N nodes, we must exactly have (N-1) edges and there is exactly one edge in a parent child relationship etc.

Contrary to this, a graph has no rules dictating the connections among the nodes. It contains nodes and edges which can be connected in any possible way.

So, tree is just a special kind of a graph.

> A graph G is an ordered pair of a set V of vertices and a set E of edges.
>
> G = (V, E)
>
> **Ordered pair**: a pair of mathematical objects, where order matters, for example,
>
> (a, b) != (b, a) if (a != b)
>
> **Unordered pair**: simply a set of 2 mathematical objects with no specific order, for example,
>
> {a, b} = {b, a}

### Edges

How is an edge represented?

An edge is uniquely identified by it's 2 endpoints.

Edges can be of two types:

1. Directed:

   Connection is one-way.

2. Undirected:

   Connection is two-way.

A graph with all directed edges is called a **directed graph** or a **Digraph**

A graph with all undirected edges is called an **undirected graph**

### Weights

Sometimes, in a graph all connections cannot be treated as equal. Some connections can be prefereable to others. For example, a road network.

In these kind of cases, we associate a weight or a cost to each edge of the graph. These kind of graphs are called **Weighted Graphs**.

We can actually look at all the graphs as weighted graphs, an unweighted graph can be seen as a weighted graph in which the weight of all the edges is the same, typically, we assume it to be 1 unit.

### Applications

Any kind of real life application can be modelled using a graph, and they can be used to store all kinds of data.

Once data is modelled using a graph, a lot of problems can easily be solved by using standard graph theory algorithms.

Examples:

1. A Social Network
2. Interlinked webpages - WWW (World wide web)
3. Web crawling - This is just basically graph traversal to reccommend good search results.
4. Intercity road networks - Weighted undirected graph.
5. Intracity road networks - Weighted directed graphs: This is because there can be one-way roads in a city.

### Properties

- Self loop:

  An edge is called a self loop, or a self edge, if it only involves one vertex. These complicate algorithms and make working with graphs difficult.

  These can be seen in webpages, where a webpage links to itself.

- Multiedge / Parallel edge:
  An edge is called a multiedge, if it occurs more than once in a graph.

  These can be seen if we are modelling a flight network using graphs.

- If a graph doesn't have a self loop or a multi edge, then it is called a **simple graph**.

- Number of edges:

  Minimum number of edges for a graph = 0

  These can be calculated for a simple graph, cause if self loops are multi loops get involved, we obviously won't be able to calculate.

  1.  Directed-

      Here, we will have a directed edge from one node to every other node.

      So, in general,

      If |V| = n,

      then, for number of edges, E

      0 <= E <= n(n-1)

  2.  Undirected -

      Here, we will have only one edge from one node to another,

      So, similar to a directed graph,

      If |V| = n,

      then, for number of edges, E

      0 <= E <= n(n-1) / 2

- If the number of edges in a graph are close to the sqaure of it's number of nodes, that is the maximum number of edges, then it is called a **dense graph**.

- If the number of edges in a graph is really less, we call it a **sparse graph**. Typically, close to the number of vertices.

- **Path** - a sequence of vertices where each adjecent pair is connected by an edge.

  In a directed graph, all edges must also be aligned in one direction, the direction of path.

  - **Simple path** - a path in which no vertices, and hence, no edges are repeated.

  Most of the time when we say path, we mean a simple path. So, for the actual path, we use the term **walk**, and thus, the defination of a simple path becomes,

  A _walk_ in which no vertices, and hence, no edges are repeated.

  - **Trial** - a _walk_ in which no edges are repeated.

  If a trail is possible between two vertices, then certainly a simple path, or just a path is also possible.

- **Strongly Connected Graph** - A graph is called a strongly connected graph, if there is a path from any vertex to any other vertex.

  - If it's an undirected graph, we simply call it connected
  - If it's a directed graph, we call it strongly connected.

- **Weakly Connected Graphs** - If a directed graph is not strongly connected, but can be by treating all the edges as undirected, then it is called a weakly connected graph.

- **Closed walk** - If a walk starts and ends at the same vertex and the length of the walk(number of edges in the walk) is > 0.

  Some use the term **cycle** for a closed walk, but the term _cycle_ generally refers to a simple cycle.

- **Simple Cycle** - A simple cycle is a closed walk in which there is no repetition except the start and end vertices.

- **Acyclic graph** - A graph with no cycle. A tree would be an example of an acyclic graph.

### Graph Representation

We can store the graph in the computer's memory in different ways. Here we analyse the time and space complexity of different methods:

1. **Edge List**

   We create 2 lists,

   1. To store vertices
   2. To store edges

   Vertices can be a simple string, and in a realistic scenario the strings won't be very long, so the space complexity will be proportional to the number of vertices.

   For edges, we can store it in the form

   ```c
      struct Edge {
         int start_vertex;
         int end_vertex;
         int weight;
      }
   ```

   Here, the space complexity would be propoortional to the number of edges.

   Hence, the total space complexity of storing a graph would be `O(|V| + |E|)`

   We cannot do a lot better if we want to store a graph in the memory. So we are good with the memory usage.

   For **Time complexity**,

   The most frequently performed operations would be-

   1. Find nodes adjecent to given nodes-
      For this specific case, we would have to scan the whole edge list. We will have to perform a linear search.

      Time complexity for this operation will be `O(|E|)`

   2. Find if two given nodes are connected -
      Similar to the previous case, here too, we will have to perform a linear search.

      Thus, time complexity for this operation will also be `O(|E|)`

   If we take a look at that in terms of number of vertices, the time complexity would be

   `O(|V| * |V|)`, this is because the maximum number of edges is n(n-1), which is costly.
