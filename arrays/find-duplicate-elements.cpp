// http://www.geeksforgeeks.org/find-duplicates-in-on-time-and-constant-extra-space/

#include <iostream>
using namespace std;

void findRepeatElements(int *arr, int n);
void printArray(int *arr, int n);

void findRepeatElements(int *arr, int n) {
    for (int i = 0; i < n; i++)
        arr[arr[i] % n] += n;
    for (int i = 0; i < n ; i++)
        if (arr[i]/n > 1)
            cout<<i<<" ";
}

void printArray(int *arr, int n) {
    if (n < 1 || arr == NULL)
        return;
    for (int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
}

int main() {
    int arr[] = {1, 6, 2, 0, 1, 0, 6, 6};
    int n = sizeof(arr)/sizeof(int);
    cout<<"array: ";
    printArray(arr, n);
    cout<<endl<<endl;

    cout<<"repeat elements: ";
    findRepeatElements(arr, n);

    cout<<endl<<endl;
    return 0;
}