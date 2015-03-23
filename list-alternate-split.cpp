// http://www.geeksforgeeks.org/alternating-split-of-a-given-singly-linked-list/

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

void alternateSplit(Node *head);
Node* addNode(Node *head, int data);
void printList(Node *head);

void alternateSplit(Node *head) {
    if (head == NULL || head->next == NULL)
        return;
    Node* list2 = NULL;
    Node *prev = head, *curr = head->next;
    while (curr != NULL && curr->next != NULL) {
        prev->next = curr->next;
        prev = prev->next;
        list2 = addNode(list2, curr->data);
        curr = curr->next->next;
    }
    if (curr != NULL)
        list2 = addNode(list2, curr->data);
    if (prev->next != NULL)
        prev->next = NULL;
    cout<<endl;
    printList(head);
    cout<<endl;
    printList(list2);
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
    head = addNode(head, 0);
    head = addNode(head, 1);
    head = addNode(head, 0);
    head = addNode(head, 1);
    head = addNode(head, 0);
    head = addNode(head, 1);

    cout<<"list: ";
    printList(head);
    cout<<endl<<"alternate split..";
    alternateSplit(head);
    cout<<endl;
    
    return 0;
}