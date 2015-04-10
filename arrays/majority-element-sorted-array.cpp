// http://www.geeksforgeeks.org/to-find-smallest-and-second-smallest-element-in-an-array/

#include <iostream>
using namespace std;

bool isMajority(int *arr, int n, int x);                // complexity O(logn)
int binarySearch(int *arr, int n, int x);               // returns first occurence of x
void printArray(int *arr, int n);

bool isMajority(int *arr, int n, int x) {
    // if x is not middle element, it can never be majority element
    int mid = n/2;
    if (x != arr[mid])
        return false;

    // find first index of x, and then check for x at (i + n/2)
    int i = binarySearch(arr, n , x);
    if ((i + n/2) < n && x == arr[i + n/2])
        return true;
    return false;
}

int binarySearch(int *arr, int n, int x) {
    int beg = 0;
    int end = n-1;
    while (beg <= end) {
        int mid = (beg+end)/2;
        if ( (mid == 0 || x > arr[mid-1]) && x == arr[mid] )
            return mid;
        else if (x > arr[mid])
            beg = mid+1;
        else end = mid-1;
    }
    return -1;
}

void printArray(int *arr, int n) {
    if (n < 1 || arr == NULL)
        return;
    for (int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
}

int main() {
    int arr[] = {1, 2, 3, 3, 3, 3, 10};
    int n = sizeof(arr)/sizeof(int);
    cout<<"array: ";
    printArray(arr, n);
    cout<<endl<<endl;

    cout<<"is 3 majority: ";
    isMajority(arr, n, 3) ? cout<<"yes" : cout<<"no";
    cout<<endl<<"is 2 majority: ";
    isMajority(arr, n, 2) ? cout<<"yes" : cout<<"no";

    cout<<endl<<endl;
    return 0;
}