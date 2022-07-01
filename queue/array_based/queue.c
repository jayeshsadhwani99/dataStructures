// To make the code better, we should
// consider the array to be a circular array.
// This is because we want to be able to
// enqueue and dequeue from the front and
// the back of the array and don't want to leave
// empty spaces.

#include<stdlib.h>
#include<stdio.h>

// bool does not exist as a keyword pre-C99.
// It's a macro declared in <stdbool.h>.
#include <stdbool.h>

// The macro in C language is known as the 
// piece of code which can be replaced by the 
// macro value. Macro is just a name given to 
// certain values or expressions it doesn't 
// point to any memory location.
#define MAX_SIZE 101

// We define global variables so we don't
// have to pass them as arguments to functions.
int A[MAX_SIZE];
int front = -1, rear = -1;

bool isEmpty() {
    return (front == -1 && rear == -1);
}

bool isFull() {
    return (rear+1)%MAX_SIZE == front;
}

void enqueue(int data) {
    if(isFull()) {
        printf("Queue is full.\n");
        return;
    } else if(isEmpty()) {
        // If the queue is empty.
        // we set the front and rear to 0.
        front = 0;
        rear = 0;
    } else {
        // If the queue is not empty.
        // we increment the rear by 1.

        // We find the modulo to find if there 
        // are any empty spaces between the front
        // and the rear.
        rear = (rear+1)%MAX_SIZE;
    }

    A[rear] = data;
}

int dequeue() {
    int element = A[front];
    if(isEmpty()) {
        printf("Queue is empty.\n");
        return -1;
    } else if(front == rear) {
        // When there is only one
        // item in the queue
        front = -1;
        rear = -1;
    } else {
        // We don't need to remove the data as 
        // our array is defined from the front pointer.
        // We just need to increment the front pointer.
        front = (front + 1)%MAX_SIZE;
    }

    return element;
}

int peek() {
    return A[front];
}

void traverse() {
    int i = front;

    printf("Queue is:\n");
    while(i <= rear) {
        printf("%d ", A[i]);
        i = (i+1)%MAX_SIZE;
    }
    printf("\n");
}

int main() {
    int dequeued_element;

    printf("Enqueuing element: %d.\n", 1);
    enqueue(1);
    printf("Front element: %d\nFront: %d\nRear: %d\n", peek(), front, rear);

    printf("Enqueuing element: %d.\n", 2);
    enqueue(2);
    printf("Front element: %d\nFront: %d\nRear: %d\n", peek(), front, rear);

    printf("Enqueuing element: %d.\n", 3);
    enqueue(3);
    printf("Front element: %d\nFront: %d\nRear: %d\n", peek(), front, rear);

    traverse();
    printf("Front element: %d\nFront: %d\nRear: %d\n", peek(), front, rear);

    dequeued_element = dequeue();

    printf("Dequeued element: %d\n", dequeued_element);
    traverse();

    printf("Front element: %d\nFront: %d\nRear: %d\n", peek(), front, rear);
    
    return 0;
}