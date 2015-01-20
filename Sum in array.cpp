/*
Write a C program that, given an array A[] of n numbers and another number x,
determines whether or not there exist two elements in S whose sum is exactly x. 

http://www.geeksforgeeks.org/write-a-c-program-that-given-a-set-a-of-n-numbers-and-another-number-x-determines-whether-or-not-there-exist-two-elements-in-s-whose-sum-is-exactly-x/
*/


#include <iostream>
#include <cstdio>
using namespace std;

void sumInArray(int* arr, int size, int x) {
	int first = 0, last = size-1;
    while(last > first) {
        if(x == arr[first] + arr[last]) {
        cout<<x<<" as a sum exists."<<endl;
        return;
        }
        else if(x > arr[first] + arr[last])
            ++first;
        else --last;
    }
    cout<<x<<" as a sum does not exist."<<endl;
	return;
}

void bubbleSort(int* arr, int size) {
    bool flag = true;
    while(flag) {
        flag = false;
        for(int i=0; i<size; i++) {
            if(arr[i] > arr[i+1]) {
                flag = true;
                int temp = arr[i+1];
                arr[i+1] = arr[i];
                arr[i] = temp;
            }
        }
    }
    return;
}

int main() {
    freopen("input.txt","r",stdin);

    int size, x;
    cin>>size;
    int arr[size];
    for(int i=0; i<size; i++)
    	cin>>arr[i];
    cin>>x;
    bubbleSort(arr, size);
    sumInArray(arr, size, x);
    return 0;
}