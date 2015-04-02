// http://www.geeksforgeeks.org/in-place-conversion-of-sorted-dll-to-balanced-bst/
// code for method 2 in gfg

#include <iostream>
using namespace std;

class node {
public:
    int data;
    node *left, *right;
    node(int data) {
        this->data = data;
        this->left = NULL;  
        this->right = NULL;
    }
};

node* sortedListToBst(node *head);
node* sortedListToBstAux(node **head, int n);
int countNodes(node *head);
node* addnode(node *head, int data);
void printLeftToRight(node *head);
void preorder(node *root);
void inorder(node *root);

node* sortedListToBst(node *head) {
    int n = countNodes(head);
    return sortedListToBstAux(&head, n);
}

node* sortedListToBstAux(node **head, int n) {
    if (n <= 0)
        return NULL;
    
    node *left = sortedListToBstAux(head, n/2);
    node *root = (*head);
    root->left = left;
    (*head) = (*head)->right;
    root->right = sortedListToBstAux(head, n-n/2-1);

    return root;
}

int countNodes(node *head) {
    int count = 0;
    node *ptr = head;
    while (ptr != NULL) {
        count++;
        ptr = ptr->right;
    }
    return count;
}

node* addnode(node *head, int data) {
    if (head == NULL)
        return new node(data);
    node *ptr = head;
    while (ptr->right != NULL)
        ptr = ptr->right;
    ptr->right = new node(data);
    ptr->right->left = ptr;
    return head;
}

void printLeftToRight(node *head) {
    if (head == NULL)
        return;
    while (head != NULL) {
        cout<<head->data<<" ";
        head = head->right;
    }
}

void preorder(node *root) {
    if (root == NULL)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(node *root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main() {
    node *head = NULL;
    head = addnode(head, 1);
    head = addnode(head, 2);
    head = addnode(head, 3);
    head = addnode(head, 4);
    head = addnode(head, 5);
    head = addnode(head, 6);
    head = addnode(head, 7);

    cout<<"list: ";
    printLeftToRight(head);
    
    cout<<endl<<"preorder of BST: ";
    node *root = sortedListToBst(head);
    preorder(root);
    cout<<endl<<"inorder of BST: ";
    inorder(root);
    cout<<endl;
    
    return 0;
}