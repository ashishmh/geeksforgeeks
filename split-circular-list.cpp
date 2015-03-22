// http://www.geeksforgeeks.org/split-a-circular-linked-list-into-two-halves/

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

void splitCircular(Node *head);
void makeCircular(Node *head);
Node* addNode(Node *head, int data);
void printCircularList(Node *head);

void splitCircular(Node *head) {
    if (head == NULL || head->next == NULL)
        return;
    Node *slow = head;
    Node *fast = head;
    while (fast->next != head && fast->next->next != head) {
        fast = fast->next->next;
        slow = slow->next;
    }
    
    // setting head of second list
    Node *list2 = slow->next;
    if (fast->next->next == head)
        fast = fast->next;
    fast->next = list2;   
    // setting head of first list
    Node *list1 = head;
    slow->next = list1;

    cout<<endl<<"list 1: ";
    printCircularList(list1);
    cout<<endl<<"list 2: ";
    printCircularList(list2);
}

void makeCircular(Node *head) {
    if (head == NULL)
        return;
    Node *ptr = head;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = head;
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

void printCircularList(Node *head) {
    if (head == NULL)
        return;
    Node *start = head;
    while (head->next != start) {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<head->data;
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
    makeCircular(head);

    cout<<"original: ";
    printCircularList(head);
    cout<<endl<<"after splitting..";
    splitCircular(head);
    cout<<endl;
    
    return 0;
}