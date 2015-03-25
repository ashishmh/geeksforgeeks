// http://www.geeksforgeeks.org/merge-sort-for-linked-list/

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

Node* mergeSort(Node *head);
Node* sortedMerge(Node *a, Node *b);
Node* splitListHalf(Node* head);
Node* addNode(Node *head, int data);
void printList(Node *head);

Node* mergeSort(Node *head) {
    if (head == NULL || head->next == NULL)
        return head;
    
    // splitting list in half
    Node *a = head, *b;
    b = splitListHalf(a);
    
    // sorting both lists
    a = mergeSort(a);
    b = mergeSort(b);
    
    // merging both sorted lists
    Node* newhead = sortedMerge(a, b);
    return newhead;
}

Node* sortedMerge(Node *a, Node *b) {
    if (a == NULL) return b;
    else if (b == NULL) return a;
    Node *head = NULL;
    while (a != NULL && b != NULL) {
        if (a->data < b->data) {
            head = addNode(head, a->data);
            a = a->next;
        }
        else {
            head = addNode(head, b->data);
            b = b->next;
        }
    }
    if (a == NULL)
        while (b != NULL) {
            head = addNode(head, b->data);
            b = b->next;
        }
    if (b == NULL)
        while (a != NULL) {
            head = addNode(head, a->data);
            a = a->next;
        }
    return head;
}

Node* splitListHalf(Node* head) {
    if (head == NULL || head->next == NULL)
        return head;
    Node *slow = head, *fast = head->next;
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    Node* ptr = slow->next;
    slow->next = NULL;
    return ptr;
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
    head = addNode(head, 3);
    head = addNode(head, 0);
    head = addNode(head, 11);
    head = addNode(head, 2);
    head = addNode(head, 6);
    head = addNode(head, 7);

    cout<<"list: ";
    printList(head);
    cout<<endl<<"merge sort: ";
    head = mergeSort(head);
    printList(head);
    cout<<endl;
    
    return 0;
}