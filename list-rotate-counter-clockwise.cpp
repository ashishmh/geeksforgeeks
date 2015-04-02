// http://www.geeksforgeeks.org/rotate-a-linked-list/

#include <iostream>
using namespace std;

class node {
public:
    int data;
    node *next;
    node(int data) {
        this->data = data;
        this->next = NULL;  
    }
};

node* rotateList(node *head, int k);
int countList(node *head);
node* addnode(node *head, int data);
void printList(node *head);

node* rotateList(node *head, int k) {
	if (head == NULL || head->next == NULL)
		return head;

	node *temp, *end;
	int n = countList(head);
	// to rotate k times counter clockwise, rotate n-k times clockwise, where n is length of list
	for (int i = 0; i < n-k; i++) {
		end = head;
		while (end->next != NULL) {
			temp = end;
			end = end->next;
		}
		end->next = head;
		temp->next = NULL;
		head = end;
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

node* addnode(node *head, int data) {
    if (head == NULL)
        return new node(data);
    node *ptr = head;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = new node(data);
    return head;
}

void printList(node *head) {
    if (head == NULL)
        return;
    while (head != NULL) {
        cout<<head->data<<" ";
        head = head->next;
    }
}

int main() {
    node *head = NULL;
    head = addnode(head, 10);
    head = addnode(head, 20);
    head = addnode(head, 30);
    head = addnode(head, 40);
    head = addnode(head, 50);
    head = addnode(head, 60);

    cout<<"list: ";
    printList(head);
    cout<<endl<<"rotate counter clockwise by 4: "<<endl;
    head = rotateList(head, 4);
    printList(head);
    
    cout<<endl;
    return 0;
}