// http://www.geeksforgeeks.org/dynamic-programming-set-14-maximum-sum-increasing-subsequence/

#include <iostream>
using namespace std;

void lisSum(int *arr, int n);
int maxElement(int *arr, int n);
void printArray(int *arr, int size);

void lisSum(int *arr, int n) {
    if (n == 0)
        return;
    // lis_sum[i] stores longest increasing subsequence sum till ith position
    int lis_sum[n];
    for (int i = 0; i < n; i++)
        lis_sum[i] = arr[i];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && lis_sum[i] < lis_sum[j] + arr[i])
                lis_sum[i] = lis_sum[j] + arr[i];
        }
    }
    // max element in lis_sum array is the maximum sum
    cout<<endl<<"lis sum: "<<maxElement(lis_sum, n);
}

int maxElement(int *arr, int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void printArray(int *arr, int size) {
    if (size < 1 || arr == NULL)
        return;
    for (int i = 0; i < size; i++)
        cout<<arr[i]<<" ";
}
 
int main () {
    int arr[] = {1, 101, 2, 3, 100, 4, 5};
    int n = sizeof(arr)/sizeof(int);
    
    cout<<"array: ";
    printArray(arr, n);
    lisSum(arr, n);

    cout<<endl<<endl;
}