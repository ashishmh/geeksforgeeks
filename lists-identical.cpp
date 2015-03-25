// http://www.geeksforgeeks.org/identical-linked-lists/

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

bool isEqual(Node *head1, Node *head2);
Node* addNode(Node *head, int data);
void printList(Node *head);

bool isEqual(Node *head1, Node *head2) {
    while (true) {
        if (head1 == NULL && head2 == NULL)
            return true;
        if (head1 == NULL && head2 != NULL)
            return false;
        if (head1 != NULL && head2 == NULL)
            return false;
        if (head1->data != head2->data)
            return false;
        head1 =head1->next;
        head2 =head2->next;
    }
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
    head1 = addNode(head1, 5);

    Node *head2 = NULL;
    head2 = addNode(head2, 1);
    head2 = addNode(head2, 2);
    head2 = addNode(head2, 3);
    head2 = addNode(head2, 4);

    cout<<"list 1: ";
    printList(head1);
    cout<<endl<<"list 2: ";
    printList(head2);
    cout<<endl<<"equality: ";
    isEqual(head1, head2) ? cout<<"true" : cout<<"false";
    cout<<endl;
    
    return 0;
}