// http://www.geeksforgeeks.org/the-great-tree-list-recursion-problem/

#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node *left, *right;
	Node(int data) {
		this->data = data;
		left = right = NULL;
	}
};

Node* treeToList(Node *root);
Node* joinList(Node *listA, Node *listB); 		// joins two circular linked lists
void joinNode(Node *a, Node *b); 				// joins a to b
void printCircularList(Node *head);				// prints circular linked list
Node* treeInsert(Node* root, int data); 		// inserts elements in BST

Node* treeToList(Node *root) {
	if (root == NULL)
		return root;
	Node *leftList = treeToList(root->left); 	// convert left sub-tree to list
	Node *rightList = treeToList(root->right); 	// convert right sub-tree to list
	// make root an independent list of single element
	root->left = root;
	root->right = root;
	// join leftList & root and then the resultant list & rightList
	leftList = joinList(leftList, root);
	leftList = joinList(leftList, rightList);
	return leftList;
}

Node* joinList(Node *listA, Node *listB) {
	if (listA == NULL)
		return listB;
	if (listB == NULL)
		return listA;
	
	Node *aLast, *bLast;
	aLast = listA->left;
	bLast = listB->left;

	joinNode(aLast, listB);
	joinNode(bLast, listA);

	// still have to figure out why this doesn't work
	// joinNode(listA->left, listB);
	// joinNode(listB->left, listA);
	return listA;
}

void joinNode(Node *a, Node *b) {
	a->right = b;
	b->left = a;
}

void printCircularList(Node *head) {
	if (head == NULL)
		return;
	Node *start = head;
	while (true) {
		cout<<head->data<<" ";
		head = head->right;
		if (head == start)
			return;
	}
}

void inorder(Node *root) {
	if (root == NULL)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

Node* treeInsert(Node* root, int data) {
	if (root == NULL)
		return new Node(data);
	else {
		if (data <= root->data)
			root->left = treeInsert(root->left, data);
		else 
			root->right = treeInsert(root->right, data);
	}
	return root;
}

int main() {
	Node *root = NULL;
	root = treeInsert(root, 4);
	treeInsert(root, 2);
	treeInsert(root, 1);
	treeInsert(root, 3);
	treeInsert(root, 5);

	Node *head = treeToList(root);
	printCircularList(head);
	cout<<endl;
	return 0;
}