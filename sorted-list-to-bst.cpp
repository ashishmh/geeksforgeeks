// http://www.geeksforgeeks.org/sorted-linked-list-to-balanced-bst/
// code for method 2 in gfg

#include <iostream>
using namespace std;

class lnode {
public:
    int data;
    lnode *next;
    lnode(int data) {
        this->data = data;
        this->next = NULL;  
    }
};

class tnode {
public:
    int data;
    tnode *left, *right;
    tnode(int data) {
        this->data = data;
        this->left = NULL;  
        this->right = NULL;
    }
};

tnode* sortedListToBst(lnode *head);
tnode* sortedListToBstAux(lnode **head, int n);
int countNodes(lnode *head);
lnode* addnode(lnode *head, int data);
void printList(lnode *head);
void preorder(tnode *root);
void inorder(tnode *root);

tnode* sortedListToBst(lnode *head) {
    int n = countNodes(head);
    return sortedListToBstAux(&head, n);
}

tnode* sortedListToBstAux(lnode **head, int n) {
    if (n <= 0)
        return NULL;
    
    tnode *left = sortedListToBstAux(head, n/2);
    tnode *root = new tnode((*head)->data);
    root->left = left;
    (*head) = (*head)->next;
    root->right = sortedListToBstAux(head, n-n/2-1);

    return root;
}

int countNodes(lnode *head) {
    int count = 0;
    lnode *ptr = head;
    while (ptr != NULL) {
        count++;
        ptr = ptr->next;
    }
    return count;
}

lnode* addnode(lnode *head, int data) {
    if (head == NULL)
        return new lnode(data);
    lnode *ptr = head;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = new lnode(data);
    return head;
}

void printList(lnode *head) {
    if (head == NULL)
        return;
    while (head != NULL) {
        cout<<head->data<<" ";
        head = head->next;
    }
}

void preorder(tnode *root) {
    if (root == NULL)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(tnode *root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main() {
    lnode *head = NULL;
    head = addnode(head, 1);
    head = addnode(head, 2);
    head = addnode(head, 3);
    head = addnode(head, 4);
    head = addnode(head, 5);
    head = addnode(head, 6);
    head = addnode(head, 7);

    cout<<"list: ";
    printList(head);
    
    cout<<endl<<"preorder of BST: ";
    tnode *root = sortedListToBst(head);
    preorder(root);
    cout<<endl<<"inorder of BST: ";
    inorder(root);
    cout<<endl;
    
    return 0;
}