// http://www.geeksforgeeks.org/dynamic-programming-set-24-optimal-binary-search-tree/

#include <iostream>
#define INF numeric_limits<int>::max()
using namespace std;

void optimalBst(int *keys, int* freq, int n);
int freqSum(int *arr, int i, int j);

void optimalBst(int *keys, int* freq, int n) {
    // cost[i][j] stores optimal cost for index from i to j
    int cost[n][n];
    // storing cost for single key bst
    for (int i = 0; i < n; i++)
        cost[i][i] = freq[i];
    // for more than one key i.e i != j
    for (int L = 2; L <= n; L++) {
        // i is starting index for key length L
        for (int i = 0; i < n-L+1; i++) {
            // j is ending index for key length L
            int j = i+L-1;
            if (j < n)
                cost[i][j] = INF;
            for (int r = i; r <= j; r++) {
                // c contains cost from i to j
                int c = ( ((r > i) ? cost[i][r-1] : 0) +
                          ((r < j) ? cost[r+1][j] : 0) +
                          freqSum(freq, i , j)
                    );
                if (cost[i][j] > c)
                    cost[i][j] = c;
            }
        }
    }
    cout<<"optimal BST cost: "<<cost[0][n-1];
}

int freqSum(int *arr, int i, int j) {
    int sum = 0;
    for (int k = i; k <= j ; k++)
        sum = sum + arr[k];
    return sum;
}

int main () {
    int keys[] = {10, 12, 20};
    int freq[] = {34, 8, 50};
    int n = sizeof(keys)/sizeof(int);
  
    optimalBst(keys, freq, n);

    cout<<endl<<endl;
}