// http://www.geeksforgeeks.org/search-an-element-in-a-sorted-and-pivoted-array/

#include <iostream>
using namespace std;

void binarySearchRotated(int *arr, int beg, int end, int x);
void printArray(int *arr, int size);

void binarySearchRotated(int *arr, int beg, int end, int x) {
    if (beg > end) {
        cout<<"element not found!";
        return;
    }

    int mid = (beg + end) / 2;
    if (x == arr[mid]) {
        cout<<"element found at pos: "<<mid+1;
        return;
    }
    // right half of rotated array is sorted
    else if (arr[mid] <= arr[end]) {
        if (x > arr[mid] && x <= arr[end])
            binarySearchRotated(arr, mid+1, end, x);
        else binarySearchRotated(arr, beg, mid-1, x);
    }
    // left half of rotated array is sorted
    else {
        if (x >= arr[beg] && x < arr[mid])
            binarySearchRotated(arr, beg, mid-1, x);
        else binarySearchRotated(arr, mid+1, end, x);
    }
}

void printArray(int *arr, int size) {
    if (size < 1 || arr == NULL)
        return;
    for (int i = 0; i < size; i++)
        cout<<arr[i]<<" ";
}

int main() {
    int arr[] = {6, 7, 1, 2, 3, 4, 5};
    cout<<"array: ";
    printArray(arr, 7);
    cout<<endl;
    cout<<"binary search: ";
    binarySearchRotated(arr, 0, 6, 7);

    cout<<endl<<endl;
    return 0;
}