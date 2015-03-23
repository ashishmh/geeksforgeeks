// http://www.geeksforgeeks.org/merge-two-sorted-linked-lists/

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

Node* mergeSortedLists(Node *head1, Node *head2);
Node* addNode(Node *head, int data);
void printList(Node *head);

Node* mergeSortedLists(Node *head1, Node *head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;
    Node *head = NULL;

    while (head1 != NULL && head2 != NULL) {
        if (head1->data < head2->data) {
            head = addNode(head, head1->data);
            head1 = head1->next;
        }
        else {
            head = addNode(head, head2->data);
            head2 = head2->next;
        }
    }

    if (head1 == NULL)
        while (head2 != NULL) {
            head = addNode(head, head2->data);
            head2 = head2->next;
        }
    else if (head2 == NULL)
        while (head1 != NULL) {
            head = addNode(head, head1->data);
            head1 = head1->next;
        }

    return head;
}

Node* addNode(Node *head, int data) {
    if (head == NULL)
        return new Node(data);
    Node *ptr = head;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = new Node(data);
    return head;
}

void printList(Node *head) {
    if (head == NULL)
        return;
    while (head != NULL) {
        cout<<head->data<<" ";
        head = head->next;
    }
}

int main() {
    Node *head1 = NULL;
    head1 = addNode(head1, 1);
    head1 = addNode(head1, 3);
    head1 = addNode(head1, 6);
    head1 = addNode(head1, 8);
    head1 = addNode(head1, 9);

    Node *head2 = NULL;
    head2 = addNode(head2, 2);
    head2 = addNode(head2, 4);
    head2 = addNode(head2, 5);
    head2 = addNode(head2, 7);
    head2 = addNode(head2, 10);
    head2 = addNode(head2, 12);


    cout<<"list 1: ";
    printList(head1);
    cout<<endl<<"list 2: ";
    printList(head2);
    head1 = mergeSortedLists(head1, head2);
    cout<<endl<<"after merge: ";
    printList(head1);
    cout<<endl;
    
    return 0;
}