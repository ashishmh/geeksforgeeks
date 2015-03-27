// http://www.geeksforgeeks.org/delete-nodes-which-have-a-greater-value-on-right-side/

#include <iostream>
#define INF numeric_limits<int>::min()
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

void deleteRight(node *head);
node* deleteRightRecursive(node *head);
node* reverseRecursive(node *head);
node* addnode(node *head, int data);
void printList(node *head);

void deleteRight(node *head) {
    if (head == NULL || head->next == NULL)
        return;
    node *ptr = head, *ptr1;
    while (ptr != NULL) {
        ptr1 = ptr->next;
        while (ptr1 != NULL) {
            if (ptr1->data > ptr->data) {
                ptr->data = ptr1->data;
                ptr->next = ptr1->next;
            }
            ptr1 = ptr1->next;
        }
        ptr = ptr->next;
    }
}

node* deleteRightRecursive(node *head) {
    if (head == NULL || head->next == NULL)
        return head;
    // reverse the list
    head = reverseRecursive(head);
    // keep max and delete all nodes < max
    int max = head->data;
    node *ptr = head->next;
    node *temp = head;
    while (ptr != NULL) {
        if (ptr->data < max) {
            temp->next = ptr->next;
            ptr = temp->next;
        }
        else {
            max = ptr->data;
            temp = ptr;
            ptr = ptr->next;
        }
    }
    // reverse list again
    head = reverseRecursive(head);
    // return new head
    return head;
}

node* reverseRecursive(node *head) {
    if (head == NULL || head->next == NULL)
        return head;
    node *new_head = reverseRecursive(head->next);
    node *ptr = new_head;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = head;
    head->next = NULL;
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
    node *head1 = NULL;
    head1 = addnode(head1, 12);
    head1 = addnode(head1, 15);
    head1 = addnode(head1, 10);
    head1 = addnode(head1, 11);
    head1 = addnode(head1, 5);
    head1 = addnode(head1, 6);
    head1 = addnode(head1, 2);
    head1 = addnode(head1, 3);
    
    node *head2 = NULL;
    head2 = addnode(head2, 10);
    head2 = addnode(head2, 20);
    head2 = addnode(head2, 30);
    head2 = addnode(head2, 40);
    head2 = addnode(head2, 50);
    head2 = addnode(head2, 60);

    cout<<"list 1: ";
    printList(head1);
    cout<<endl<<"deleting greater right nodes: ";
    deleteRight(head1);
    printList(head1);

    cout<<endl<<endl<<"list 2: ";
    printList(head2);
    cout<<endl<<"deleting greater right nodes: ";
    head2 = deleteRightRecursive(head2);
    printList(head2);
    cout<<endl;
    
    return 0;
}