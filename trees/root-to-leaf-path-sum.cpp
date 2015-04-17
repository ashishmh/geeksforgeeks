// http://www.geeksforgeeks.org/root-to-leaf-path-sum-equal-to-a-given-number/

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

void rootToLeafPath(node *root, int x);
void rootToLeafPathAux(node *root, int *path, int pathlen, int x);
int arraySum(int *arr, int n);

void rootToLeafPath(node *root, int x) {
    if (root == NULL)
        return;
    int path[1000];
    rootToLeafPathAux(root, path, 0, x);
}

void rootToLeafPathAux(node *root, int *path, int pathlen, int x) {
    if (root != NULL) {
        path[pathlen] = root->data;
        pathlen++;
    }
    if (root->left == NULL && root->right == NULL) {
        if (x == arraySum(path, pathlen))
            cout<<"path equal to "<<x;
        return;
    }
    else {
        if (root->left != NULL)
            rootToLeafPathAux(root->left, path, pathlen, x);
        if (root->right != NULL)
            rootToLeafPathAux(root->right, path, pathlen, x);
    }
}

int arraySum(int *arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum = sum + arr[i];
    return sum;
}

int main() {
    node *root               = new node(1);
    root->left               = new node(2);
    root->right              = new node(3);
    root->left->left         = new node(4);
    root->left->right        = new node(5);
    root->left->left->left   = new node(6);

    cout<<"root to leaf path sum.."<<endl;
    rootToLeafPath(root, 13);

    cout<<endl<<endl;
}