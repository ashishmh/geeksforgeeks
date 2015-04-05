// http://www.geeksforgeeks.org/write-a-c-program-that-given-a-set-a-of-n-numbers-and-another-number-x-determines-whether-or-not-there-exist-two-elements-in-s-whose-sum-is-exactly-x/
// using array binary map

#include <iostream>
using namespace std;

void findPairInArray(int *arr, int size, int sum);
void printArray(int *arr, int size);

void findPairInArray(int *arr, int size, int sum) {
    bool bin_map[1000] = {0};
    int x;
    bool flag = false;
    for (int i = 0; i < size; i++) {
        x = sum - arr[i];
        if (x >= 0 && bin_map[x] == 1) {
            cout<<endl<<"pair with sum "<<sum<<" is: "<<x<<" & "<<sum-x;
            flag = true;            
        }
        else
            bin_map[arr[i]] = 1;
    }
    if (flag == false)
        cout<<endl<<sum<<" as pair not in array..";
}

void printArray(int *arr, int size) {
    if (size < 1 || arr == NULL)
        return;
    for (int i = 0; i < size; i++)
        cout<<arr[i]<<" ";
}

int main() {
    int arr[] = {1, 4, 45, 6, 10, 12, -8};
    cout<<"array: ";
    printArray(arr, 7);
    cout<<endl;
    findPairInArray(arr, 7, 16);
    findPairInArray(arr, 7, 99);

    cout<<endl<<endl;
    return 0;
}