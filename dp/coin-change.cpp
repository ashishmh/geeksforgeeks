// http://www.geeksforgeeks.org/dynamic-programming-set-7-coin-change/

#include <iostream>
using namespace std;

int countSolutions(int *S, int m, int n) {
    int sol[n+1][m];
    // if value is zero, there is one solution, don't include any coin
    for (int i = 0; i < m; i++)
        sol[0][i] = 1;
    for (int i = 1; i < n+1; i++) {
        for (int j = 0; j < m; j++) {
            // x is no of solutions including S[j] coin
            int x = (i-S[j] >= 0) ? sol[i-S[j]][j] : 0;
            // y is no of solutions excluding S[j] coin
            int y = (j > 0) ? sol[i][j-1] : 0;
            // total no of solutions is x + y for value = i and no of coins = j
            sol[i][j] = x + y;
        }
    }
    return sol[n][m-1];
}

int main () {
    int arr[] = {2, 5, 3, 6};
    int m = sizeof(arr)/sizeof(int);
    int n = 10;

    cout<<"max no of coin changes: "<<countSolutions(arr, m, n);

    cout<<endl<<endl;
}