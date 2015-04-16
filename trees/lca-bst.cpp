// http://www.geeksforgeeks.org/lowest-common-ancestor-in-a-binary-search-tree/

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

bool isNodeInBST(node *root, int x);
void inorder(node *root);
void printArray(int *arr, int n);

node* lca(node *root, int a, int b) {
    if (root == NULL || !isNodeInBST(root, a) || !isNodeInBST(root, b))
        return NULL;

    if (root->data > a && root->data > b)
        return lca(root->left, a, b);
    if (root->data < a && root->data < b)
        return lca(root->right, a, b);
    return root;
}

bool isNodeInBST(node *root, int x) {
    if (root == NULL)
        return false;
    while (root != NULL) {
        if (x == root->data)
            return true;
        if (x < root->data)
            root = root->left;
        else root = root->right;
    }
    return false;
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
    node *root               = new node(20);
    root->left               = new node(8);
    root->right              = new node(22);
    root->left->left         = new node(4);
    root->left->right        = new node(12);
    root->left->right->left  = new node(10);
    root->left->right->right = new node(14);

    cout<<"inorder: ";
    inorder(root);

    cout<<endl;
    cout<<endl<<"lca of 10 and 14: "<<lca(root, 10, 14)->data;
    cout<<endl<<"lca of 14 and 8: "<<lca(root, 14, 8)->data;
    cout<<endl<<"lca of 10 and 22: "<<lca(root, 10, 22)->data;
    cout<<endl<<"lca of 10 and 88: ";
    node *ans = lca(root, 10, 88);
    ans ? cout<<ans->data : cout<<"NULL";

    cout<<endl<<endl;
}