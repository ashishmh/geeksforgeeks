// http://www.geeksforgeeks.org/binary-tree-to-binary-search-tree-conversion/

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
        this->right = NULL;
    }
};

void binaryTreeToBST(node *root);
void arrayToBST(node *root, int *arr);
int countNodes(node *root);
void storeInorder(node *root, int *arr);
void printInorder(node* root);

void binaryTreeToBST(node *root) {
    if (root == NULL)
        return;
    int n = countNodes(root);
    int *arr = new int[n];
    storeInorder(root, arr);
    sort(arr, arr+n);
    arrayToBST(root, arr);
}

void arrayToBST(node *root, int *arr) {
    if (root == NULL)
        return;
    static int i = 0;
    arrayToBST(root->left, arr);
    root->data = arr[i];
    i++;
    arrayToBST(root->right, arr);
}

int countNodes(node *root) {
    if (root == NULL)
        return 0;
    return (1 +
        countNodes(root->left) +
        countNodes(root->right));
}

void storeInorder(node *root, int *arr) {
    static int i = 0;
    if (root == NULL)
        return;
    storeInorder(root->left, arr);
    arr[i] = root->data;
    i++;
    storeInorder(root->right, arr);
}

void printInorder(node* root) {
    if (root == NULL)
        return;
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

int main() {
    node *root = NULL;
    root = new node(10);
    root->left = new node(30);
    root->right = new node(15);
    root->left->left = new node(20);
    root->right->right = new node(5);

    cout<<"binary tree (inorder): ";
    printInorder(root);

    cout<<endl<<"converted BST (inorder): ";
    binaryTreeToBST (root);
    printInorder(root);

    cout<<endl<<endl;
}