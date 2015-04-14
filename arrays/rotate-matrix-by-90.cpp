// http://www.geeksforgeeks.org/turn-an-image-by-90-degree/

#include <iostream>
using namespace std;

void rotate90(int *pSrc, int *pDest, int rows, int cols);
void printMatrix(int *m, int rows, int cols);

void rotate90(int *pSrc, int *pDest, int rows, int cols) {
    int i, j, k, l;
    for (i = 0, l = rows-1; i < rows; i++, l--)
        for (j = 0, k = 0; j < cols; j++, k++)
            *(pDest + k*rows + l) = *(pSrc + i*cols + j);
}

void printMatrix(int *m, int rows, int cols) {
    if (m == NULL)
        return;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            cout<<*(m + i*cols + j)<<" ";
        cout<<endl;   
    }
}

int main() {
    int arr[3][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
    int rows = 3, cols = 4;
    int* pSource = (int *)arr;
    int *pDestination = (int *)new int[4][3];

    cout<<"source matrix.."<<endl;
    printMatrix(pSource, rows, cols);
    cout<<endl;

    cout<<"after rotating 90 deg.."<<endl;
    rotate90(pSource, pDestination, rows, cols);
    printMatrix(pDestination, cols, rows);

    cout<<endl;
    return 0;
}