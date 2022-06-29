// Though works, this is not an
// ideal implementation for a stack.
// For an ideal implementation,
// we can create a struct
#include<stdlib.h>
#include<stdio.h>

// The macro in C language is known as the 
// piece of code which can be replaced by the 
// macro value. Macro is just a name given to 
// certain values or expressions it doesn't 
// point to any memory location.
#define MAX_SIZE 101

// We define global variables so we don't
// have to pass them as arguments to functions.
int A[MAX_SIZE];
int top = -1;

void push(int data) {
    // Handle overflow
    if(top == MAX_SIZE - 1) {
        printf("Error: Stack overflow\n");
        return;
    }

    // We use pre-increment operator so that
    // increment happens before the value is 
    // assigned.
    A[++top] = data;
}

void pop() {
    // Handle underflow
    if(top == -1) {
        printf("Error: Stack underflow\n");
        return;
    }

    // We do not need to do anything to the
    // value as the stack is determined by the
    // top pointer.
    top--;
}

void print() {
    printf("Stack is: \n");
    for(int i=0; i <= top; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int topValue() {
    return A[top];
}

int main() {

    push(2);
    print();
    push(4);
    print();
    push(6);
    print();
    push(8);
    print();
    push(1);
    print();
    pop();
    print();
    push(10);
    print();

    return 0;
}