#include <iostream>

using namespace std;

long simpleGCD(long a, long b) {
	long min;
	
	if (a < b) {
		min = a;
	} else {
		min = b;
	}

	while (min) {
		if ((a % min == 0) && (b % min == 0)) {
			break;
		}
		
		--min;
	}
	
	return min;
}


long euclidGCD(long a, long b) {
	if (b == 0) { 
		return a;
	}

	long rem = a % b;

	return euclidGCD(b, rem);
}



int main() {
	long a, b;

	cin >> a >> b;

	cout << euclidGCD(a, b);

	return 0;
}