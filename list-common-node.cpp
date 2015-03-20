// http://www.geeksforgeeks.org/write-a-function-to-get-the-intersection-point-of-two-linked-lists/

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void getIntersection(Node *head1, Node *head2);
void printList(Node *head);

void getIntersection(Node *head1, Node *head2) {
    if (head1 == NULL || head2 == NULL)
        return;
    bool visited[100] = {false};
    // mark nodes in list 1 as visited
    while (head1 != NULL) {
        visited[head1->data] = true;
        head1 = head1->next;
    }
    // traverse list 2 and return if any node is already visited
    while (head2 != NULL) {
        if (visited[head2->data]) {
            cout<<head2->data;
            return;
        }
        head2 = head2->next;
    }
    cout<<"none";
}

void printList(Node *head) {
    if (head == NULL)
        return;
    while (head != NULL) {
        cout<<head->data<<" ";
        head = head->next;
    }
}

int main()
{
    Node *head1 = new Node(3);
    head1->next = new Node(6);
    head1->next->next = new Node(9);
    head1->next->next->next = new Node(15);
    head1->next->next->next->next = new Node(30);
    
    Node *head2 = new Node(10);
    head2->next = head1->next->next->next;
    head2->next->next = head1->next->next->next->next;
    cout<<"list 1: ";
    printList(head1);
    cout<<endl<<"list 2: ";
    printList(head2);
    cout<<endl<<"common node: ";
    getIntersection(head1, head2);
    cout<<endl;
    
    return 0;
}