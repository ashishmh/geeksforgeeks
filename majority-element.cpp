/*
Majority Element: A majority element in an array A[] of size n is an element that appears more
than n/2 times (and hence there is at most one such element).

http://www.geeksforgeeksc.org/majority-element/
*/

#include <iostream>
using namespace std;

void majorityElement(int* arr, int size) {
    int count[100] = {0}, i;
    for (i = 0; i < size; i++)
        ++count[arr[i]];
    for (i = 0; i < 100; i++)
        if (count[i] > size/2) {
            cout<<i;
            return;
        }
    cout<<"NONE";
}

int main() {
    freopen("input.txt","r",stdin);

    int size;
    cin>>size;
    int arr[size];
    for(int i = 0; i < size; i++)
        cin>>arr[i];
    majorityElement(arr, size);
    cout<<endl;
    return 0;
}