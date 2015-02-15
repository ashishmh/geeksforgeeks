// Print Nth node from the end of a Linked List without using the size attribute of the list

// http://www.geeksforgeeks.org/nth-node-from-the-end-of-a-linked-list/

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
void getNthFromLast(Node* start, int index);
void getNthFromLastRecursive(Node* start, int index);
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

void getNthFromLast(Node* start, int index) {
	if (!start) {
		cout<<"List empty.. ";
		return;
	}
	Node* main = start;
	Node* ref = start;
	for (int i=0; i<index; i++)
		ref = ref->next;
	while (ref) {
		ref = ref->next;
		main = main->next;
	}
	cout<<endl<<"Nth element from last is: "<<main->data;
	return;
}

void getNthFromLastRecursive(Node* start, int index) {
    static int i = 0;
    if (!start)
       return;
    getNthFromLastRecursive(start->next, index);
    if (++i == index) {
		cout<<endl<<"(Recursive fn) Nth element from last is: "<<start->data;
		return;
    }
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
	getNthFromLast(L->start, index);
	getNthFromLastRecursive(L->start, index);
	cout<<endl;
	return 0;
}