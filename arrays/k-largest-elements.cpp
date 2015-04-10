// http://www.geeksforgeeks.org/k-largestor-smallest-elements-in-an-array/

#include <iostream>
using namespace std;

void printLargestK(int *arr, int n, int k);
void buildMaxHeap(int *arr, int n);
void heapifyMax(int *arr, int n, int i);
int heapExtractMax(int *arr, int n);
void swap(int* arr, int a, int b);
void printArray(int *arr, int n);

void printLargestK(int *arr, int n, int k) {
    buildMaxHeap(arr, n);
    cout<<"K largest are: ";
    for (int i = 0; i < k; i++)
        cout<<heapExtractMax(arr, n)<<" ";
}

void buildMaxHeap(int *arr, int n) {
    for (int i = n/2-1; i >= 0; i--)
        heapifyMax(arr, n, i);
}

void heapifyMax(int *arr, int n, int i) {
    int left = 2*i+1;
    int right = 2*i+2;
    int largest = i;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i) {
        swap(arr, i, largest);
        heapifyMax(arr, n, largest);
    }
}

int heapExtractMax(int *arr, int n) {
    int temp = arr[0];
    arr[0] = arr[n-1];
    n = n-1;
    heapifyMax(arr, n, 0);
    return temp;
}

void swap(int* arr, int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
    return;
}

void printArray(int *arr, int n) {
    if (n < 1 || arr == NULL)
        return;
    for (int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
}

int main() {
    int arr[] = {1, 23, 12, 9, 30, 2, 50};
    int n = sizeof(arr)/sizeof(int);
    cout<<"array: ";
    printArray(arr, n);
    cout<<endl<<endl;

    printLargestK(arr, n, 3);

    cout<<endl<<endl;
    return 0;
}