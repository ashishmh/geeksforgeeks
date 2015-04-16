// http://www.geeksforgeeks.org/write-an-efficient-c-function-to-convert-a-tree-into-its-mirror-tree/

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

void mirrorTree(node* root);
void swapTree(node* root);
void levelOrderIteration(node *root);

void mirrorTree(node* root) {
    if (root == NULL)
        return;
    mirrorTree(root->left);
    mirrorTree(root->right);
    swapTree(root);
}

void swapTree(node* root) {
    node* temp = root->left;
    root->left = root->right;
    root->right = temp;
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
    node *root = new node(1);
    root->left        = new node(2);
    root->right       = new node(3);
    root->left->left  = new node(4);
    root->left->right = new node(5); 

    cout<<"level order: ";
    levelOrderIteration(root);

    mirrorTree(root);
    cout<<endl<<"after mirror.."<<endl;
    cout<<"level order: ";
    levelOrderIteration(root);

    cout<<endl<<endl;
}