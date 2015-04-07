// http://www.geeksforgeeks.org/median-of-two-sorted-arrays/

#include <iostream>
using namespace std;

void findMedian(int *arr1, int n1, int *arr2, int n2);
int sortedMergeTillHalf(int *result, int *arr1, int n1, int *arr2, int n2);
void printArray(int *arr, int size);

void findMedian(int *arr1, int n1, int *arr2, int n2) {
    int result[1000] = {0};
    int median = sortedMergeTillHalf(result, arr1, n1, arr2, n2);
    if ((n1+n2) % 2 != 0)
        cout<<endl<<"median: "<<result[median];
    else
        cout<<endl<<"median: "<<(result[median-1] + result[median]) / 2;
}

int sortedMergeTillHalf(int *result, int *arr1, int n1, int *arr2, int n2) {
    int count = 0;
    int i = 0, j = 0;
    while (count <= (n1+n2)/2 && i < n1 && j < n2) {
        if (arr1[i] < arr2[j])
            result[count++] = arr1[i++];
        else
            result[count++] = arr2[j++];
    }
    return count-1;
}

void printArray(int *arr, int size) {
    if (size < 1 || arr == NULL)
        return;
    for (int i = 0; i < size; i++)
        cout<<arr[i]<<" ";
}

int main() {
    int arr1[] = {1, 12, 15, 26, 38};
    int n1 = sizeof(arr1)/sizeof(int);
    cout<<"array1: ";
    printArray(arr1, n1);

    int arr2[] = {2, 13, 17, 30, 45, 55};
    int n2 = sizeof(arr2)/sizeof(int);
    cout<<endl<<"array2: ";
    printArray(arr2, n2);

    findMedian(arr1, n1, arr2, n2);
    cout<<endl<<endl;
    return 0;
}