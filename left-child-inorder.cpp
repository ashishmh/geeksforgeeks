// Print the nodes of a tree which have a left child and are themselves the left child of some node (in inorder)

#include <iostream>
#include <cstdio>
using namespace std;

class node
{
public:
	int data;
	node* left;
	node* right;
	node(int data) {
		this->data = data;
		left = right = NULL;
	}
};

node* createBinaryTree(node* root, int depth, int value) {
	if (depth < 1)
		return NULL;
	root = new node(value);
	root->left = createBinaryTree(root->left, depth-1, value*2);
	root->right = createBinaryTree(root->right, depth-1, value*2+1);
	return root;
}

void inorder(node* root, int left) {
	if (!root)
		return;
	inorder(root->left, 1);
	if (left == 1)
		cout<<root -> data<<" ";
	inorder(root->right, 0);
	return;
}

int main() {
    freopen("input.txt","r",stdin);

    int depth;
    cin>>depth;
    node* root;
    root = createBinaryTree(root, depth, 1);
	cout<<"Inorder traversal of nodes which have a left child and are themselves left child of some node: "<<endl;
	inorder(root, 1);
	cout<<endl;
    return 0;
}