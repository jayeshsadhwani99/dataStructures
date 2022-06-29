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

void reverse() {
    // Since we are reversing the list,
    // We would need access to the previous node
    // By default, we'll be starting from the first node,
    // So we set it to NULL

    // As soon as we remove the link to the next node,
    // We'll have no way to access the node, so,
    // We need to have access to the next node too
    struct Node *current, *prev, *next;
    current = head;
    prev = NULL;

    while(current!=NULL) {
        next = (*current).next;
        // We will have to update both, the previous node,
        // and the current node

        (*current).next = prev;
        prev = current;
        current = next;
    }

    // Set the head to the last element
    // And according to the code,
    // the last element would be the prev element once
    // the loop is done, so,
    head = prev;
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
    reverse();

    traverse();

    return 0;
}