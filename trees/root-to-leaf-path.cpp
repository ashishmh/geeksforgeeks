// http://www.geeksforgeeks.org/given-a-binary-tree-print-out-all-of-its-root-to-leaf-paths-one-per-line/

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

void rootToLeafPath(node *root);
void rootToLeafPathAux(node *root, int *path, int pathlen);
void printArray(int *arr, int n);

void rootToLeafPath(node *root) {
    if (root == NULL)
        return;
    int path[1000];
    rootToLeafPathAux(root, path, 0);
}

void rootToLeafPathAux(node *root, int *path, int pathlen) {
    if (root == NULL)
        return;

    path[pathlen] = root->data;
    pathlen++;

    if (root->left == NULL && root->right == NULL) {
        printArray(path, pathlen);
        cout<<endl;
    }
    else {
        rootToLeafPathAux(root->left, path, pathlen);
        rootToLeafPathAux(root->right, path, pathlen);
    }
}

void printArray(int *arr, int n) {
    for (int i = 0 ; i < n ; i++)
        cout<<arr[i]<<" ";
}

int main() {
    node *root = new node(1);
    root->left        = new node(2);
    root->right       = new node(3);
    root->left->left  = new node(4);
    root->left->right = new node(5);
    root->right->left  = new node(6);
    root->right->left->right  = new node(7);

    rootToLeafPath(root);

    cout<<endl;
}