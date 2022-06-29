// As reversing a linked list is 
// not as easy as reversing a string,
// stack is a good choice for this.

#include<iostream>
// Built-in stack implementation
// from Standard Template Library(STL)
#include<stack>

using namespace std;

struct Node {
    int data;
    Node* next;
};

// A pointer to the first node of the list.
Node* head;

void insertToStart(int x) {
    Node* temp = new Node();
    temp -> data = x;
    temp -> next = head;
    head = temp;
}

void traverse() {
    Node* temp = head;
    printf("List is:\n");
    while(temp != NULL) {
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}

void reverse() {
    if(head == NULL) {
        printf("List is empty.\n");
        return;
    }
    stack<Node*> s;
    Node* temp = head;

    // Add to the stack
    while(temp!=NULL) {
        s.push(temp);
        temp = temp -> next;
    }

    // Remove from the stack
    temp = s.top();
    head = temp;
    s.pop();

    while(!s.empty()) {
        temp -> next = s.top();
        s.pop();
        temp = temp -> next;
    }
    temp -> next = NULL;
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