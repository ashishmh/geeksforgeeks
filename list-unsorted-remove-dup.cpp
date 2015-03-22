// http://www.geeksforgeeks.org/remove-duplicates-from-an-unsorted-linked-list/

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

void removeDuplicates(Node *head);
Node* addNode(Node *head, int data);
void printList(Node *head);

void removeDuplicates(Node *head) {
    if (head == NULL || head->next == NULL)
        return;
    int count[1000];
    Node *prev = head, *curr = head;
    
    while (curr != NULL) {
        // if element already in hash table, delete it
        if (count[curr->data] == 1) {
            if (curr->next != NULL)
                prev->next = curr->next;
            else
                prev->next = NULL;
        }
        // if element not in hash table, add it
        else {
            count[curr->data] = 1;
            prev = curr;
        }
        curr = curr->next;
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
    Node *head = NULL;
    head = addNode(head, 8);
    head = addNode(head, 1);
    head = addNode(head, 2);
    head = addNode(head, 3);
    head = addNode(head, 4);
    head = addNode(head, 7);
    head = addNode(head, 5);
    head = addNode(head, 3);
    head = addNode(head, 1);
    head = addNode(head, 5);

    cout<<"original: ";
    printList(head);
    removeDuplicates(head);
    cout<<endl<<"after duplicate removal: ";
    printList(head);
    cout<<endl;
    
    return 0;
}