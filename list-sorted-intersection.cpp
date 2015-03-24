// http://www.geeksforgeeks.org/intersection-of-two-sorted-linked-lists/

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

Node* intersection1(Node *head1, Node *head2);            // complexity (m+n)
Node* intersection2(Node *head1, Node *head2);            // complexity (mn)
Node* addNode(Node *head, int data);
void printList(Node *head);

Node* intersection1(Node *head1, Node *head2) {
    Node *head = NULL;
    Node *ptr = head2;
    while (head1 != NULL && head2 != NULL) {
        // if nodes of both lists are equal, copy it to new list and advance both lists
        if (head1->data == head2->data) {
            head = addNode(head, head1->data);
            head1 = head2->next;
            head2 = head2->next;
        }
        // else advance only smaller list
        else if (head1->data < head2->data)
            head1 = head1->next;
        else head2 = head2->next;
    }
    return head;
}

Node* intersection2(Node *head1, Node *head2) {
    Node *head = NULL;
    Node *ptr = head2;
    // two nested loops.. results in time complexity of (mn)
    while (head1 != NULL) {
        ptr = head2;
        while (ptr != NULL) {
            if (ptr->data == head1->data)
                head = addNode(head, ptr->data);
            ptr = ptr->next;
        }
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
    head1 = addNode(head1, 2);
    head1 = addNode(head1, 3);
    head1 = addNode(head1, 4);
    head1 = addNode(head1, 6);

    Node *head2 = NULL;
    head2 = addNode(head2, 2);
    head2 = addNode(head2, 4);
    head2 = addNode(head2, 6);
    head2 = addNode(head2, 8);


    cout<<"list 1: ";
    printList(head1);
    cout<<endl<<"list 2: ";
    printList(head2);
    cout<<endl<<"intersection (m+n): ";
    head1 = intersection1(head1, head2);
    printList(head1);
    cout<<endl<<"intersection (mn) : ";
    head1 = intersection2(head1, head2);
    printList(head1);
    cout<<endl;
    
    return 0;
}