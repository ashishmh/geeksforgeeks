// http://www.geeksforgeeks.org/reverse-alternate-k-nodes-in-a-singly-linked-list/

#include <iostream>
using namespace std;

class node {
public:
    int data;
    node *next;
    node(int data) {
        this->data = data;
        this->next = NULL;  
    }
};

node* kAltReverse(node *head, int k);
node* addnode(node *head, int data);
void printList(node *head);

node* kAltReverse(node *head, int k) {
    if (head == NULL || head->next == NULL)
        return head;
    node *curr = head;
    node *prev = NULL;
    node *next = NULL;
    int count = 0;
    // reverse first k nodes
    while (curr != NULL && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    head->next = next;
    // skip next k nodes
    count = 0;
    while (count < k && next != NULL) {
        curr = next;
        next = next->next;
        count++;   
    }
    // recursively call for remaining lists
    if (next != NULL)
        curr->next = kAltReverse(next, k);
    return prev;
}

node* addnode(node *head, int data) {
    if (head == NULL)
        return new node(data);
    node *ptr = head;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = new node(data);
    return head;
}

void printList(node *head) {
    if (head == NULL)
        return;
    while (head != NULL) {
        cout<<head->data<<" ";
        head = head->next;
    }
}

int main() {
    node *head = NULL;
    head = addnode(head, 1);
    head = addnode(head, 2);
    head = addnode(head, 3);
    head = addnode(head, 4);
    head = addnode(head, 5);
    head = addnode(head, 6);
    head = addnode(head, 7);
    head = addnode(head, 8);
    head = addnode(head, 9);

    cout<<"list: ";
    printList(head);
    cout<<endl<<"k alt reverse: ";
    head = kAltReverse(head, 4);
    printList(head);
    cout<<endl;
    
    return 0;
}