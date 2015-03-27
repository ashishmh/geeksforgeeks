// http://www.geeksforgeeks.org/segregate-even-and-odd-elements-in-a-linked-list/

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

void separateEvenOdd(node *head);
node* addnode(node *head, int data);
void printList(node *head);

void separateEvenOdd(node *head) {
    if (head == NULL || head->next == NULL)
        return;

    // first even element becomes new head
    node *ptr = head;
    while (ptr->data % 2 != 0)
        ptr = ptr->next;
    node *new_head = ptr;

    // store end and aux end
    ptr = head;
    node *aux_end, *end;
    while (ptr->next != NULL)
        ptr = ptr->next;
    aux_end = end = ptr;
    ptr = head;

    // move all odd nodes at the end of list
    node *temp;
    while (ptr != aux_end) {      
        // if odd, delete node and add it to the end  
        if (ptr->data % 2 != 0) {
            temp->next = ptr->next;
            end->next = new node(ptr->data);
            end = end->next;
            ptr = temp->next;
        }
        // if even, increment both temp and ptr
        else {
            temp = ptr;
            ptr = ptr->next;
        }
    }
    // print result
    printList(new_head);
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
    head = addnode(head, 17);
    head = addnode(head, 15);
    head = addnode(head, 8);
    head = addnode(head, 12);
    head = addnode(head, 10);
    head = addnode(head, 5);
    head = addnode(head, 4);
    head = addnode(head, 1);
    head = addnode(head, 7);
    head = addnode(head, 6);

    cout<<"list: ";
    printList(head);
    cout<<endl<<"after separation: ";
    separateEvenOdd(head);

    cout<<endl;    
    return 0;
}