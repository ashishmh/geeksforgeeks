// http://www.geeksforgeeks.org/a-product-array-puzzle/

#include <iostream>
using namespace std;

void printArray(int *arr, int n);

void productArray1(int *arr, int n) {
    int p[n];
    int prod;
    for (int i = 0; i < n; i++) {
        prod = 1;
        for (int j = 0; j < n; j++) {
            if (j == i)
                continue;
            prod = prod * arr[j];
        }
        p[i] = prod;
    }
    cout<<"product array O(n^2): ";
    printArray(p, n);
}

void productArray2(int *arr, int n) {
    int p[n];
    for (int i = 0; i < n; i++)
        p[i] = 1;

    int temp = 1;
    for (int i = 0; i < n; i++) {
        p[i] = p[i] * temp;
        temp = temp * arr[i];
    }
    temp = 1;
    for (int i = n-1; i >= 0; i--) {
        p[i] = p[i] * temp;
        temp = temp * arr[i];
    }
    cout<<"product array O(n):   ";
    printArray(p, n);
}

void printArray(int *arr, int n) {
    if (n < 1 || arr == NULL)
        return;
    for (int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
}

int main() {
    int arr[] = {10, 3, 5, 6, 2};
    int n = sizeof(arr)/sizeof(int);
    cout<<"array: ";
    printArray(arr, n);
    cout<<endl<<endl;

    productArray1(arr, n);
    cout<<endl;
    productArray2(arr, n);

    cout<<endl<<endl;
    return 0;
}