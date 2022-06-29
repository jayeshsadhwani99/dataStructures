// Since we can dynamically allocate memory,
// linked list implementation of stack is
// ideal.
#include<stdlib.h>
#include<stdio.h>

struct Node {
    int data;
    struct Node* link;
};

struct Node* top = NULL;

void push(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
    (*temp).data = data;
    (*temp).link = top;

    top = temp;
}

void pop() {
    struct Node* temp = top;
    if(top == NULL) {
        printf("Error: Stack underflow\n");
        return;
    }

    top = (*top).link;
    free(temp);
}

void topValue() {
    if(top == NULL) {
        printf("Error: Stack underflow\n");
        return;
    }

    printf("Top value is: %d\n", (*top).data);
}

void print() {
    printf("Stack is: \n");
    struct Node* temp = top;
    while(temp != NULL) {
        printf("%d ", (*temp).data);
        temp = (*temp).link;
    }
    printf("\n");
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