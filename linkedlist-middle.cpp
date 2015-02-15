// Write a C function to print the middle of a given linked list

// http://www.geeksforgeeks.org/write-a-c-function-to-print-the-middle-of-the-linked-list/

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
void printMiddle(LinkedList* L);
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

void printMiddle(LinkedList* L) {
	if (!L->start)
		return;
	Node* slow;
	Node* fast;
	slow = L->start;
	fast = L->start->next;
	while (fast && fast->next) {
		fast = fast->next->next;
		slow = slow->next;
	}
	cout<<endl<<"Middle of list: "<<slow->data;
	return;
}

void printLL(LinkedList* L) {
	Node* start = L->start;
	if (!start) {
		cout<<"List empty..";
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
	printMiddle(L);
	cout<<endl;
	return 0;
}