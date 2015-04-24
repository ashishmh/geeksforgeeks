// http://www.geeksforgeeks.org/dynamic-programming-set-6-min-cost-path/

#include <iostream>
#include <limits>
#define R 3
#define C 3
using namespace std;

int minCostPathNaive(int cost[R][C], int m, int n);
int minCostPathDP(int cost[R][C], int m, int n);
int min(int a, int b, int c);
void printMatrix(int *m, int rows, int cols);

int minCostPathNaive(int cost[R][C], int m, int n) {
    if (m < 0 || n < 0)
        return INT_MAX;
    else if (m == 0 && n == 0)
        return cost[m][n];
    else
        return cost[m][n] + min(
            minCostPathNaive(cost, m-1, n),
            minCostPathNaive(cost, m-1, n-1),
            minCostPathNaive(cost, m, n-1));
}

int minCostPathDP(int cost[R][C], int m, int n) {
    // temp[i][j] stores min cost from (0,0) to (i,j)
    int temp[m][n];
    temp[0][0] = cost[0][0];
    for (int i = 1; i <= m; i++)
        temp[i][0] = temp[i-1][0] + cost[i][0];
    for (int j = 1; j <= n; j++)
        temp[0][j] = temp[0][j-1] + cost[0][j];

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <=n; j++) {
            temp[i][j] = cost[i][j] + min(temp[i-1][j], temp[i-1][j-1], temp[i][j-1]);
        }
    }
    return temp[m][n];
}

int min(int a, int b, int c) {
    int temp = (a < b) ? a : b;
    return (temp < c) ? temp : c;
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
 
int main () {
    int cost[R][C] = { {1, 2, 3},
                      {4, 8, 2},
                      {1, 5, 3} };
    
    cout<<"cost matrix: "<<endl;
    int *m = (int *)cost;
    printMatrix(m, R, C);

    cout<<endl<<"min cost (naive): "<<minCostPathNaive(cost, 2, 2);
    cout<<endl<<"min cost (DP): "<<minCostPathDP(cost, 2, 2);

    cout<<endl<<endl;
}