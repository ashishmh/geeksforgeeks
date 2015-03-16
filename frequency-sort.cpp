// http://www.geeksforgeeks.org/sort-elements-by-frequency/

#include <iostream>
#include <vector>
using namespace std;

void frequencySort(int *arr, int size);
void printArr(int *arr, int size);

void frequencySort(int *arr, int size) {
	int i, count[100] = {0};
	for (i = 0; i < size; i++)
		count[arr[i]]++;
	
	// making a vector of pair to store each distinct element and its count
	// pair.first contains count and pair.second contains actual element
	vector<pair<int,int> > temp;
	for (i = 0; i < 100; i++)
		if (count[i] > 0)
			temp.push_back(make_pair(count[i], i));

	// sorting the vector based on count of element in descending order
	sort(temp.begin(), temp.end());
	reverse(temp.begin(), temp.end());

	// printing output
	vector<pair<int,int> >::iterator itr;
	for (itr = temp.begin(); itr < temp.end(); itr++)
		for (i = itr->first; i > 0; i--)
			cout<<itr->second<<" ";
}

void printArr(int *arr, int size) {
	for (int i = 0; i < size; i++)
		cout<<arr[i]<<" ";
}

int main() {
	int arr[] = {1,2,4,1,3,1,4,5,6,7,1,8,8,9,4};
	printArr(arr, 15);
	cout<<endl;
	frequencySort(arr, 15);
	cout<<endl;
	return 0;
}