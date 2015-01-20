/*
Find the missing number
You are given a list of n-1 integers and these integers are in the range of 1 to n. 
There are no duplicates in list. One of the integers is missing in the list. 
Write an efficient code to find the missing integer.

http://www.geeksforgeeks.org/find-the-missing-number/
*/

#include <iostream>
#include <cstdio>
using namespace std;

int missingNumber(int* arr, int size) {
	int sum;
	int n = size+1;
	// n = sizeof(arr);  // this means the size of the pointer to array
	sum = n*(n+1)/2;
	for(int i=0; i<size; i++)
		sum = sum - arr[i];
	return sum;
}

int main() {
    freopen("input.txt","r",stdin);

    int n, missing;
    cin>>n;
    int arr[n-1];
    for (int i=0; i<n-1; i++)
    	cin>>arr[i];
    missing = missingNumber(arr,n-1);
    cout<<"The missing number is: "<<missing<<endl;
    return 0;
}