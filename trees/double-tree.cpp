// http://www.geeksforgeeks.org/double-tree/

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

void doubleTree(node *root);
void printInorder(node* root);

void doubleTree(node *root) {
    if (root == NULL)
        return;
    doubleTree(root->left);
    doubleTree(root->right);
    node *new_node = new node(root->data);
    new_node->left = root->left;
    root->left = new_node;
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
    root                 = new node(2);
    root->left           = new node(1);
    root->right          = new node(3);

    cout<<"binary tree (inorder): ";
    printInorder(root);

    cout<<endl<<"double tree (inorder): ";
    doubleTree (root);
    printInorder(root);

    cout<<endl<<endl;
}