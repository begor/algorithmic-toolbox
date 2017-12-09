#include <iostream>
#include <vector>

using namespace std;


int get_change(int m) {
  int coins[3] = {10, 5, 1};
  int n = 0, i = 0;

  while (m > 0) {
  	int coin = coins[i];

  	if (m >= coin) {
  		n++;
  		m -= coin;
  	} else {
  		i++;
  	}
  }

  return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
