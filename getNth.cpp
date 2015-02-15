// Write a GetNth() function that takes a linked list and an integer index and returns 
// the data value stored in the Node at that index position.

// http://www.geeksforgeeks.org/write-a-function-to-get-nth-node-in-a-linked-list/

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
int getNth(LinkedList* L, int index);
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

int getNth(LinkedList* L, int index) {
	if (index > L->size) {
		cout<<"Index should be less than size.. ";
		return -1;
	}
	Node* ptr = L->start;
	if (!ptr) {
		cout<<"List empty.."<<endl;
		return -1;
	}
	for (int i=1; i<index; i++)
		ptr = ptr->next;
	return ptr->data;
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
	cout<<endl<<"Value at Nth node: "<<getNth(L, index);
	cout<<endl;
	return 0;
}