// http://www.geeksforgeeks.org/largest-sum-contiguous-subarray/

#include <iostream>
using namespace std;

void maxContiguousSum1(int *arr, int n);            // doesnt work for all -ve numbers
void maxContiguousSum2(int *arr, int n);            // works for all -ve numbers too
void printArray(int *arr, int n);

void maxContiguousSum1(int *arr, int n) {
    int start = 0, end;
    int max_here = 0;
    int max_so_far = 0;
    for (int i = 0; i < n; i++) {
        max_here = max_here + arr[i];
        if (max_here < 0) {
            max_here = 0;
            start = i+1;            
        }
        else if (max_here > max_so_far) {
            max_so_far = max_here;
            end = i;
        }
    }
    cout<<"max sum: "<<max_so_far<<" | start: "<<start<<" | end: "<<end;
}

void maxContiguousSum2(int *arr, int n) {
    int start = 0, end;
    int max_here = arr[0];
    int max_so_far = arr[0];
    for (int i = 1; i < n; i++) {
        if (max(arr[i], max_here + arr[i]) == arr[i])
            start = i;
        max_here = max(arr[i], max_here + arr[i]);
        if (max(max_here, max_so_far) == max_here)
            end = i;
        max_so_far = max(max_here, max_so_far);
    }
    if (start > end)
        start = end;
    cout<<"max sum: "<<max_so_far<<" | start: "<<start<<" | end: "<<end;
}

void printArray(int *arr, int n) {
    if (n < 1 || arr == NULL)
        return;
    for (int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
}

int main() {
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    // int arr[] = {-2, -3, -4, -1, -2, -1, -5, -3};

    int n = sizeof(arr)/sizeof(int);
    cout<<"array: ";
    printArray(arr, n);
    cout<<endl<<endl;

    maxContiguousSum1(arr, n);
    cout<<endl;
    maxContiguousSum2(arr, n);

    cout<<endl<<endl;
    return 0;
}