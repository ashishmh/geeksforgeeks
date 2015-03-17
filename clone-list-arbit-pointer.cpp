// http://www.geeksforgeeks.org/a-linked-list-with-next-and-arbit-pointer/

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *arbit, *next;
    Node(int data) {
        this->data = data;
        arbit = next = NULL;
    }
};

Node* copyList(Node *orig);
Node* createList(int n);
void printList(Node *head);
void printArbitList(Node *head);

Node* copyList(Node *orig) {
    // create the copy of node 1 and insert it b/w node 1 & node 2 in original list and
    // repeat this for all the nodes in the original list
    Node *prev, *curr, *next;
    prev = orig;
    next = orig->next;
    int i = 1;
    while (next != NULL) {
        curr = new Node(i++);
        curr->next = next;
        prev->next = curr;
        prev = next;
        next = next->next;
    }
    prev->next = new Node(i);
    
    // copy the arbit linking of original list
    Node *temp_orig = orig;
    while (temp_orig != NULL) {
        temp_orig->next->arbit = temp_orig->arbit->next;
        temp_orig = temp_orig->next->next;
    }

    // separate the original and copy list
    Node* copy = orig->next;
    Node *temp_copy = copy;
    temp_orig = orig;
    while (temp_copy->next != NULL) {
        temp_orig->next = temp_orig->next->next;
        temp_orig = temp_orig->next;

        temp_copy->next = temp_copy->next->next;
        temp_copy = temp_copy->next;
    }
    temp_orig->next = NULL;

    // return the head pointer to copied list
    return copy;
}

Node* createList(int n) {
    Node *head = new Node(1);
    Node *ptr, *ptr1;
    ptr = ptr1 = head;
    for (int i = 2; i <= n; i++) {
        ptr1 = new Node(i);
        ptr->next = ptr1;
        ptr = ptr1;
    }
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

void printArbitList(Node *head) {
    if (head == NULL)
        return;
    while (head != NULL) {
        cout<<head->data<<"->"<<head->arbit->data<<" . ";
        head = head->next;
    }   
}

int main()
{
    Node *head = createList(5);
    // create arbit linking of original list
    Node *ptr = head;
    ptr->arbit = ptr->next->next;                               // 1 -> 3
    ptr->next->arbit = ptr;                                     // 2 -> 1
    ptr->next->next->arbit = ptr->next->next->next->next;       // 3 -> 5
    ptr->next->next->next->arbit = ptr->next;                   // 4 -> 2
    ptr->next->next->next->next->arbit = ptr;                   // 5 -> 1
    
    cout<<"original: ";
    printList(head);
    cout<<endl<<"arbit linking: ";
    printArbitList(head);

    Node *copy = copyList(head);
    cout<<endl<<endl<<"copy: ";
    printList(copy);
    cout<<endl<<"arbit linking: ";
    printArbitList(copy);
    cout<<endl;
    return 0;
}