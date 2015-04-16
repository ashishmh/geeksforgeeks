// http://www.geeksforgeeks.org/check-for-children-sum-property-in-a-binary-tree/

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

bool isSumProperty(node *root);
void inorder(node *root);

bool isSumProperty(node *root) {
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return true;
    int left_data = 0;
    int right_data = 0;

    if (root->left != NULL)
        left_data = root->left->data;
    if (root->right != NULL)
        right_data = root->right->data;

    return ((root->data == left_data+right_data) &&
        isSumProperty(root->left)&&
        isSumProperty(root->right)
        );
}

void inorder(node *root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main() {
    node *root               = new node(10);
    root->left               = new node(8);
    root->right              = new node(2);
    root->left->left         = new node(3);
    root->left->right        = new node(5);
    root->right->left        = new node(2);

    cout<<"inorder: ";
    inorder(root);

    cout<<endl<<"child sum property: ";
    isSumProperty(root) ? cout<<"yes" : cout<<"no";
    cout<<endl<<endl;
}