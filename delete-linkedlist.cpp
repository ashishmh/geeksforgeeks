// Write a function to delete a Linked List

// http://www.geeksforgeeks.org/write-a-function-to-delete-a-linked-list/

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
void deleteList(LinkedList* L);
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

void deleteList(LinkedList* L) {
	if (!L || !L->start) {
		cout<<endl<<"List is already empty.."<<endl;
		return;
	}
	Node* start = L->start;
	Node* curr = start->next;
	Node* prev = start;
	while (curr) {
		delete(prev);
		prev = curr;
		curr = curr->next;
	}
	L->start = NULL;
	L->size = 0;					// setting new size of linked list to zero
	return;
}

void printLL(LinkedList* L) {
	if (!L || !L->start) {
		cout<<endl<<"List empty.."<<endl;
		return;
	}
	Node* start = L->start;
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
	deleteList(L);	
	printLL(L);
	cout<<endl;
	return 0;
}