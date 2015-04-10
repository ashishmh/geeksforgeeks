#include <iostream>
#define R 6
#define C 5
using namespace std;

void findMaxSubSquare(int M[R][C]);
int findMin(int a, int b, int c);

void findMaxSubSquare(int M[R][C]) {
    int S[R][C] ;
    int i, j;
    // copy first row and col as it is
    for (i = 0; i < R; i++)
        S[i][0] = M[i][0];
    for (i = 0; i < C; i++)
        S[0][i] = M[0][i];
    for (i = 1; i < R; i++) {
        for (j = 1; j < C; j++) {
            if (M[i][j] == 1)
                S[i][j] = findMin(S[i-1][j], S[i][j-1], S[i-1][j-1]) + 1;
            else
                S[i][j] = 0;
        }
    }
    // find max value in S[R][C]
    int max = 0, max_i = 0, max_j = 0;
    for (i = 0; i < R; i++)
        for (j = 0; j < C; j++)
            if (S[i][j] > max) {
                max = S[i][j];
                max_i = i;
                max_j = j;                
            }
    // print max square matrix using max value and max_i & max_j indices
    for (i = (max_i - max + 1); i <= max_i; i++) {
        for (j = (max_j - max + 1); j <= max_j; j++)
            cout<<M[i][j]<<" ";
        cout<<endl;
    }
        
}

int findMin(int a, int b, int c) {
    int temp = (a > b) ? b : a;
    return (temp > c) ? c : temp;
}

int main() {
    int M[R][C] = { {0, 1, 1, 0, 1}, 
                    {1, 1, 0, 1, 0}, 
                    {0, 1, 1, 1, 0},
                    {1, 1, 1, 1, 0},
                    {1, 1, 1, 1, 1},
                    {0, 0, 0, 0, 0}
                };

    findMaxSubSquare(M);
    
    cout<<endl;
    return 0;
}