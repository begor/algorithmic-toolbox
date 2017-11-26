#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }

    int mod = a % b;

    return gcd(b, mod);
}

long long lcm(int a, int b) {
    long long ab_gcd = gcd(a, b);
    long long product = a * b;

    return product / ab_gcd;
}


void test() {
    while(true) {
        int a = rand() % 1000 + 2;
        int b = rand() % 1000 + 2;

        std::cout << a << std::endl;
        std::cout << b << std::endl;

        long long naive = lcm_naive(a, b);
        long long fast = lcm(a, b);

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
    std::cout << lcm(a, b) << std::endl;
    return 0;
}
