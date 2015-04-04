// http://www.geeksforgeeks.org/delete-n-nodes-after-m-nodes-of-a-linked-list/

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

void deleteMN(node *head, int m, int n);
node* addnode(node *head, int data);
void printList(node *head);

void deleteMN(node *head, int m, int n) {
    if (head == NULL || head->next == NULL)
        return;

    node *ptr1 = head, *ptr2 = head;
    while (ptr2 != NULL) {
        for (int i = 0; ptr2 != NULL && i < m; i++) {
            ptr1 = ptr2;
            ptr2 = ptr2->next;
        }
        if (ptr2 == NULL)
            return;
        for (int i = 0; ptr2 != NULL && i < n; i++) {
            ptr2 = ptr2->next;
        }
        ptr1->next = ptr2;
    }
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

    cout<<"list: ";
    printList(head);
    cout<<endl<<"retain m, delete n: "<<endl;
    deleteMN(head, 3, 2);
    printList(head);
    
    cout<<endl<<endl;
    return 0;
}