// http://www.geeksforgeeks.org/program-for-array-rotation-continued-reversal-algorithm/

#include <iostream>
using namespace std;

void rotateLeftByReverse(int *arr, int n, int d);
void rotateRightByReverse(int *arr, int n, int d);
void reverseArrayRecursive(int *arr, int beg, int end);
void swapElement(int *arr, int a, int b);
void printArray(int *arr, int size);

void rotateLeftByReverse(int *arr, int n, int d) {
    if (d > n)
        d = d-n;
    reverseArrayRecursive(arr, 0, d-1);
    reverseArrayRecursive(arr, d, n-1);
    reverseArrayRecursive(arr, 0, n-1);
}

void rotateRightByReverse(int *arr, int n, int d) {
    if (d > n)
        d = d-n;
    reverseArrayRecursive(arr, n-d, n-1);
    reverseArrayRecursive(arr, 0, n-d-1);
    reverseArrayRecursive(arr, 0, n-1);
}

void reverseArrayRecursive(int *arr, int beg, int end) {
    if (beg > end)
        return;
    swapElement(arr, beg, end);
    reverseArrayRecursive(arr, ++beg, --end);
}

void swapElement(int *arr, int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void printArray(int *arr, int size) {
    if (size < 1 || arr == NULL)
        return;
    for (int i = 0; i < size; i++)
        cout<<arr[i]<<" ";
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr)/sizeof(int);
    cout<<"array: ";
    printArray(arr, n);
    cout<<endl;

    cout<<"rotate left by 3:  ";
    rotateLeftByReverse(arr, n, 3);
    printArray(arr, n);

    cout<<endl<<"rotate right by 4: ";
    rotateRightByReverse(arr, n, 4);
    printArray(arr, n);

    cout<<endl<<endl;
    return 0;
}