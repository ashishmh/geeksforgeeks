// http://www.geeksforgeeks.org/merge-a-linked-list-into-another-linked-list-at-alternate-positions/

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

void mergeAlternate(node *p, node **q);
node* addnode(node *head, int data);
void printList(node *head);

void mergeAlternate(node *p, node **q) {
    if (p == NULL || (*q) == NULL)
        return;

    node *p_curr = p, *p_next;
    node *q_curr = (*q), *q_next;
    while (p_curr != NULL && q_curr != NULL) {
        p_next = p_curr->next;
        q_next = q_curr->next;

        q_curr->next = p_next;
        p_curr->next = q_curr;

        p_curr = p_next;
        q_curr = q_next;
    }
    // updating head of q
    (*q) = q_curr;
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
    node *p = NULL;
    p = addnode(p, 1);
    p = addnode(p, 2);
    p = addnode(p, 3);

    node *q = NULL;
    q = addnode(q, 4);
    q = addnode(q, 5);
    q = addnode(q, 6);
    q = addnode(q, 7);
    q = addnode(q, 8);

    cout<<"list1: ";
    printList(p);
    cout<<endl<<"list2: ";
    printList(q);
    cout<<endl<<"after merge.. ";
    mergeAlternate(p, &q);
    cout<<endl<<"list1: ";
    printList(p);
    cout<<endl<<"list2: ";
    printList(q);
    
    cout<<endl<<endl;
    return 0;
}