// http://www.geeksforgeeks.org/reverse-a-doubly-linked-list/

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* reverseDoubleList(Node *head);
Node* addNode(Node *head, int data);
void printLeftToRight(Node *head);
void printLeftToRight(Node *head);

Node* reverseDoubleList(Node *head) {
    if (head->right == NULL)
        return head;
    Node *newhead = reverseDoubleList(head->right);
    Node *ptr = head, *temp = head;
    while (ptr->right != NULL)
        ptr = ptr->right;
    newhead->left = NULL;
    ptr->right = temp;
    temp->left = ptr;
    temp->right = NULL;
    return newhead;
}

Node* addNode(Node *head, int data) {
    if (head == NULL)
        return new Node(data);
    Node *ptr = head;
    while (ptr->right != NULL)
        ptr = ptr->right;
    ptr->right = new Node(data);
    ptr->right->left = ptr;
    return head;
}

void printLeftToRight(Node *head) {
    if (head == NULL)
        return;
    while (head != NULL) {
        cout<<head->data<<" ";
        head = head->right;
    }
}

void printRightToLeft(Node *head) {
    if (head == NULL)
        return;
    while (head != NULL) {
        cout<<head->data<<" ";
        head = head->left;
    }
}

int main() {
    Node *head = NULL;
    head = addNode(head, 1);
    head = addNode(head, 2);
    head = addNode(head, 3);
    head = addNode(head, 4);
    head = addNode(head, 5);

    cout<<"original: ";
    printLeftToRight(head);
    cout<<endl<<"after reversal: ";
    head = reverseDoubleList(head);
    printLeftToRight(head);
    cout<<endl;
    
    return 0;
}