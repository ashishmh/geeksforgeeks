// http://www.geeksforgeeks.org/xor-linked-list-a-memory-efficient-doubly-linked-list-set-2/

#include <iostream>
using namespace std;

class node {
public:
    int data;
    node *npx;
    node(int data) {
        this->data = data;
        this->npx = NULL;  
    }
};

node* addnode(node *head, int data);        // adds node to double list
node* XOR(node* a, node* b);                // returns XOR of two pointers of node type
void printList(node *head);                 // traverses double list L->R starting with head

node* addnode(node *head, int data) {
    // if list is empty
    if (head == NULL)
        return new node(data);
    // if list is not empty, traverse till end and add node
    node *prev = NULL;
    node *curr = head;
    node* temp;
    while (curr->npx != XOR(prev, NULL)) {
        temp = curr;
        curr = XOR(curr->npx, prev);
        prev = temp;
    }
    // curr now points to last node
    temp = new node(data);
    curr->npx = XOR(prev, temp);
    temp->npx = XOR(curr, NULL);

    return head;
}

node* XOR(node* a, node* b) {
    return (node*) ((unsigned long)a ^ (unsigned long)b);
}

void printList(node *head) {
    if (head == NULL)
        return;
    node *prev = NULL;
    node* curr = head;
    node* temp;
    while (curr != NULL) {
        temp = curr;
        cout<<curr->data<<" ";
        curr = XOR(curr->npx, prev);
        prev = temp;
    }
}

int main() {
    node *head = NULL;
    head = addnode(head, 1);
    head = addnode(head, 2);
    head = addnode(head, 3);
    head = addnode(head, 4);
    head = addnode(head, 5);

    // traverse L->R
    cout<<"traverse (L->R): ";
    printList(head);

    // traverse R->L
    node *prev = NULL;
    node *curr = head;
    node* temp;
    while (curr->npx != XOR(prev, NULL)) {
        temp = curr;
        curr = XOR(curr->npx, prev);
        prev = temp;
    }
    cout<<endl<<"traverse (R->L): ";
    printList(curr);

    cout<<endl;    
    return 0;
}