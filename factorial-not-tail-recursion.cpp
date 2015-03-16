// http://www.geeksforgeeks.org/tail-recursion/
// factorialRecursion function is not a case of Tail Recursion

#include <iostream>
using namespace std;

int factorialRecursion(int n) {
	if (n <= 1)
		return 1;
	return (n * factorialRecursion(n-1));
}

int factorialIteration(int n) {
	if (n <= 1)
		return 1;
	int fact = 1;
	for (int i = n; i > 0; i--)
		fact = fact * i;
	return fact;
}

int main() {
	cout<<factorialRecursion(5);
	cout<<endl;
	cout<<factorialIteration(5);
	cout<<endl;
	return 0;
}