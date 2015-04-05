// http://www.geeksforgeeks.org/pairwise-swap-elements-of-a-given-linked-list-by-changing-links/

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

node* pairSwap(node *head);
node* addnode(node *head, int data);
void printList(node *head);

node* pairSwap(node *head) {
    if (head == NULL || head->next == NULL)
        return head;
    // store new head as 2nd node
    node *new_head = head->next;
    
    node *ptr1 = head;
    node *ptr2 = head->next;
    node *temp = ptr2->next;

    ptr2->next = ptr1;
    ptr1->next = pairSwap(temp);

    return new_head;
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

    cout<<"list: ";
    printList(head);
    cout<<endl<<"swap: ";
    head = pairSwap(head);
    printList(head);
    
    cout<<endl<<endl;
    return 0;
}