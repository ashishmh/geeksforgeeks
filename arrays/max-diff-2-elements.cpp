// http://www.geeksforgeeks.org/maximum-difference-between-two-elements/

#include <iostream>
using namespace std;

int maxDiff1(int *arr, int n);                  // complexity O(n^2)
int maxDiff2(int *arr, int n);                  // complexity O(n)
void printArray(int *arr, int n);

int maxDiff1(int *arr, int n) {
    int max_diff = 0;
    for (int i = 0; i < n-1; i++)
        for (int j = i+1; j < n; j++)
            if (arr[j] - arr[i] > max_diff)
                max_diff = arr[j] - arr[i];
    return max_diff;
}

int maxDiff2(int *arr, int n) {
    int min_ele = arr[0];
    int max_diff = arr[1] - arr[0];
    for (int i = 0; i < n; i++) {
        if (arr[i] - min_ele > max_diff)
            max_diff = arr[i] - min_ele;
        if (arr[i] < min_ele)
            min_ele = arr[i];
    }
    return max_diff;
}

void printArray(int *arr, int n) {
    if (n < 1 || arr == NULL)
        return;
    for (int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
}

int main() {
    int arr[] = {80, 2, 6, 3, 100};
    int n = sizeof(arr)/sizeof(int);
    cout<<"array: ";
    printArray(arr, n);
    cout<<endl<<endl;

    cout<<"max diff -> O(n^2): ";
    cout<<maxDiff1(arr, n);
    cout<<endl<<"max diff -> O(n):   ";
    cout<<maxDiff2(arr, n);

    cout<<endl<<endl;
    return 0;
}