// http://www.geeksforgeeks.org/construct-tree-from-given-inorder-and-preorder-traversal/

#include <iostream>
using namespace std;

class node
{
public:
    char data;
    node* left;
    node* right;
    node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildTree(char *in, char *pre, int beg, int end);
int searchNode(char *arr, int beg, int end, char x);
void inorder(node* root);

node* buildTree(char *in, char *pre, int beg, int end) {
    if (beg > end)
        return NULL;
    static int pre_index = beg;
    node *root = new node(pre[pre_index++]);
    // if root has no children, return it
    if (beg == end)
        return root;

    int in_index = searchNode(in, beg, end, root->data);
    // recursively build left and right subtree
    root->left = buildTree(in, pre, beg, in_index-1);
    root->right = buildTree(in, pre, in_index+1, end);

    return root;
}

int searchNode(char *arr, int beg, int end, char x) {
    int i;
    for (i = beg; i <= end; i++)
        if (x == arr[i])
            break;
    return i;
}

void inorder(node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main() {
    char in[] = {'D', 'B', 'E', 'A', 'F', 'C'};
    char pre[] = {'A', 'B', 'D', 'E', 'C', 'F'};
    int len = sizeof(in)/sizeof(in[0]);

    node *root = buildTree(in, pre, 0, len-1);
    cout<<"inorder: ";
    inorder(root);

    cout<<endl<<endl;
}