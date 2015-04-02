// http://www.geeksforgeeks.org/sort-a-linked-list-of-0s-1s-or-2s/

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

node* sortList(node *head);                 // time complexity O(n), space complexity O(1)
node* addnode(node *head, int data);
void printList(node *head);

node* sortList(node *head) {
    if (head == NULL)
        return head;

    int count[3] = {0};
    node *ptr;
    // count occurence of each element
    ptr = head;
    while (ptr != NULL) {
        count[ptr->data]++;
        ptr = ptr->next;
    }
    // traverse list and copy each element into list until its count is zero
    ptr = head;
    int i = 0;
    while(ptr != NULL) {
        if (count[i] == 0)
            i++;
        ptr->data = i;
        count[i]--;
        ptr = ptr->next;
    }
    return head;
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
    head = addnode(head, 0);
    head = addnode(head, 1);
    head = addnode(head, 0);
    head = addnode(head, 2);
    head = addnode(head, 1);
    head = addnode(head, 1);
    head = addnode(head, 2);
    head = addnode(head, 1);
    head = addnode(head, 2);

    cout<<"list: ";
    printList(head);
    cout<<endl<<"sort: ";
    head = sortList(head);
    printList(head);

    cout<<endl<<endl;
    return 0;
}