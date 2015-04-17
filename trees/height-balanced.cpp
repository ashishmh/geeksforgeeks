// http://www.geeksforgeeks.org/how-to-determine-if-a-binary-tree-is-balanced/

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

bool isBalanced(node *root);
int height(node *root);

bool isBalanced(node *root) {
    if (root == NULL)
        return true;
    int l_height = height(root->left);
    int r_height = height(root->right);

    return (
        (abs(l_height - r_height) < 2) &&
        isBalanced(root->left) &&
        isBalanced(root->right)
        );
}

int height(node *root) {
    if (root == NULL)
        return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return (1 + max(lh, rh));
}

int main() {
    node *root1               = new node(1);
    root1->left               = new node(2);
    root1->right              = new node(3);
    root1->left->left         = new node(4);
    root1->left->right        = new node(5);
    root1->left->left->left   = new node(8);

    node *root2               = new node(1);
    root2->left               = new node(2);
    root2->right              = new node(3);
    root2->left->left         = new node(4);
    root2->left->right        = new node(5);

    cout<<endl<<"tree1 is balanced: ";
    isBalanced(root1) ? cout<<"yes" : cout<<"no";

    cout<<endl<<"tree2 is balanced: ";
    isBalanced(root2) ? cout<<"yes" : cout<<"no";

    cout<<endl<<endl;
}