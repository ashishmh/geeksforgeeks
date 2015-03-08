// http://www.geeksforgeeks.org/sort-elements-by-frequency/

#include <iostream>
#include <vector>
using namespace std;

void frequencySort(int* arr, int n);
bool pairCompare(const pair<int,int> firstElem, const pair<int,int> secondElem);
int maxValueInArray(int* arr, int n);
void printArr(int* arr, int size);

void frequencySort(int* arr, int n) {
	int max = maxValueInArray(arr, n);
	int count[max+1], output[n], i;
	for (i = 0; i < max+1; i++)
		count[i] = 0;
	for (i = 0; i < n; i++)
		++count[arr[i]];

	// making a vector of pair to store each distinct element and its count
	// pair.first contains count and pair.second contains actual element
	vector<pair<int,int> > tempArray;
	for (i = 0; i < max+1; i++)
		tempArray.push_back(make_pair(count[i], i));

	// sorting the vector based on count of element in descending order
	stable_sort(tempArray.begin(), tempArray.end());
	reverse(tempArray.begin(), tempArray.end());

	vector<pair<int, int> >::iterator itr;
	// printing output
	cout<<endl<<"frequency sort (stable): ";
	for (itr = tempArray.begin(); itr < tempArray.end(); itr++)
		for (i = itr->first; i > 0; i--) {
			cout<<itr->second<<" ";
			--(itr->first);
		}
}

// function to compare elements of pair based on count in descending order
bool pairCompare(const pair<int,int> firstElem, const pair<int,int> secondElem) {
	return firstElem.first > secondElem.first;
}

int maxValueInArray(int* arr, int n) {
	int max = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > max)
			max = arr[i];
	return max;
}

void printArr(int* arr, int size) {
	for (int i = 0; i < size; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

int main() {
    freopen("input.txt","r",stdin);

	int n;					// n is no of elements in input array
	cin>>n;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin>>arr[i];
	cout<<"original array: ";
	printArr(arr, n);
	frequencySort(arr, n);
	cout<<endl<<endl;
	return 0;
}