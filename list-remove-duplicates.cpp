// http://www.geeksforgeeks.org/remove-duplicates-from-a-sorted-linked-list/

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

void printList(Node *head);

void removeDuplicates(Node *head) {
    if (head == NULL || head->next == NULL)
        return;
    Node *prev, *curr;
    prev = head;
    curr = head->next;
    while (curr != NULL) {
        if (prev->data == curr->data) {
            prev->next = curr->next;
            curr = prev->next;
            continue;
        }
        prev = prev->next;
        curr = curr->next;
    }
}

void printList(Node *head) {
    if (head == NULL)
        return;
    while (head != NULL) {
        cout<<head->data<<" ";
        head = head->next;
    }
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(3);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(4);
    
    cout<<"original: ";
    printList(head);
    removeDuplicates(head);
    cout<<endl<<"after duplicate removal: ";
    printList(head);
    cout<<endl;
    
    return 0;
}