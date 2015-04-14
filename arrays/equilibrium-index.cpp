// http://www.geeksforgeeks.org/equilibrium-index-of-an-array/

#include <iostream>
using namespace std;

void findEquilibrium1(int *arr, int n);                 // complexity O(n^2)
void findEquilibrium2(int *arr, int n);                 // complexity O(n)
void printArray(int *arr, int n);

void findEquilibrium1(int *arr, int n) {
    int left_sum;
    int right_sum;
    for (int i = 0; i < n; i++) {
        left_sum = 0;
        right_sum = 0;
        for (int j = 0; j < i; j++)
            left_sum += arr[j];
        for (int j = i+1; j < n; j++)
            right_sum += arr[j];
        if (left_sum == right_sum)
            cout<<i<<" ";
    }
}

void findEquilibrium2(int *arr, int n) {
    // calculate total sum in right_sum
    int right_sum = 0;
    for (int i = 0; i < n; i++)
        right_sum += arr[i];
    
    int left_sum = 0;
    for (int i = 0; i < n; i++) {
        // calculate right sum for index i
        right_sum = right_sum - arr[i];
        if (left_sum == right_sum)
            cout<<i<<" ";
        // update left_sum
        left_sum = left_sum + arr[i];
    }
}

void printArray(int *arr, int n) {
    if (n < 1 || arr == NULL)
        return;
    for (int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
}

int main() {
    int arr[] = {-7, 1, 5, 2, -4, -3, -1};
    int n = sizeof(arr)/sizeof(int);
    cout<<"array: ";
    printArray(arr, n);
    cout<<endl<<endl;

    cout<<"equilibrium index..";
    cout<<endl<<"O(n^2): ";
    findEquilibrium1(arr, n);
    cout<<endl<<"O(n):   ";
    findEquilibrium2(arr, n);

    cout<<endl<<endl;
    return 0;
}