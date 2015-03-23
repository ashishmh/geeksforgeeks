// http://www.geeksforgeeks.org/pairwise-swap-elements-of-a-given-linked-list/
// this program swaps the data of two nodes

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void pairSwapRecursion(Node *head);
void pairSwapIteration(Node *head);
void swap(Node *a, Node *b);
Node* addNode(Node *head, int data);
void printList(Node *head);

void pairSwapRecursion(Node *head) {
	// there must be atleast two nodes in the list
	if (head == NULL || head->next == NULL)
		return;
	swap(head, head->next);
	pairSwapRecursion(head->next->next);
}

void pairSwapIteration(Node *head) {
	// swap data of nodes till there are two nodes in the list
	while (head != NULL && head->next != NULL) {
		swap(head, head->next);
		head = head->next->next;
	}
}

void swap(Node *a, Node *b) {
	int temp = a->data;
	a->data = b->data;
	b->data = temp;
}

Node* addNode(Node *head, int data) {
    if (head == NULL)
        return new Node(data);
    Node *ptr = head;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = new Node(data);
    return head;
}

void printList(Node *head) {
    if (head == NULL)
        return;
    while (head != NULL) {
        cout<<head->data<<" ";
        head = head->next;
    }
}

int main() {
    Node *head = NULL;
    head = addNode(head, 1);
    head = addNode(head, 2);
    head = addNode(head, 3);
    head = addNode(head, 4);
    head = addNode(head, 5);
    head = addNode(head, 6);
    head = addNode(head, 7);

    cout<<"original: ";
    printList(head);
    cout<<endl<<"1st swap (iterative): ";
    pairSwapIteration(head);
    printList(head);
    cout<<endl<<"2nd swap (recursive): ";
    pairSwapRecursion(head);
    printList(head);
    cout<<endl;
    
    return 0;
}