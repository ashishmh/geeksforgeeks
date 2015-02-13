// You are given a one dimensional array that may contain both positive and negative integers, find the sum 
// of contiguous subarray of numbers which has the largest sum.

// http://www.geeksforgeeks.org/divide-and-conquer-maximum-sum-subarray/

#include <iostream>
#include <cstdio>
#include <limits>
using namespace std;

class result						// for returning low index, high index and sum of max sub-array
{
public:
	int lo, hi, sum;
	result(int lo, int hi, int sum) {
		this->lo = lo;
		this->hi = hi;
		this->sum = sum;
	}
};

result* maxSubArray(int* arr, int lo, int hi);
result* maxCrossingSubArray(int* arr, int lo, int mid, int hi);

result* maxSubArray(int* arr, int lo, int hi) {
    if (lo == hi)
    	return new result(lo, hi, arr[lo]);
    int mid = (lo + hi)/2;
    result* left = maxSubArray(arr, lo, mid);
    result* right = maxSubArray(arr, mid+1, hi);
    result* cross = maxCrossingSubArray(arr, lo, mid, hi);
    if (left->sum > right->sum && left->sum > cross->sum)
    	return left;
    else if (right->sum > left->sum && right->sum > cross->sum)
    	return right;
    else return cross;
}

result* maxCrossingSubArray(int* arr, int lo, int mid, int hi) {
	int sum, left_sum, left_index, right_sum, right_index;
	sum = 0;
	left_sum = numeric_limits<int>::min();
	for (int i=mid; i>=lo; i--) {
		sum = sum + arr[i];
		if (sum > left_sum) {
			left_sum = sum;
			left_index = i;
		}
	}
	sum = 0;
	right_sum = numeric_limits<int>::min();
	for (int i=mid+1; i<=hi; i++) {
		sum = sum + arr[i];
		if (sum > right_sum) {
			right_sum = sum;
			right_index = i;
		}
	}
    return new result(left_index, right_index, left_sum+right_sum);
}

int main() {
    freopen("input.txt","r",stdin);

    int size;
    cin>>size;
    int arr[size];
    for(int i=0; i<size; i++)
    	cin>>arr[i];
    result* r = maxSubArray(arr, 0, size-1);
    cout<<"Max sub-array.."<<endl;
    cout<<"low index: "<<r->lo<<endl;
    cout<<"high index: "<<r->hi<<endl;
    cout<<"sum: "<<r->sum<<endl;
    return 0;
}