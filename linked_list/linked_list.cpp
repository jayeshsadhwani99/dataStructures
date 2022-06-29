// This is a lot like C,
// but with a few differences.

#include<stdlib.h>
#include<stdio.h>

using namespace std;

// Why do we use (n-2) in all the loops?
// This is because we are using the position.
// Cause of this, the total elements are (n-1).
// We handle the head seperately, so we use (n-2)

// A structure for a node,
// which contains a data and a 
// pointer to the next node.
struct Node {
    int data;
    Node* next;
};

// A pointer to the first node of the list.
Node* head;

void insertToStart(int x) {
    // Allocate memory for the new node.
    Node* temp = new Node();

    // Access the fields of a node
    temp -> data = x;
    
    // This handles two cases
    // 1. If we are adding the first element, next is NULL
    // 2. If we are adding to the end of the list, next is the current head
    temp -> next = head;

    // Set the head to the newly created node
    head = temp;
}

void insertAtPosition(int value, int position) {
Node* temp = new Node();
    temp -> data = value;
    temp -> next = NULL;

    // If the element is the first one
    if(position == 1) {
        temp -> next = head;
        head = temp;
        return;
    }

    Node* temp_2 = head;
    for(int i =0; i < position-2; i++) {
        temp_2 = temp_2 -> next;
    }
    temp -> next = temp_2 -> next;
    temp_2 -> next = temp;
}

void delete_element(int position) {
    // Let the node to be deleted be n
    Node* temp = head;

    // Delete the head node (the first node)
    if(position == 1) {
        // point head to the second node
        head = temp -> next;
        delete temp;
        return;
    }

    // Go to the (n-1)th node
    for(int i = 0; i < position-2; i++) {
        // point temp to the (n-1)th node
        temp = temp -> next;
    }

    // point to the nth node
    Node* nth_node = temp -> next;
    
    // point the (n-1)th node to the (n+1)th node
    // this means, deleting the link to the nth element
    // from the list
    temp -> next = nth_node -> next;

    // Delete the memory allocated to
    // the nth node (the element to be deleted)
    delete nth_node;
}

void traverseList() {
    Node *temp = head;

    printf("The list is: ");

    while(temp != NULL) {
        printf("%d ", temp -> data);
        temp = temp -> next;
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

void delete_input() {
    int delete_position, delete_more;
    printf("Enter the position you want to delete: ");
    scanf("%d", &delete_position);

    delete_element(delete_position);
    traverseList();

    printf("Want to delete more values? (1 for yes, 0 for no): ");
    scanf("%d", &delete_more);

    if(delete_more) {
        delete_input();
    }
}


int main() {
    int delete_el;
    // The value in the pointer is NULL
    // This just means that the list is empty
    head = NULL;

    askForInput();
    traverseList();

    printf("Want to delete elements? (1 for yes, 0 for no): ");
    scanf("%d", &delete_el);

    if(delete_el) {
        delete_input();
    }

    return 0;
}