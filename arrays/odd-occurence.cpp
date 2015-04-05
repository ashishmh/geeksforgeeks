// http://www.geeksforgeeks.org/find-the-number-occurring-odd-number-of-times/

#include <iostream>
using namespace std;

void findOdd(int *arr, int size);
void printArray(int *arr, int size);

void findOdd(int *arr, int size) {
    int odd = 0;
    for (int i = 0; i < size; i++)
        odd = odd ^ arr[i];
    cout<<odd;
}

void printArray(int *arr, int size) {
    if (size < 1 || arr == NULL)
        return;
    for (int i = 0; i < size; i++)
        cout<<arr[i]<<" ";
}

int main() {
// using array binary map
    int arr[] = {2, 3, 5, 4, 5, 2, 4, 3, 5, 2, 4, 4, 2};
    cout<<"array: ";
    printArray(arr, 13);
    cout<<endl;
    cout<<"element with odd occurence: ";
    findOdd(arr, 13);

    cout<<endl<<endl;
    return 0;
}