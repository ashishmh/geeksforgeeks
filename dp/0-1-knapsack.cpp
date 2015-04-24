// http://www.geeksforgeeks.org/dynamic-programming-set-10-0-1-knapsack-problem/

#include <iostream>
using namespace std;

void knapSack(int W, int *wt, int *val, int n);

void knapSack(int W, int *wt, int *val, int n) {
    int K[n+1][W+1];
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i-1] <= w)
                K[i][w] = max(K[i-1][w], (K[i-1][w-wt[i-1]] + val[i-1]));
            else 
                K[i][w] = K[i-1][w];
        }
    }
    cout<<"max val in knapsack: "<<K[n][W];
}

int main () {
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int n = sizeof(val)/sizeof(int);
    int W = 50;
  
    knapSack(W, wt, val, n);

    cout<<endl<<endl;
}