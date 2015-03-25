// http://www.geeksforgeeks.org/sorted-insert-for-circular-linked-list/

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

node* sortedInsertnode(node *head, int ele);
void makeCircular(node *head);
node* addnode(node *head, int data);
void printCircularList(node *head);

node* sortedInsertnode(node *head, int ele) {
    node *newnode = new node(ele);
    // case 1: list empty
    if (head == NULL) {
        head = newnode;
        head->next = head;
    }
    // case 2: insertion before head
    else if (ele <= head->data) {
        node *ptr = head;
        while (ptr->next != head)
            ptr = ptr->next;
        ptr->next = newnode;
        newnode->next = head;
        head = newnode;
    }
    // case 3: insertion after head
    else {
        node *ptr = head, *start = head, *temp;
        while (ptr->next != start && ptr->data < ele) {
            temp = ptr;
            ptr = ptr->next;
        }
        if (ptr->next == start && ptr->data < ele) {
            newnode->next = ptr->next;
            ptr->next = newnode;
        }
        else {
            newnode->next = temp->next;
            temp->next = newnode;    
        }
    }
    return head;
}

void makeCircular(node *head) {
    if (head == NULL)
        return;
    node *ptr = head;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = head;
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

void printCircularList(node *head) {
    if (head == NULL)
        return;
    node *start = head;
    while (head->next != start) {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<head->data;
}

int main() {
    node *head = NULL;
    head = addnode(head, 2);
    head = addnode(head, 5);
    head = addnode(head, 8);
    head = addnode(head, 10);
    makeCircular(head);

    cout<<"original: ";
    printCircularList(head);
    cout<<endl<<"after inserting (1,9,11): ";
    head = sortedInsertnode(head, 1);
    head = sortedInsertnode(head, 9);
    head = sortedInsertnode(head, 11);
    printCircularList(head);
    cout<<endl;
    
    return 0;
}