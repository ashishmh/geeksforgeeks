// http://www.geeksforgeeks.org/write-a-c-program-to-get-count-of-leaf-nodes-in-a-binary-tree/

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

void inorder(node *root);
void printArray(int *arr, int n);

int countLeaf(node *root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    int left_count = countLeaf(root->left);
    int right_count = countLeaf(root->right);
    return left_count+right_count;
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
    node *root        = new node(1);
    root->left        = new node(2);
    root->right       = new node(3);
    root->left->left  = new node(4);
    root->left->right = new node(5);   

    cout<<"inorder: ";
    inorder(root);

    cout<<endl<<"count: "<<countLeaf(root);

    cout<<endl<<endl;
}