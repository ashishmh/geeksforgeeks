// http://www.geeksforgeeks.org/pairwise-swap-elements-of-a-given-linked-list-by-changing-links/
// this program swaps by reassigning the pointers of nodes

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

Node* pairSwapRecursion(Node *head);
Node* pairSwapIteration(Node *head);
Node* addNode(Node *head, int data);
void printList(Node *head);

Node* pairSwapRecursion(Node *head) {
	if (head == NULL || head->next == NULL)
		return head;
	
	Node *remain = head->next->next;
	Node *newhead = head->next;
	newhead->next = head;
	head->next = pairSwapRecursion(remain);
	return newhead;
}

Node* pairSwapIteration(Node *head) {
	Node *prev, *curr, *next;
	prev = head;
	curr = head->next;
	next = head->next->next;

	// change head before beginning
	head = head->next;
	
	while (next != NULL && next->next != NULL) {
		curr->next = prev;
		prev->next = next->next;
		prev = next;
		curr = prev->next;
		next = next->next->next;
	}
	curr->next = prev;
	prev->next = next;
	return head;
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
    head = pairSwapIteration(head);
    printList(head);
    cout<<endl<<"2nd swap (recursive): ";
    head = pairSwapRecursion(head);
    printList(head);
    cout<<endl;
    
    return 0;
}