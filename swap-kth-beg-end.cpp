// http://www.geeksforgeeks.org/swap-kth-node-from-beginning-with-kth-node-from-end-in-a-linked-list/

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

void swapKth(node* head, int k);
int countList(node *head);
node* addnode(node *head, int data);
void printList(node *head);

void swapKth(node* head, int k) {
    if (head == NULL || head->next == NULL)
        return;
    int n = countList(head);
    // k is not appropriate
    if (k > n || k < 0) {
        cout<<endl<<"k is invalid..";
        return;
    }
    // kth node from first = kth node from last
    if (k == n-k+1) {
        cout<<endl<<"kth node from first = kth node from last..";
        return;
    }
    // if k = 1, make k = n
    if (k == 1)
        k = n;

    // move x, p_x and y, p_y, n_y to correct positions
    node *x = head, *p_x;
    for (int i = 0; i < k-1; i++) {
        p_x = x;
        x = x->next;
    }
    node *y = head, *p_y, *n_y = NULL;
    for (int i = 0; i < n-k; i++) {
        p_y = y;
        y = y->next;
    }
    if (y->next != NULL)
        n_y = y->next;

    // begin changing pointers

    // if x is next to y
    if (x == y->next) {
        node *temp = x;
        x = y;
        y = temp;

        temp = p_x;
        p_x = p_y;
        p_y = temp;

        n_y = y->next;
    }

    p_x->next = y;
    if (y == x->next) {
        y->next = x;
    }
    else {
        y->next = x->next;
        p_y->next = x;
    }
    if (n_y != NULL)
        x->next = n_y;
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
    head = addnode(head, 1);
    head = addnode(head, 2);
    head = addnode(head, 3);
    head = addnode(head, 4);
    head = addnode(head, 5);
    head = addnode(head, 6);
    head = addnode(head, 7);
    head = addnode(head, 8);

    cout<<"list: ";
    printList(head);
    cout<<endl<<"kth swap: ";
    swapKth(head, 2);
    printList(head);
    
    cout<<endl<<endl;
    return 0;
}