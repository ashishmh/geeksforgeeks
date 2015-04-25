// http://www.geeksforgeeks.org/dynamic-programming-set-8-matrix-chain-multiplication/

#include <iostream>
#include <limits>
using namespace std;

int matrixChainCount(int *p, int i, int j) {
    if (i == j)
        return 0;
    int min = INT_MAX;
    for (int k = i; k < j; k++) {
        int count = matrixChainCount(p, i , k) +
            matrixChainCount(p, k+1, j) + (p[i-1]*p[k]*p[j]);
        if (count < min)
            min = count;
    }
    return min;
}

int matrixChainCountDP(int *p, int n) {
    // cost[i][j] stores min cost of multiplying matrix Ai to Aj
    int cost[n][n];
    // cost of multiplying a single matrix (i.e length = 1) is zero
    for (int i = 1; i < n; i++)
        cost[i][i] = 0;
    // for length >= 2
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n-L+1; i++) {
            int j = i+L-1;
            cost[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int q = cost[i][k] + cost[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < cost[i][j])
                    cost[i][j] = q;
            }
        }
    }
    // return min cost of multiplying matrix A(1) to A(n-1)
    return cost[1][n-1];
}

int main () {
    int arr[] = {40, 20, 30, 10, 30};
    int n = sizeof(arr)/sizeof(int);

    cout<<"min no of multiplications (naive): "<<matrixChainCount(arr, 1, n-1);
    cout<<endl<<"min no of multiplications (DP): "<<matrixChainCountDP(arr, n);

    cout<<endl<<endl;
}