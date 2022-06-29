#include<stdlib.h>
#include<stdio.h>

// A structure for a node,
// which contains a data and a 
// pointer to the next node.
struct Node {
    int data;
    struct Node* next;
};

// A pointer to the first node of the list.
struct Node* head;

void insertToStart(int x) {
    // Allocate memory for the new node.
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));

    // Access the fields of a node
    (*temp).data = x; // A more common way to do this (temp -> data = x;)
    
    // This handles two cases
    // 1. If we are adding the first element, next is NULL
    // 2. If we are adding to the end of the list, next is the current head
    (*temp).next = head;

    // Set the head to the newly created node
    head = temp;
}

void insertAtPosition(int value, int position) {
   struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    (*temp).data = value;
    (*temp).next = NULL;

    // If the element is the first one
    if(position == 1) {
        (*temp).next = head;
        head = temp;
        return;
    }

    struct Node* temp_2 = head;
    for(int i =0; i < position-2; i++) {
        temp_2 = (*temp_2).next;
    }
    (*temp).next = (*temp_2).next;
    (*temp_2).next = temp;
}

void traverseList() {
    struct Node *temp = head;

    printf("The list is: ");

    while(temp != NULL) {
        printf("%d ", (*temp).data);
        temp = (*temp).next;
    } 
    printf("\n");
}

// A recusive function to add values to the list.
void askForInput() {
    int input, more, position;

    printf("Enter the value you want to input: ");
    scanf("%d", &input);

    printf("Enter the position you want to input value in: ");
    scanf("%d", &position);

    // insertToStart(input);
    insertAtPosition(input, position);

    printf("Want to enter more values? (1 for yes, 0 for no): ");
    scanf("%d", &more);

    if(more) {
        askForInput();
    }
}


int main() {
    // The value in the pointer is NULL
    // This just means that the list is empty
    head = NULL;

    askForInput();
    traverseList();

    return 0;

}