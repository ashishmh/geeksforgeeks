// http://www.geeksforgeeks.org/factorial-large-number/

#include <iostream>
#include <string>
using namespace std;

string bigMultiply(string str, int n);
void printReverseStr(string str);

string bigFactorial(int n) {
    string fact;
    fact += ('0' + 1);
    for (int i = n; i > 1; i--)
        fact = bigMultiply(fact, i);
    return fact;
}

string bigMultiply(string str, int n) {
    int i, x, carry = 0;
    string result;
    for (i = 0; i < str.length(); i++) {
        x = ( (str[i]-'0') * n ) + carry;
        result += ('0' + x % 10);
        carry = x/10;
    }
    while (carry > 0) {
        result += ('0' + carry % 10);
        carry = carry/10;
        i++;
    }
    return result;
}

void printReverseStr(string str) {
    for (int i = str.length()-1; i >= 0; i--)
        cout<<str[i];
}

int main() {
    string fact = bigFactorial(100);
    cout<<"factorial: ";
    printReverseStr(fact);
    cout<<endl;
    return 0;
}