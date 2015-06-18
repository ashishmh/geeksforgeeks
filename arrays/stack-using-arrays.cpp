#include <iostream>
#include <limits>
using namespace std;

class node {
public:
    int value;
    int min_beneath;
    node *next;
    node(int value, int min_beneath) {
        this->value = value;
        this->min_beneath = min_beneath;
        this->next = NULL;
    }
};

node* push(node *top, int value) {
    if (top == NULL)
        return new node(value, value);
    int min = (top->min_beneath < value) ? top->min_beneath : value;
    node *ptr = new node(value, min);
    ptr->next = top;
    top = ptr;
    return top;
}

node* pop(node *top) {
    if (top == NULL) {
        cout<<"Stack underflow.."<<endl;
        return NULL;
    }
    top = top->next;
    return top;
}

int peek(node *top) {
    if (top == NULL) {
        cout<<"Stack empty.."<<endl;
        return INT_MIN;
    }
    return top->value;
}

int minValue(node *top) {
    if (top == NULL) {
        cout<<"Stack empty.."<<endl;
        return INT_MIN;   
    }
    return top->min_beneath;
}

bool isEmpty(node *top) {
    if (top == NULL)
        return true;
    return false;
}

int main()
{
    // freopen("input.txt","r",stdin);
    node *top = push(top, 5);
    top = push(top, 6);
    top = push(top, 1);
    top = push(top, 8);

    int temp = peek(top);
    cout<<"peek: "<<temp<<endl;
    temp = minValue(top);
    cout<<"min value: "<<temp<<endl;  

    top = pop(top);    
    cout<<endl<<"top: "<<top->value<<endl;
    
    top = pop(top);
    cout<<endl<<"im here"<<endl;
    
    // top ? cout<<"not null" : cout<<"null";
    // cout<<endl<<top->value<<endl;

    // cout<<endl<<"im here"<<endl;
    // if (top == NULL)
        // cout<<"top is null"<<endl;
    // top = pop(top);
    // temp = peek(top);
    // cout<<endl<<"peek: "<<temp<<endl;

    // top = pop(top);

    // top = pop(top);
    // cout<<endl;
    // if (top)
        // cout<<"not null";
    // else cout<<"null";
    // top ? cout<<"not null" : cout<<"null";

    cout<<endl;
    return 0;
}