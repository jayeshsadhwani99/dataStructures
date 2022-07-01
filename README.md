# Data Structures

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

## Binary Seach Tree

A type of binary tree in which each node, value of all the nodes in left subtree is lesser or equal(to handle duplicates) and value of all the nodes in right subtree is greater.

The search operation has the complexity of **O(log<sub>2</sub>n)**

> The search we perform in this tree is a binary search and hence, the name.

> To prevent the worst case, we can keep the tree balanced.

> To insert data, we search with log complexity, and we just add the place

During insertion and deletion, the balance of the tree is disturbed and there are ways of restoring it.
