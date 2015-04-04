// http://www.geeksforgeeks.org/design-a-stack-with-find-middle-operation/
// stack using doubly linked list

#include <iostream>
#include <limits>
#define INF INT_MIN
using namespace std;

class node {
public:
    int data;
    node *left, *right;
    node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class Stack {
public:
	node *top;
	node *mid;
	int count;

	void push(Stack *stack, int data);
	int pop(Stack *stack);
	int findMiddle(Stack *stack);
	void deleteMiddle(Stack *stack);

	Stack() {
		this->top = NULL;
		this->mid = NULL;
		this->count = 0;
	}
};

void Stack::push(Stack *stack, int data) {
	node *new_node = new node(data);
	if (stack->count == 0) {
		top = new_node;
		stack->mid = top;
		++(stack->count);
		return;
	}
	new_node->right = top;
	top->left = new_node;
	top = new_node;
	++(stack->count);
	
	// if count goes from odd to even, mid shifts up
	if (stack->count % 2 == 0)
		stack->mid = stack->mid->left;
}

int Stack::pop(Stack *stack) {
	if (stack->count == 0) {
		cout<<endl<<"stack empty..";
		return INF;
	}
	int temp = stack->top->data;
	stack->top = stack->top->right;
	if (stack->top != NULL)
		stack->top->left = NULL;	
	--(stack->count);

	// if count goes from even to odd, mid shifts down
	if (stack->count % 2 != 0)
		stack->mid = stack->mid->right;
	return temp;
}

int Stack::findMiddle(Stack *stack) {
	if (stack->mid != NULL && stack->count != 0)
		return stack->mid->data;
	else return INF;
}

void Stack::deleteMiddle(Stack *stack) {
	if (stack->count == 0) {
		cout<<"stack empty..";
		return;
	}
	if (stack->mid == stack->top) {
		--(stack->count);
		stack->top = NULL;
		stack->mid = NULL;
		return;
	}
	stack->mid->left->right = stack->mid->right;
	stack->mid->right->left = stack->mid->left;
	--(stack->count);
	
	// if count goes from even to odd, mid shifts down
	if (stack->count % 2 != 0)
		stack->mid = stack->mid->right;
	// if count goes from odd to even, mid shifts up
	if (stack->count % 2 == 0)
		stack->mid = stack->mid->left;
}

void printStack(Stack *stack) {
	if (stack->count == 0) {
		cout<<"stack empty..";
		return;
	}
	node *ptr = stack->top;
	while (ptr != NULL) {
		cout<<ptr->data<<" ";		
		ptr = ptr->right;		
	}
}

int main() {
    Stack *stack = new Stack();

    stack->push(stack, 4);
    stack->push(stack, 10);    
    stack->push(stack, 1);
    stack->push(stack, 11);
    stack->push(stack, 12);
    stack->push(stack, 99);
    stack->push(stack, 100);

    cout<<"stack: ";
    printStack(stack);

    cout<<endl<<"after 2 pops: ";
    stack->pop(stack);    
    stack->pop(stack);

    printStack(stack);

    cout<<endl<<"middle of stack: ";
    (stack->findMiddle(stack) == INF) ? cout<<"empty" : cout<<stack->findMiddle(stack);
    cout<<endl<<"delete middle: ";
    stack->deleteMiddle(stack);
    printStack(stack);
    cout<<endl<<"new middle: ";
    (stack->findMiddle(stack) == INF) ? cout<<"empty" : cout<<stack->findMiddle(stack);

    cout<<endl<<endl;
    return 0;
}