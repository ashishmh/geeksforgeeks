// http://www.geeksforgeeks.org/program-for-nth-fibonacci-number/

#include <iostream>
using namespace std;

void fibonacciRecursion(int max);
void fibonacciRecursionAux(int a, int b, int max);
void fibonacciIteration(int max);

void fibonacciRecursion(int max) {
	int a = 0, b = 1;
	cout<<a<<" "<<b<<" ";
	fibonacciRecursionAux(a, b, max);
}

void fibonacciRecursionAux(int a, int b, int max) {
	int sum = a + b;
	if (sum > max)
		return;
	cout<<sum<<" ";
	fibonacciRecursionAux(b, sum, max);
}

void fibonacciIteration(int max) {
	int a = 0, b = 1;
	int sum = 1;
	cout<<a<<" ";
	while (sum < max) {
		cout<<sum<<" ";
		sum = a + b;
		a = b;
		b = sum;
	}
}

int main() {
	fibonacciRecursion(100);
	cout<<endl;
	fibonacciIteration(100);
	cout<<endl;
	return 0;
}