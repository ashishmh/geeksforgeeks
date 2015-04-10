// http://www.geeksforgeeks.org/leaders-in-an-array/

#include <iostream>
using namespace std;

void printLeader1(int *arr, int n);                      // complexity O(n^2)
void printLeader2(int *arr, int n);                      // complexity O(nlogn)
void printArray(int *arr, int n);

void printLeader1(int *arr, int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = i+1; j < n; j++) {
            if (arr[i] <= arr[j])
                break;
        }
        if (j == n)
            cout<<arr[i]<<" ";
    }
}

void printLeader2(int *arr, int n) {
    int max_from_right = arr[n-1];
    cout<<max_from_right<<" ";
    for (int i = n-2; i >= 0; i--) {
        if (arr[i] > max_from_right) {
            cout<<arr[i]<<" ";
            max_from_right = arr[i];
        }
    }
}

void printArray(int *arr, int n) {
    if (n < 1 || arr == NULL)
        return;
    for (int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
}

int main() {
    int arr[] = {16, 17, 4, 3, 5, 2};
    int n = sizeof(arr)/sizeof(int);
    cout<<"array: ";
    printArray(arr, n);
    cout<<endl<<endl;

    cout<<"leader: O(n^2)   -> ";
    printLeader1(arr, n);

    cout<<endl<<"leader: O(nlogn) -> ";
    printLeader2(arr, n);

    cout<<endl<<endl;
    return 0;
}