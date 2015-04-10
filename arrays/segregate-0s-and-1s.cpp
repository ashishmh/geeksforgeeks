// http://www.geeksforgeeks.org/segregate-0s-and-1s-in-an-array-by-traversing-array-once/

#include <iostream>
using namespace std;

void segregate0and1(int *arr, int n);
void printArray(int *arr, int n);

void segregate0and1(int *arr, int n) {
    int left = 0;
    int right = n-1;
    while (left < right) {
        while (left < right && arr[left] == 0)
            left++;
        while (left < right && arr[right] == 1)
            right--;
        // if upper loops break on arr[left] == 0 or arr[right] == 1, swap left and right
        if (left < right) {
            arr[left] = 0;
            arr[right] = 1;
        }
        left++;
        right--;
    }
}

void printArray(int *arr, int n) {
    if (n < 1 || arr == NULL)
        return;
    for (int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
}

int main() {
    int arr[] = {1, 0, 1, 0, 1, 1, 1, 0};
    int n = sizeof(arr)/sizeof(int);
    cout<<"array: ";
    printArray(arr, n);
    cout<<endl<<endl;

    cout<<"segregate 0s and 1s: ";
    segregate0and1(arr, n);
    printArray(arr, n);

    cout<<endl<<endl;
    return 0;
}