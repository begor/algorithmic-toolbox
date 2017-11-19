#include <iostream>
#include <vector>

using namespace std;


long long fiboSlow(int n) {
	if (n < 2) {
		return n;
	}

	return fiboSlow(n - 2) + fiboSlow(n - 1);
}


long long fiboFast(int n) {
	int current_idx = 2;
	vector<long long> fibos = {0, 1};

	while (n >= current_idx) {
		long long n_1 = fibos[fibos.size() - 1];
		long long n_2 = fibos[fibos.size() - 2];
		long long next_fibo = n_1 + n_2;
		fibos.push_back(next_fibo);
		current_idx++;
	}


	return fibos[n];
}


int main() {
	int n;

	cin >> n;
	cout << fiboFast(n);

	return 0;
}