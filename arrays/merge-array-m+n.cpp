// http://www.geeksforgeeks.org/merge-one-array-of-size-n-into-another-one-of-size-mn/

#include <iostream>
#include <limits>
#define NA INT_MAX
using namespace std;

void binarySearchRotated(int *arr, int beg, int end, int x);
void moveToEnd(int *arr, int size);
void printArray(int *arr, int size);

void mergemPlusN(int *mPlusN, int size_mplusn, int *N, int size_n) {
    moveToEnd(mPlusN, size_mplusn);
    int i = size_n, j = 0, k = 0;
    while (i < size_mplusn && j < size_n) {
        if (mPlusN[i] < N[j])
            mPlusN[k++] = mPlusN[i++];
        else
            mPlusN[k++] = N[j++];
    }
    while (i < size_mplusn)
        mPlusN[k++] = mPlusN[i++];
    while (j < size_n)
        mPlusN[k++] = N[j++];
}

void moveToEnd(int *arr, int size) {
    int j = size-1;
    for (int i = size-2; i >= 0; i--) {
        if (arr[i] != NA) {
            arr[j] = arr[i];
            arr[i] = NA;
            j--;            
        }
    }
}

void printArray(int *arr, int size) {
    if (size < 1 || arr == NULL)
        return;
    for (int i = 0; i < size; i++) {
        if (arr[i] == NA)
            cout<<"NA ";
        else cout<<arr[i]<<" ";
    }
}

int main() {
    int mPlusN[] = {2, NA, 7, NA, NA, 10, NA};
    int size_mplusn = sizeof(mPlusN)/sizeof(int);
    cout<<"array mPlusN: ";
    printArray(mPlusN, size_mplusn);
    cout<<endl;

    int N[] = {5, 8, 12, 14};
    int size_n = sizeof(N)/sizeof(int);
    cout<<"array N: ";
    printArray(N, size_n);
    cout<<endl;
    
    cout<<endl<<"merge: ";
    mergemPlusN(mPlusN, size_mplusn, N, size_n);
    printArray(mPlusN, size_mplusn);

    cout<<endl<<endl;
    return 0;
}