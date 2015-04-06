// http://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
// using kadane's algo

#include <iostream>
using namespace std;

int findMaxSumSubarray(int *arr, int size);
void printArray(int *arr, int size);

int findMaxSumSubarray(int *arr, int size) {
    int max_so_far = 0;
    int max_here = 0;
    int start_index = 0, end_index = 0;
    for (int i = 0; i < size; i++) {
        max_here = max_here + arr[i];
        if (max_here < 0) {
            max_here = 0;
            // if max_here resets, index starts from next element
            start_index = i+1;            
        }
        if (max_here > max_so_far) {
            max_so_far = max_here;
            // end index is when max_so_far is set last time
            end_index = i;            
        }
    }
    // if max sum consists of single element
    if (start_index > end_index)
        start_index = end_index;
    cout<<endl<<"start index: "<<start_index+1<<" | end index: "<<end_index+1<<endl;
    return max_so_far;
}

void printArray(int *arr, int size) {
    if (size < 1 || arr == NULL)
        return;
    for (int i = 0; i < size; i++)
        cout<<arr[i]<<" ";
}

int main() {
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    cout<<"array: ";
    printArray(arr, 8);
    cout<<endl;
    cout<<"max sum subarray: ";
    int sum = findMaxSumSubarray(arr, 8);
    cout<<"sum: "<<sum;

    cout<<endl<<endl;
    return 0;
}