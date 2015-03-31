// http://www.geeksforgeeks.org/detect-and-remove-loop-in-a-linked-list/

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

bool detectAndRemoveLoop(node *head);
void removeLoop(node* head, node* ptr);
node* addnode(node *head, int data);
void printList(node *head);

bool detectAndRemoveLoop(node *head) {
    if (head == NULL || head->next == NULL)
        return false;

    node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        // if slow and fast meet, loop exists.
        if (fast == slow) {
            removeLoop(head, slow);
            return true;
        }
    }
    return false;
}

void removeLoop(node* head, node* slow) {
    // calculating no of nodes (k) in loop
    node *ptr = slow;
    int k = 1;
    while (ptr->next != slow) {
        ptr = ptr->next;
        k++;
    }
    // resetting slow to head and ptr to kth position
    slow = head;
    ptr = head;
    for (int i = 0; i < k; i++)
        ptr = ptr->next;
    // move slow and ptr together till they meet at loop's starting node
    // store last node in last and set last->next to NULL
    node *last;
    while (slow != ptr) {
        last = ptr;
        slow = slow->next;
        ptr = ptr->next;
    }
    // breaking loop
    last->next = NULL;
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
    head->next->next->next->next->next->next = head->next->next;       // linking 6 -> 3

    cout<<"cycle: ";
    detectAndRemoveLoop(head) ? cout<<"true" : cout<<"false";
    cout<<endl<<"list: ";
    printList(head);

    cout<<endl;    
    return 0;
}