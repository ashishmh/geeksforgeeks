// http://www.geeksforgeeks.org/dynamic-programming-set-12-longest-palindromic-subsequence/

#include <iostream>
using namespace std;

int lpsNaive(char* str, int i, int j);
int lpsDP(char* str, int n);
int max(int a, int b);

int lpsNaive(char* str, int i, int j) {
    // single char
    if (i == j)
        return 1;
    // if 2 characters
    if (j == i+1) {
        // 2 char and same
        if (str[i] == str[j]) return 2;
        // 2 char and not same
        else return 0;
    }
    // more than 2 chars and first = last
    if (str[i] == str[j])
        return 2 + lpsNaive(str, i+1, j-1);
    else 
        return max(lpsNaive(str, i, j-1), lpsNaive(str, i+1, j));
}

int lpsDP(char* str, int n) {
    // len[i][j] stores length of lps from i to j
    int len[n][n];
    // lps of length = 1 is 1
    for (int i = 0; i < n; i++)
        len[i][i] = 1;
    // for length >= 2
    for (int L = 2; L <= n; L++) {
        for (int i = 0; i < n-L+1; i++) {
            int j = i+L-1;
            if (L == 2) {
                // 2 char and same
                if (str[i] == str[j])
                    len[i][j] = 2;
                // 2 char and not same
                else
                    len[i][j] = 0;
            }
            if (str[i] == str[j])
                len[i][j] = 2 + len[i+1][j-1];
            else
                len[i][j] = max(len[i][j-1], len[i+1][j]);
        }
    }
    return len[0][n-1];
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main () {
    char str[] = "BBABCBCAB";
    int n = sizeof(str)/sizeof(str[0]) - 1;

    cout<<"lps (naive): "<<lpsNaive(str, 0, n-1);
    cout<<endl<<"lps (DP): "<<lpsDP(str, n);

    cout<<endl<<endl;
}