#include<stdlib.h>
#include<stdio.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head;

void insertToStart(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    (*temp).data = x;
    (*temp).next = head;
    head = temp;
}

void traverse() {
    struct Node* temp = head;
    printf("List is:\n");
    while(temp != NULL) {
        printf("%d ", (*temp).data);
        temp = (*temp).next;
    }
    printf("\n");
}

void reverse(struct Node* element) {
    // When we do recursion,
    // We need to have an exit condition, 
    // so that we don't create an infinite loop
    if((*element).next == NULL) {

        // Set the last element to head
        head = element;
        return;
    }

    reverse((*element).next);

    // These statements will be executed after 
    // the recursive call, that is, after the exit
    // condition. Why?
    // This is because in the call stack, the 
    // execution of the function is paused, until
    // the next function is executed.
    struct Node* temp = (*element).next;
    (*temp).next = element;
    (*element).next = NULL;
}

int main() {
    head = NULL;

    // Basic setup of linked list
    insertToStart(5);
    insertToStart(8);
    insertToStart(1);
    insertToStart(4);

    traverse();

    // Reverse the list
    printf("Reversing the list\n");
    reverse(head);

    traverse();

    return 0;
}