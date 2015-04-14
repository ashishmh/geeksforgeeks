// http://www.geeksforgeeks.org/search-in-row-wise-and-column-wise-sorted-matrix/

#include <iostream>
using namespace std;

void printMatrix(int *m, int rows, int cols);

bool findEleInMatrix(int *mat, int rows, int cols, int x) {
    int i = 0, j = cols-1;
    while (i < rows && j >= 0) {
        if (x == *(mat + i*cols + j)) {
            cout<<x<<" found at index: "<<i<<" "<<j;
            return true;
        }
        else if (x > *(mat + i*cols + j))
            i++;
        else j--;
    }
    return false;
}

void printMatrix(int *mat, int rows, int cols) {
    if (mat == NULL)
        return;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            cout<<*(mat + i*cols + j)<<" ";
        cout<<endl;   
    }
}

int main() {
    int matrix[3][4] = { {10, 20, 30, 40},
                    {15, 25, 35, 45},
                    {27, 29, 37, 48},
                  };
    int *mat = (int *)matrix;
    int rows = 3, cols = 4;

    cout<<"matrix.."<<endl;
    printMatrix(mat, rows, cols);
    cout<<endl;

    if (!findEleInMatrix(mat, rows, cols, 29))
        cout<<"element not found..";
    cout<<endl;
    if (!findEleInMatrix(mat, rows, cols, 99))
        cout<<"element not found..";

    cout<<endl;
    return 0;
}