// http://www.geeksforgeeks.org/level-order-traversal-in-spiral-form/

#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node* left;
    node* right;
    node(int data) {
        this->data = data;
        this->left = NULL;
    }
};

void levelOrderSpiral(node *root);
void printGivenLevel(node *root, int level, int ltr);
int findHeight(node *root);
void inorder(node *root);
void printArray(int *arr, int n);

void levelOrderSpiral(node *root) {
    if (root == NULL)
        return;
    int ltr = -1;
    int height = findHeight(root);
    for (int i = 1; i <= height; i++) {
        printGivenLevel(root, i, ltr);
        ltr = -ltr;
    }
}

void printGivenLevel(node *root, int level, int ltr) {
    if (root == NULL)
        return;
    if (level == 1) {
        cout<<root->data<<" ";
        return;
    }
    else if (level > 1) {
        if (ltr == 1) {
            printGivenLevel(root->left, level-1, ltr);
            printGivenLevel(root->right, level-1, ltr);
        }
        else {
            printGivenLevel(root->right, level-1, ltr);
            printGivenLevel(root->left, level-1, ltr);
        }
    }
}

int findHeight(node *root) {
    if (root == NULL)
        return 0;
    int lh = findHeight(root->left);
    int rh = findHeight(root->right);
    if (lh > rh)
        return lh+1;
    else return rh+1;
}

void inorder(node *root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void printArray(int *arr, int n) {
    for (int i = 0 ; i < n ; i++)
        cout<<arr[i]<<" ";
}

int main() {
    node *root               = new node(1);
    root->left               = new node(2);
    root->right              = new node(3);
    root->left->left         = new node(4);
    root->left->right        = new node(5);
    root->right->left        = new node(6);
    root->right->right       = new node(7); 

    cout<<"inorder: ";
    inorder(root);

    cout<<endl<<"spiral order: ";
    levelOrderSpiral(root);
    cout<<endl<<endl;
}