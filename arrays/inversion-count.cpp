// http://www.geeksforgeeks.org/counting-inversions/

#include <iostream>
using namespace std;

int inversionCount1(int *arr, int n);						// O(n^2)
int inversionCount2(int *arr, int n);						// O(nlogn)
int mergeSort(int *arr, int beg, int end);
int sortedMerge(int *arr, int beg, int mid, int end);
void printArray(int *arr, int size);

int inversionCount1(int *arr, int n) {
	int inv_count = 0;
	for (int i = 0; i < n-1; i++)
		for (int j = i+1; j < n; j++)
			if (arr[i] > arr[j])
				inv_count++;
	return inv_count;
}

int inversionCount2(int *arr, int n) {
	int beg = 0;
	int end = n-1;
	int inv_count;
	inv_count = mergeSort(arr, beg, end);

	return inv_count;
}

int mergeSort(int *arr, int beg, int end) {
	if (beg >= end)
		return 0;

	int left_count = 0, right_count = 0, cross_count = 0;
	int mid = (beg+end)/2;
	left_count = mergeSort(arr, beg, mid);
	right_count = mergeSort(arr, mid+1, end);
	cross_count = sortedMerge(arr, beg, mid, end);

	return (left_count + right_count + cross_count);
}

int sortedMerge(int *arr, int beg, int mid, int end) {
	int inv_count = 0;
	int i = beg, j = mid+1, k = beg;
	int temp[end+1];
	while (i <= mid && j <= end) {
		if (arr[i] < arr[j])
			temp[k++] = arr[i++];
		else {
			temp[k++] = arr[j++];
			inv_count = inv_count + (mid - i + 1);
		}
	}
	while (i <= mid)
		temp[k++] = arr[i++];
	while (j <= end)
		temp[k++] = arr[j++];
	for (i = beg; i <= end; i++)
		arr[i] = temp[i];

	return inv_count;
}

void printArray(int *arr, int size) {
    if (size < 1 || arr == NULL)
        return;
    for (int i = 0; i < size; i++)
        cout<<arr[i]<<" ";
}

int main() {
    int arr[] = {1, 20, 6, 4, 5};
    int n = sizeof(arr)/sizeof(int);
    cout<<"array: ";
    printArray(arr, n);
    cout<<endl;

    cout<<"inversion count O(n^2): ";
    cout<<inversionCount1(arr, n);

    cout<<endl<<"inversion count O(nlogn): ";
    cout<<inversionCount2(arr, n);

    cout<<endl<<endl;
    return 0;
}