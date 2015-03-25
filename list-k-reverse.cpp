// http://www.geeksforgeeks.org/reverse-a-list-in-groups-of-given-size/

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

Node* kReverse(Node *head, int k);
Node* addNode(Node *head, int data);
void printList(Node *head);

Node* kReverse(Node *head, int k) {
    Node *curr = head; 
    Node *prev = NULL;
    Node *next = NULL;
    int count = 0;
    while (curr != NULL && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    if (next != NULL)
        head->next = kReverse(next, k);
    return prev;
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
    Node *head = NULL;
    head = addNode(head, 1);
    head = addNode(head, 2);
    head = addNode(head, 3);
    head = addNode(head, 4);
    head = addNode(head, 5);
    head = addNode(head, 6);
    head = addNode(head, 7);
    head = addNode(head, 8);

    cout<<"list: ";
    printList(head);
    cout<<endl<<"kth reverse: ";
    head = kReverse(head, 3);
    printList(head);
    cout<<endl;
    
    return 0;
}