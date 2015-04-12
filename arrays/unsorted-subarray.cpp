// http://www.geeksforgeeks.org/minimum-length-unsorted-subarray-sorting-which-makes-the-complete-array-sorted/

#include <iostream>
using namespace std;

void findUnsortedSubarray(int *arr, int n);
void printArray(int *arr, int n);

void findUnsortedSubarray(int *arr, int n) {
    int s, e, max, min;
    for (s = 0; s < n-1; s++)
        if (arr[s] > arr[s+1])
            break;
    for (e = n-1; e > 0; e--)
        if (arr[e-1] > arr[e])
            break;
    max = s, min = s;
    for (int i = s; i <= e; i++) {
        if (arr[i] > arr[max])
            max = i;
        if (arr[i] < arr[min])
            min = i;
    }
    for (int i = 0; i < s; i++)
        if (arr[i] > arr[min])
            s = i;
    for (int i = n-1; i > e; i--)
        if (arr[i] < arr[max])
            e = i;
    cout<<"unsorted subarray.."<<endl;
    cout<<"start index: "<<s<<" | end index: "<<e;
}

void printArray(int *arr, int n) {
    if (n < 1 || arr == NULL)
        return;
    for (int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
}

int main() {
    int arr[] = {0, 1, 15, 25, 6, 7, 30, 40, 50};
    int n = sizeof(arr)/sizeof(int);
    cout<<"array: ";
    printArray(arr, n);
    cout<<endl<<endl;

    findUnsortedSubarray(arr, n);

    cout<<endl<<endl;
    return 0;
}