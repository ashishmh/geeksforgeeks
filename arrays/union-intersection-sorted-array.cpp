// http://www.geeksforgeeks.org/union-and-intersection-of-two-sorted-arrays-2/

#include <iostream>
using namespace std;

void unionArray(int *arr1, int n1, int *arr2, int n2);      
void intersectionArray(int *arr1, int n1, int *arr2, int n2);               
void printArray(int *arr, int n);

void unionArray(int *arr1, int n1, int *arr2, int n2) {
    int i = 0, j = 0;
    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j])
            cout<<arr1[i++]<<" ";
        else if (arr2[j] < arr1[i])
            cout<<arr2[j++]<<" ";
        else {
            cout<<arr1[i]<<" ";
            i++, j++;
        }
    }
    while (i < n1)
        cout<<arr1[i++]<<" ";
    while (j < n2)
        cout<<arr2[j++]<<" ";
}

void intersectionArray(int *arr1, int n1, int *arr2, int n2) {
    int i = 0, j = 0;
    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j])
            i++;
        else if (arr2[j] < arr1[i])
            j++;
        else {
            cout<<arr1[i]<<" ";
            i++, j++;
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
    int arr1[] = {1, 3, 4, 5, 7, 8 , 9};
    int n1 = sizeof(arr1)/sizeof(int);
    cout<<"array1: ";
    printArray(arr1, n1);
    cout<<endl;

    int arr2[] = {2, 3, 5, 6};
    int n2 = sizeof(arr2)/sizeof(int);
    cout<<"array2: ";
    printArray(arr2, n2);
    cout<<endl<<endl;

    cout<<"union: ";
    unionArray(arr1, n1, arr2, n2);
    cout<<endl<<"intersection: ";
    intersectionArray(arr1, n1, arr2, n2);

    cout<<endl<<endl;
    return 0;
}