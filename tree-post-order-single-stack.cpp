// post order traversal of tree using single stack
// http://www.geeksforgeeks.org/iterative-postorder-traversal-using-stack/

#include <iostream>
#include <stack>
using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;

	Node(int data) {
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

void postOrderSingleStack(Node* root) {
	stack<Node*> stack;
	do {
		if (root != NULL) {
			if (root->right != NULL)
				stack.push(root->right);
			stack.push(root);
			root = root->left;
		}
		else {
			root = stack.top();
			stack.pop();
			if (root->right != NULL && !stack.empty() && root->right == stack.top()) {
				Node* temp = stack.top();
				stack.pop();
				stack.push(root);
				root = root->right;
			}
			else {
				cout<<root->data<<" ";
				root = NULL;
			}
		}
	} while (!stack.empty());
}

int main() {
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->left->right->right = new Node(8);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	root->right->right->left = new Node(9);

	cout<<"Postorder traversal (single stack): ";
	postOrderSingleStack(root);
	cout<<endl<<endl;
	return 0;
}