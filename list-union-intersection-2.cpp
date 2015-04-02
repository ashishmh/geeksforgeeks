// http://www.geeksforgeeks.org/union-and-intersection-of-two-linked-lists/
// code for method 3 (hash table) of gfg

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

node* listUnion(node *head1, node *head2);                  // complexity (m+n)
node* listIntersection(node *head1, node *head2);           // complexity (m+n)
node* addnode(node *head, int data);
void printList(node *head);

node* listUnion(node *head1, node *head2) {
    if (head1 == NULL || head2 == NULL)
        return NULL;
    int arr[1000] = {0};                                    // array hash table upto 1000
    node *result = NULL, *ptr;
    
    // scan list 1, if node is not in hash table, add it to hash table and result list
    ptr = head1;
    while (ptr != NULL) {
        if (arr[ptr->data] == 0) {
            result = addnode(result, ptr->data);
            arr[ptr->data] = 1;            
        }
        ptr = ptr->next;
    }

    // scan list 2, if node is not in hash table, add it to hash table and result list
    ptr = head2;
    while (ptr != NULL) {
        if (arr[ptr->data] == 0) {
            result = addnode(result, ptr->data);
            arr[ptr->data] = 1;            
        }
        ptr = ptr->next;
    }
    return result;
}

node* listIntersection(node *head1, node *head2) {
    if (head1 == NULL || head2 == NULL)
        return NULL;
    int arr[1000] = {0};                                    // array hash table upto 1000
    node *result = NULL, *ptr;

    // add unique nodes of list 1 into hash table
    ptr = head1;
    while (ptr != NULL) {
        if (arr[ptr->data] == 0)
            arr[ptr->data] = 1;            
        ptr = ptr->next;
    }

    // scan list 2, if node is already in hash table, add it to result list
    ptr = head2;
    while (ptr != NULL) {
        if (arr[ptr->data] == 1) {
            result = addnode(result, ptr->data);
            arr[ptr->data] = 0;            
        }
        ptr = ptr->next;
    }
    return result;
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
    node *head1 = NULL;
    head1 = addnode(head1, 10);
    head1 = addnode(head1, 15);
    head1 = addnode(head1, 4);
    head1 = addnode(head1, 20);
    head1 = addnode(head1, 10);
    
    node *head2 = NULL;
    head2 = addnode(head2, 8);
    head2 = addnode(head2, 4);
    head2 = addnode(head2, 2);
    head2 = addnode(head2, 10);
    head2 = addnode(head2, 4);

    cout<<"list1: ";
    printList(head1);
    cout<<endl<<"list2: ";
    printList(head2);

    cout<<endl<<endl<<"union: ";
    node *unionList = listUnion(head1, head2);
    printList(unionList);

    cout<<endl<<"intersection: ";
    node *intersectionList = listIntersection(head1, head2);
    printList(intersectionList);

    cout<<endl<<endl;
    return 0;
}