// http://www.geeksforgeeks.org/two-elements-whose-sum-is-closest-to-zero/

#include <iostream>
using namespace std;

void sumCloseToZero1(int *arr, int n);                      // complexity O(n^2)
void sumCloseToZero2(int *arr, int n);                      // complexity O(nlogn)
void printArray(int *arr, int n);

void sumCloseToZero1(int *arr, int n) {
    if (n < 2)
        return;
    int l_index = 0, r_index = 0, min_sum, sum;
    min_sum = arr[0] + arr[1];
    for (int i = 0; i < n-1; i++)
        for (int j = i+1; j < n; j++) {
            sum = arr[i] + arr[j];
            if (abs(sum) < abs(min_sum)) {
                min_sum = sum;
                l_index = i;
                r_index = j;
            }
        }
    cout<<"min sum: "<<min_sum<<" elements: "<<arr[l_index]<<" "<<arr[r_index];
}

void sumCloseToZero2(int *arr, int n) {
    if (n < 2)
        return;
    // stl sort function, has nlogn complexity
    sort(arr, arr+n-1);

    int i = 0, j = n-1;
    int sum, min_sum, l_index, r_index;
    min_sum = arr[0] + arr[n-1];
    l_index = i;
    r_index = j;

    while (i < j) {
        sum = arr[i] + arr[j];
        if (abs(sum) < abs(min_sum)) {
            min_sum = sum;
            l_index = i;
            r_index = j;
        }
        i++, j--;
    }
    cout<<"min sum: "<<min_sum<<" elements: "<<arr[l_index]<<" "<<arr[r_index];
}

void printArray(int *arr, int n) {
    if (n < 1 || arr == NULL)
        return;
    for (int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
}

int main() {
    int arr[] = {1, 60, -10, 70, -80, 85};
    int n = sizeof(arr)/sizeof(int);
    cout<<"array: ";
    printArray(arr, n);
    cout<<endl<<endl;

    cout<<"O(n^2)   -> ";
    sumCloseToZero1(arr, n);

    cout<<endl<<"O(nlogn) -> ";
    sumCloseToZero2(arr, n);

    cout<<endl<<endl;
    return 0;
}