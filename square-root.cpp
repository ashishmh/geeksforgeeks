// find square root of a number by approximation
// http://www.geeksforgeeks.org/square-root-of-a-perfect-square/

#include <iostream>
#include <cstdio>
using namespace std;

const double ERROR = 0.000000001;

double findSqrt (double n) {
	double low = 0;
	double high = n;
	while ((high-low) > ERROR) {
		double mid = (low+high)/2;
		if ((mid * mid) > n)
			high = mid;
		else low = mid;
	}
	return low;
}

int main() {
    freopen("input.txt","r",stdin);
	
	double n = 0, result = 0;
	cin>>n;
 	cout<<"Square root of "<<n<<" is: "<<findSqrt(n)<<endl;
  	return 0;
}