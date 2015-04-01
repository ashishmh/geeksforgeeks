// http://www.geeksforgeeks.org/add-two-numbers-represented-by-linked-lists/

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

void addNumList(node *head1, node* head2);
node* reverseList(node* head);
node* addnode(node *head, int data);
void printList(node *head);

void addNumList(node *head1, node* head2) {
    if (head1 == NULL || head2 == NULL)
        return;
    node* num1 = reverseList(head1);
    node* num2 = reverseList(head2);
    node* result = NULL;
    int sum, rem = 0;
    while (num1 != NULL && num2 != NULL) {
        sum = num1->data + num2->data + rem;
        result = addnode(result, sum % 10);
        rem = sum / 10;
        num1 = num1->next;
        num2 = num2->next;
    }
    // if num1 finished first
    if (num1 == NULL && num2 != NULL) {
        while (num2 != NULL) {
            sum = num2->data + rem;
            result = addnode(result, sum % 10);
            rem = sum / 10; 
            num2 = num2->next;
        }
    }
    // if num2 finished first
    if (num2 == NULL && num1 != NULL) {
        while (num1 != NULL) {
            sum = num1->data + rem;
            result = addnode(result, sum % 10);
            rem = sum / 10; 
            num1 = num1->next;
        }
    }
    
    // last carry
    if (rem > 0)
        result = addnode(result, rem);
    
    // if both finished, reverse result
    result = reverseList(result);
    printList(result);
}

node* reverseList(node* head) {
    if (head == NULL || head->next == NULL)
        return head;
    node* new_head = reverseList(head->next);
    node* ptr = new_head;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = head;
    head->next = NULL;
    return new_head;
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
    // num 1 = 925
    node *head1 = NULL;
    head1 = addnode(head1, 6);
    head1 = addnode(head1, 4);
    head1 = addnode(head1, 9);
    head1 = addnode(head1, 5);
    head1 = addnode(head1, 7);
    
    // num 2 = 456
    node *head2 = NULL;
    head2 = addnode(head2, 4);
    head2 = addnode(head2, 8);

    cout<<"num1: ";
    printList(head1);
    cout<<endl<<"num2: ";
    printList(head2);

    cout<<endl<<"sum:  ";
    addNumList(head1, head2);

    cout<<endl;    
    return 0;
}