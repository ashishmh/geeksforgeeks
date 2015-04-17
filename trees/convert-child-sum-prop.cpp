// http://www.geeksforgeeks.org/convert-an-arbitrary-binary-tree-to-a-tree-that-holds-children-sum-property/

#include <iostream>
#include <queue>
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

void convertTree(node *root);
void incrementSubTree(node *root, int diff);
void levelOrderIteration(node *root);

void convertTree(node *root) {
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return;

    convertTree(root->left);
    convertTree(root->right);

    int left_data = 0;
    int right_data = 0;
    int diff;

    if (root->left != NULL)
        left_data = root->left->data;
    if (root->right != NULL)
        right_data = root->right->data;

    diff = root->data - (left_data + right_data);
    if (diff < 0)
        root->data = root->data + -diff;
    if (diff > 0)
        incrementSubTree(root, diff);
}

void incrementSubTree(node *root, int diff) {
    if (root->left != NULL) {
        root->left->data  = root->left->data + diff;
        incrementSubTree(root->left, diff);
    }
    else if (root->right != NULL) {
        root->right->data = root->right->data + diff;
        incrementSubTree(root->right, diff);
    }
}

void levelOrderIteration(node *root) {
    if (root == NULL)
        return;
    queue<node*> q;
    q.push(root);
    while (!q.empty()) {
        root = q.front();
        q.pop();
        if (root->left != NULL)
            q.push(root->left);
        if (root->right != NULL)
            q.push(root->right);
        cout<<root->data<<" ";
    }
}

int main() {
    node *root               = new node(50);
    root->left               = new node(7);
    root->right              = new node(2);
    root->left->left         = new node(3);
    root->left->right        = new node(5);
    root->right->left        = new node(1);
    root->right->right       = new node(30);

    cout<<"level order: ";
    levelOrderIteration(root);

    cout<<endl<<"convert to statisfy child sum property.."<<endl;
    convertTree(root);
    cout<<"level order: ";
    levelOrderIteration(root);

    cout<<endl<<endl;
}