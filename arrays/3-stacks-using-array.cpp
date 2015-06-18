#include <iostream>
#include <limits>
using namespace std;

class Stack {
public:
    int stackCount;
    int stackSize;
    int *buffer;
    int *stackPointer;
    Stack(int stackCount, int stackSize) {
        this->stackCount = stackCount;
        this->stackSize = stackSize;
        this->buffer = new int[stackCount * stackSize + 1];
        this->stackPointer = new int[stackCount];
    }
    // functions
    void push(int stackNum, int value);
    int pop(int stackNum);
    int peek(int stackNum);
    bool isEmpty(int stackNum);
};

void Stack::push(int stackNum, int value) {
    if (stackPointer[stackNum] >= stackSize) {
        cout<<endl<<"Stack overflow"<<endl;
        return;
    }
    int index = stackNum * stackSize + stackPointer[stackNum];
    buffer[++index] = value;
    stackPointer[stackNum]++;
}

int Stack::pop(int stackNum) {
    if (stackPointer[stackNum] < 1) {
        cout<<endl<<"Stack underflow"<<endl;
        return INT_MIN;
    }
    int index = stackNum * stackSize + stackPointer[stackNum];
    int value = buffer[index];
    buffer[index] = 0;
    stackPointer[stackNum]--;
    return value;
}

int Stack::peek(int stackNum) {
    int index = stackNum * stackSize + stackPointer[stackNum];
    return buffer[index];
}

bool Stack::isEmpty(int stackNum) {
    return (stackPointer[stackNum] == 0);
}

int main()
{
    Stack *s1 = new Stack(3, 5);
    s1->push(0, 99);
    s1->push(0, 100);
    s1->push(0, 101);
    s1->push(0, 102);
    s1->push(0, 103);
    s1->push(0, 104);

    cout<<"peek: "<<s1->peek(0)<<endl;    
    s1->pop(0);
    cout<<"peek after pop: "<<s1->peek(0)<<endl;
    cout<<endl<<"stack pointer: "<<s1->stackPointer[0]<<endl;
    cout<<"stack empty: ";
    s1->isEmpty(0) ? cout<<"true" : cout<<"false";

    s1->pop(0);
    s1->pop(0);
    s1->pop(0);
    s1->pop(0);
    s1->pop(0);

    cout<<endl<<"stack empty: ";
    s1->isEmpty(0) ? cout<<"true" : cout<<"false";

    cout<<endl;
    return 0;
}
