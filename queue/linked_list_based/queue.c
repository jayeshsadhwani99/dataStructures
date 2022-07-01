// Since we can dynamically allocate memory,
// this would mean no wasted memory
// and creating nodes as we need
// linked list implementation of stack is
// ideal.
#include<stdlib.h>
#include<stdio.h>

// bool does not exist as a keyword pre-C99.
// It's a macro declared in <stdbool.h>.
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

// Instead of a single head pointer,
// we'll now have 2 pointers,
// a front for the start if the list,
// and a rear for the end of the list.
struct Node* front = NULL;
struct Node* rear = NULL;

bool isEmpty() {
    return (front == NULL) && (front == rear);
}

void enqueue(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));

    (*temp).data = data;
    (*temp).next = NULL;

    // When we are enqueuing the first
    // element, we set both, the front
    // and the rear to the same node
    if(front == NULL && rear == NULL) {
        front = rear = temp;
        return;
    }

    // We first set the address of the
    // current node to the new node,
    // then set the rear to the new node.
    (*rear).next = temp;
    rear = temp;
}

int dequeue() {
    struct Node* temp = front;
    int data = (*temp).data;

    // If the queue is empty
    if(front == NULL) {
        printf("The queue is empty\n");
        return -1;
    }
    
    // If there is one element
    // in the queue
    if(front == rear) {
        front = rear = NULL;
    } else {
        front = (*front).next;
    }
    // Free the memory being
    // used by the dequeued node
    free(temp);

    return data;
}

// This means return the element
// in front of the queue, that is,
// the first element
int peek() {
    return (*front).data;
}

void traverse() {
    struct Node *temp = front;

    printf("The queue is: ");

    while(temp != NULL) {
        printf("%d ", (*temp).data);
        temp = (*temp).next;
    } 
    printf("\n");
}

int main() {
    int dequeued_element;

    printf("Enqueuing element: %d.\n", 1);
    enqueue(1);
    printf("Front element: %d\nFront: %d\nRear: %d\n", peek(), (*front).data, (*rear).data);

    printf("Enqueuing element: %d.\n", 2);
    enqueue(2);
    printf("Front element: %d\nFront: %d\nRear: %d\n", peek(), (*front).data, (*rear).data);

    printf("Enqueuing element: %d.\n", 3);
    enqueue(3);
    printf("Front element: %d\nFront: %d\nRear: %d\n", peek(), (*front).data, (*rear).data);

    traverse();
    printf("Front element: %d\nFront: %d\nRear: %d\n", peek(), (*front).data, (*rear).data);

    dequeued_element = dequeue();

    printf("Dequeued element: %d\n", dequeued_element);
    traverse();

    printf("Front element: %d\nFront: %d\nRear: %d\n", peek(), (*front).data, (*rear).data);


    return 0;
}