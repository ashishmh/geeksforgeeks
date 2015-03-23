// http://www.geeksforgeeks.org/delete-a-node-in-a-doubly-linked-list/

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

void deleteNode(Node *head, int data);
Node* addNode(Node *head, int data);
void printLeftToRight(Node *head);
void printLeftToRight(Node *head);

void deleteNode(Node *head, int data) {
    if (head == NULL)
        return;
    Node *ptr = head;
    while (ptr != NULL && ptr->data != data)
        ptr = ptr->right;
    // element not in list
    if (ptr == NULL) {
        cout<<endl<<"element not in list..";
        return;
    }
    // element is last node
    if (ptr->right == NULL) {
        ptr->left->right = NULL;
        return;
    }
    // element is anything except last
    ptr->data = ptr->right->data;
    ptr->right = ptr->right->right;
    if (ptr->right != NULL)
        ptr->right->left = ptr;
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
    cout<<endl<<"after deleting 1,3,5: ";
    deleteNode(head, 1);
    deleteNode(head, 3);
    deleteNode(head, 5);
    printLeftToRight(head);
    cout<<endl;
    
    return 0;
}