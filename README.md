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
