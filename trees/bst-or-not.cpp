// http://www.geeksforgeeks.org/a-program-to-check-if-a-binary-tree-is-bst-or-not/

#include <iostream>
#define MIN numeric_limits<int>::min()
#define MAX numeric_limits<int>::max()
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

int isBst(node *root);
int isBstAux(node *root, int min, int max);
void inorder(node *root);
void printArray(int *arr, int n);

int isBst(node *root) {
    return isBstAux(root, MIN, MAX);
}

int isBstAux(node *root, int min, int max) {
    if (root == NULL)
        return 1;

    if (root->data < min || root->data > max)
        return 0;

    return (
        isBstAux(root->left, min, root->data-1) &&
        isBstAux(root->right, root->data+1, max)
        );
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

    if (isBst(root))
        cout<<endl<<"input tree is BST..";
    else cout<<endl<<"input tree is not BST..";

    cout<<endl<<endl;
}