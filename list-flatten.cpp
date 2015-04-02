// http://www.geeksforgeeks.org/flattening-a-linked-list/
// iterative method

#include <iostream>
using namespace std;

class node {
public:
    int data;
    node *next, *down;
    node(int data) {
        this->data = data;
        this->next = NULL;  
        this->down = NULL;
    }
};

node* flattenList(node *head);
node* sortedMerge(node *a, node *b);
int countList(node *head);
node* addnodeDown(node *head, int data);
node* addnodeAcross(node *head, int data);
void printListAcross(node *head);
void printListDown(node *head);

node* flattenList(node *head) {
	if (head == NULL)
		return head;

	node *down, *across = head;
	int n = countList(head);
	for (int i = 0; i < n; i++) {
		down = across->down;
		head = sortedMerge(head, down);
		across = across->next;
	}
	return head;
}

node* sortedMerge(node *a, node *b) {
    if (a == NULL) return b;
    else if (b == NULL) return a;
    
    node *head = NULL;
    while (a != NULL && b != NULL) {
        if (a->data < b->data) {
            head = addnodeAcross(head, a->data);
            a = a->next;
        }
        else {
            head = addnodeAcross(head, b->data);
            b = b->down;
        }
    }
    if (a == NULL)
        while (b != NULL) {
            head = addnodeAcross(head, b->data);
            b = b->down;
        }
    if (b == NULL)
        while (a != NULL) {
            head = addnodeAcross(head, a->data);
            a = a->next;
        }
    return head;
}

int countList(node *head) {
    if (head == NULL)
        return 0;
    int count = 0;
    node *ptr = head;
    while (ptr != NULL) {
        count++;
        ptr = ptr->next;
    }
    return count;
}

node* addnodeDown(node *head, int data) {
    if (head == NULL)
        return new node(data);
    node *ptr = head;
    while (ptr->down != NULL)
        ptr = ptr->down;
    ptr->down = new node(data);
    return head;
}

node* addnodeAcross(node *head, int data) {
    if (head == NULL)
        return new node(data);
    node *ptr = head;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = new node(data);
    return head;
}

void printListAcross(node *head) {
    if (head == NULL)
        return;
    while (head != NULL) {
        cout<<head->data<<" ";
        head = head->next;
    }
}

void printListDown(node *head) {
    if (head == NULL)
        return;
    while (head != NULL) {
        cout<<head->data<<" ";
        head = head->down;
    }
}

int main() {
    node *head = NULL;
    head = addnodeDown(head, 5);
    head = addnodeDown(head, 7);
    head = addnodeDown(head, 8);
    head = addnodeDown(head, 30);

    head->next = addnodeDown(head->next, 10);
    head->next = addnodeDown(head->next, 20);

    head->next->next = addnodeDown(head->next->next, 19);
    head->next->next = addnodeDown(head->next->next, 22);
    head->next->next = addnodeDown(head->next->next, 50);

    head->next->next->next = addnodeDown(head->next->next->next, 28);
    head->next->next->next = addnodeDown(head->next->next->next, 35);
    head->next->next->next = addnodeDown(head->next->next->next, 40);
    head->next->next->next = addnodeDown(head->next->next->next, 45);

    cout<<"flattened: ";
    head = flattenList(head);
    printListAcross(head);
    
    cout<<endl<<endl;
    return 0;
}