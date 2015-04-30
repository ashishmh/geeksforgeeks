#include <iostream>
#include <queue>
using namespace std;

class node {
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

int getMaxWidth(node *root);
void inorder(node *root);

int getMaxWidth(node *root) {
    if (root == NULL)
        return 0;
    int max = 1;
    int count = 0;
    queue<node*> Q;
    Q.push(root);
    Q.push(NULL);
    while (true) {
        count = 0;
        while (Q.front() != NULL) {
            node *temp = Q.front();
            Q.pop();
            count++;
            if (temp->left != NULL)
                Q.push(temp->left);
            if (temp->right != NULL)
                Q.push(temp->right);
        }
        Q.pop();
        if (Q.empty())
            break;
        if (count > max)
            max = count;
        Q.push(NULL);
    }
    if (count > max)
        max = count;
    return max;
}

void inorder(node *root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main() {
    node *root                  = new node(1);
    root->left                  = new node(2);
    root->right                 = new node(3);
    root->left->left            = new node(4);
    root->left->right           = new node(5);
    root->left->right->left     = new node(10);
    root->left->right->right    = new node(11);
    root->right->right          = new node(8);
    root->right->right->left    = new node(6);
    root->right->right->right   = new node(7);

    cout<<"inorder of tree.."<<endl;
    inorder(root);

    cout<<endl<<"max width: ";
    cout<<getMaxWidth(root);

    cout<<endl<<endl;
}