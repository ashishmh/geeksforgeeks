// http://www.geeksforgeeks.org/write-a-program-to-reverse-an-array/

#include <iostream>
using namespace std;

void reverseArrayIterative(int *arr, int size);
void swapElement(int *arr, int a, int b);
void printArray(int *arr, int size);

void reverseArrayIterative(int *arr, int size) {
    int beg = 0, end = size-1;
    while (beg < end) {
        swapElement(arr, beg, end);
        beg++;
        end--;
    }
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
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(int);
    cout<<"array: ";
    printArray(arr, n);
    cout<<endl;
    cout<<"reverse: ";
    reverseArrayIterative(arr, n);
    printArray(arr, n);
    cout<<endl<<"reverse again: ";
    reverseArrayRecursive(arr, 0, n-1);
    printArray(arr, n);

    cout<<endl<<endl;
    return 0;
}