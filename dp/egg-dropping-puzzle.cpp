// http://www.geeksforgeeks.org/dynamic-programming-set-11-egg-dropping-puzzle/

#include <iostream>
#include <limits>
using namespace std;

int max(int a, int b);

int eggDropNaive(int n, int k) {
    // if no of floors is 0 or 1 return k
    if (k == 0 || k == 1)
        return k;
    // if no of eggs is 1 and k floors, return k
    if (n == 1)
        return k;
    int min = INT_MAX;
    for (int x = 1; x < k; x++) {
        int trials = max(eggDropNaive(n-1, x-1), eggDropNaive(n, k-x));
        if (trials < min)
            min = trials;
    }
    return min+1;
}

int eggDropDP(int n, int k) {
    // egg_floor[i][j] stores min no of trials for i eggs and j floors
    int egg_floor[n+1][k+1];
    // if floor = 1 or 0, there are 1 and 0 trials resp
    for (int i = 1; i <= n; i++) {
        egg_floor[i][0] = 0;
        egg_floor[i][1] = 1;
    }
    // if eggs = 1, trials = no of floors
    for (int i = 1; i <= k; i++)
        egg_floor[1][i] = i;
    // in following loops i is for eggs and j for floors
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= k; j++) {
            egg_floor[i][j] = INT_MAX;
            for (int x = 1; x <= j; x++) {
                int trials = 1 + max(egg_floor[i-1][x-1], egg_floor[i][j-x]);
                // if new trial value is less then min value in egg_floor, put new value in egg_floor
                if (trials < egg_floor[i][j])
                    egg_floor[i][j] = trials;
            }
        }
    }
    return egg_floor[n][k];
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main () {
    int n = 2;
    int k = 10;
    cout<<"min no of trials in worst case (naive): "<<eggDropNaive(n, k);
    cout<<endl<<"min no of trials in worst case (DP): "<<eggDropDP(n, k);

    cout<<endl<<endl;
}