/* Given an array, write a program to generate a random permutation of array elements.
http://www.geeksforgeeks.org/shuffle-a-given-array/
*/

#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;

void swap(int*, int, int);

void shuffleArray(int* arr, int size) {
	srand(time(NULL));
	for (int i = size-1; i >= 1; i--) {
		int random = rand() % i;
		swap(arr, random, i);
	}
    return;
}

void swap(int* arr, int a, int b) {
	int temp = arr[b];
	arr[b] = arr[a];
	arr[a] = temp;
	return;
}

void printArr(int* arr, int size) {
	for (int i = 0; i < size; i++)
		cout<<arr[i]<<endl;
	return;
}

int main() {
    freopen("input.txt","r",stdin);

    int size;
    cin>>size;
    int arr[size];
    for (int i = 0; i < size; i++)
    	cin>>arr[i];
    shuffleArray(arr, size);
    printArr(arr, size);
    return 0;
}