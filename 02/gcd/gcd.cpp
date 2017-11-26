#include <iostream>
#include <cstdlib>

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }

    int mod = a % b;

    return gcd(b, mod);
}

void test() {
    while(true) {
        int a = rand() % 1000 + 2;
        int b = rand() % 1000 + 2;

        std::cout << a << std::endl;
        std::cout << b << std::endl;

        int naive = gcd_naive(a, b);
        int fast = gcd(a, b);

        std::cout << naive << std::endl;
        std::cout << fast << std::endl;

        if (naive != fast) {
            std::cout << "ERR" << std::endl;
            break;
        }
    }
}

int main() {
    int a, b;
    std::cin >> a >> b;
    std::cout << gcd(a, b) << std::endl;
    return 0;
}
