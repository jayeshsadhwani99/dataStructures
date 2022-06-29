#include<stdlib.h>
#include<stdio.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head;

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    (*newNode).data = data;
    (*newNode).next = NULL;
    (*newNode).prev = NULL;

    return newNode;
}

void insertAtHead(int data) {
    struct Node* temp = createNode(data);
    if(head == NULL) {
        head = temp;
        return;
    }
    (*head).prev = temp;
    (*temp).next = head;
    head = temp;
}

void traverse() {
    struct Node* temp = head;
    printf("Linked List\n");
    while(temp != NULL) {
        printf("%d ", (*temp).data);
        temp = (*temp).next;
    }
    printf("\n");
}

void reverseTraverse() {
    printf("Linked List in reverse\n");
    struct Node* temp = head;
    if(temp == NULL) {
        printf("List is empty\n");
        return;
    }

    // Go to the last node
    while((*temp).next != NULL) {
        temp = (*temp).next;
    }

    // Traverse backwards
    // using prev pointer
    while(temp != NULL) {
        printf("%d ", (*temp).data);
        temp = (*temp).prev;
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