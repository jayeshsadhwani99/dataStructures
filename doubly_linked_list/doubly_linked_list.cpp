#include<stdlib.h>
#include<stdio.h>

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* head;

Node* createNode(int data) {
    Node* newNode = new Node();

    newNode -> data = data;
    newNode -> next = NULL;
    newNode -> prev = NULL;

    return newNode;
}

void insertAtHead(int data) {
    Node* temp = createNode(data);
    if(head == NULL) {
        head = temp;
        return;
    }
    head -> prev = temp;
    temp -> next = head;
    head = temp;
}

void traverse() {
    Node* temp = head;
    printf("Linked List\n");
    while(temp != NULL) {
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}

void reverseTraverse() {
    printf("Linked List in reverse\n");
    Node* temp = head;
    if(temp == NULL) {
        printf("List is empty\n");
        return;
    }

    // Go to the last node
    while(temp -> next != NULL) {
        temp = temp -> next;
    }

    // Traverse backwards
    // using prev pointer
    while(temp != NULL) {
        printf("%d ", temp -> data);
        temp = temp -> prev;
    }
    printf("\n");
}

int main() {
    head = NULL;

    insertAtHead(2);
    insertAtHead(3);
    insertAtHead(4);
    insertAtHead(5);

    traverse();
    reverseTraverse();
}