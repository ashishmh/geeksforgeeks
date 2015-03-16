// http://www.geeksforgeeks.org/count-trailing-zeroes-factorial-number/

#include <iostream>
using namespace std;

int trailingZeros(int n);
int factorialRecursion(int n);

int trailingZeros(int n) {
	int fact = factorialRecursion(n);
	int count = 0;
	while (fact > 0) {
		if ((fact % 10) != 0)
			return count;
		count++;
		fact = fact/10;
	}
	return count;
}

int factorialRecursion(int n) {
	if (n <= 1)
		return 1;
	return (n * factorialRecursion(n-1));
}

int main() {
	cout<<factorialRecursion(10);
	cout<<endl<<"no of zeros: ";
	cout<<trailingZeros(10);
	cout<<endl;
	cout<<factorialRecursion(4);
	cout<<endl<<"no of zeros: ";
	cout<<trailingZeros(4);
	cout<<endl;
	return 0;
}