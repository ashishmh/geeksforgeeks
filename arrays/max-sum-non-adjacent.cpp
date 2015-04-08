// http://www.geeksforgeeks.org/maximum-sum-such-that-no-two-elements-are-adjacent/

#include <iostream>
using namespace std;

void printArray(int *arr, int size);

int findMaxSum(int *arr, int n) {
    int incl = arr[0];
    int excl = 0;
    for (int i = 1; i < n; i++) {
        int temp = max(incl, excl);
        incl = excl + arr[i];
        excl = temp;
    }
    return max(incl, excl);
}

void printArray(int *arr, int size) {
    if (size < 1 || arr == NULL)
        return;
    for (int i = 0; i < size; i++)
        cout<<arr[i]<<" ";
}

int main() {
    int arr[] = {5, -5, 10, 40, 50, -35};
    int n = sizeof(arr)/sizeof(int);
    cout<<"array: ";
    printArray(arr, n);
    cout<<endl;

    cout<<"max sum: "<<findMaxSum(arr, n);

    cout<<endl<<endl;
    return 0;
}