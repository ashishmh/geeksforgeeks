// http://www.geeksforgeeks.org/union-and-intersection-of-two-linked-lists/
// code for method 1 of gfg

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
node* listIntersection(node *head1, node *head2);           // complexity (mn)
bool findInList(node *head, node* ele);
node* addnode(node *head, int data);
void printList(node *head);

node* listUnion(node *head1, node *head2) {
    if (head1 == NULL || head2 == NULL)
        return NULL;
    node *result = NULL;
    node *ptr;
    
    // scan list 1 and if node is not in result, add it
    ptr = head1;
    while (ptr != NULL) {
        if (!findInList(result, ptr))
            result = addnode(result, ptr->data);
        ptr = ptr->next;
    }

    // scan list 2 and if node is not in result, add it
    ptr = head2;
    while (ptr != NULL) {
        if (!findInList(result, ptr))
            result = addnode(result, ptr->data);
        ptr = ptr->next;
    }
    return result;
}

node* listIntersection(node *head1, node *head2) {
    if (head1 == NULL || head2 == NULL)
        return NULL;
    node *result = NULL;
    node *ptr1 = head1;
    node *ptr2;

    while (ptr1 != NULL) {
        ptr2 = head2;
        while (ptr2 != NULL) {
            // if node is in both lists and not already in result, add it
            if (ptr1->data == ptr2->data && !findInList(result, ptr1))

                result = addnode(result, ptr1->data);
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    return result;
}

bool findInList(node *head, node* ele) {
    if (head == NULL || ele == NULL)
        return false;
    node *ptr = head;
    while (ptr != NULL) {
        if (ptr->data == ele->data)
            return true;
        ptr = ptr->next;
    }
    return false;
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