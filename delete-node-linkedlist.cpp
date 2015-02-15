// Given only a pointer to a node to be deleted in a singly linked list, how do you delete it?

// http://www.geeksforgeeks.org/given-only-a-pointer-to-a-node-to-be-deleted-in-a-singly-linked-list-how-do-you-delete-it/

#include <iostream>
#include <cstdio>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node(int data) {
		this->data = data;
		next = NULL;
	}
};

class LinkedList {
public:
	Node* start;
	int size;
	LinkedList(Node* start, int size) {
		this->start = start;
		this->size = size;
	}
};

Node* createLinkedList(int size);
void deleteNode(Node* ptr);
void printLL(LinkedList* L);

Node* createLinkedList(int size) {
	if (size < 1)
		return NULL;
	Node* start = new Node(1);
	Node* ptr = start;
	Node* ptr1;
	for (int i=2; i<=size; i++) {
		ptr1 = new Node(i);
		ptr->next = ptr1;
		ptr = ptr->next;
	}
	return start;
}

void deleteNode(Node* ptr) {
	if (!ptr)
		return;
	Node* ptr1 = ptr->next;
	ptr->data = ptr1->data;
	ptr->next = ptr1->next;
	delete(ptr1);
	return;
}

void printLL(LinkedList* L) {
	Node* start = L->start;
	if (!start) {
		cout<<"List empty.."<<endl;
		return;
	}
	while (start) {
		cout<<start->data<<" ";
		start = start->next;
	}
	return;
}

int main() {
	freopen("input.txt","r",stdin);
	
	int size, index;
	cin>>size>>index;
	LinkedList* L = new LinkedList(createLinkedList(size), size);
	cout<<"List: ";
	printLL(L);
	deleteNode(L->start);
	cout<<endl<<"List after deleting node: ";
	printLL(L);
	cout<<endl;
	return 0;
}