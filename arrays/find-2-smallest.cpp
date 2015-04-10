// http://www.geeksforgeeks.org/to-find-smallest-and-second-smallest-element-in-an-array/

#include <iostream>
using namespace std;

void printArray(int *arr, int n);

void findTwoSmallest(int *arr, int n) {
    if (n < 2)
        return;
    
    int small, second_small;
    small = (arr[0] < arr[1]) ? arr[0] : arr[1];
    second_small = (arr[0] < arr[1]) ? arr[1] : arr[0];

    for (int i = 2; i < n; i++) {
        if (arr[i] < small) {
            second_small = small;
            small = arr[i];
        }
        else if (arr[i] > small && arr[i] < second_small)
            second_small = arr[i];
    }
    cout<<"smallest: "<<small<<" second smallest: "<<second_small;
}

void printArray(int *arr, int n) {
    if (n < 1 || arr == NULL)
        return;
    for (int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
}

int main() {
    int arr[] = {12, 13, 1, 10, 34, 1};
    int n = sizeof(arr)/sizeof(int);
    cout<<"array: ";
    printArray(arr, n);
    cout<<endl<<endl;

    findTwoSmallest(arr, n);

    cout<<endl<<endl;
    return 0;
}