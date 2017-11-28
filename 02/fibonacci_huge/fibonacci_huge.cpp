#include <iostream>
#include <vector>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}


long long get_pisano_period(long long m) {
    long long previous = 0;
    long long current  = 1;
    long long len = 0;

    while(true) {
        long long next = (current + previous) % m;
        
        previous = current;
        current = next;

        ++len;

        if (previous == 0 && current == 1) {
            break;
        }

    }

    return len;
}

long long get_fibonacci_huge(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    long long period = get_pisano_period(m);


    for (int i = 0; i < n % period; i++) {
        long long next = (previous + current) % m;

        previous = current;
        current = next;
    }

    return previous;
}


void test() {
    while(true) {
        int n = rand() % 20 + 2;
        int m = rand() % 20 + 2;

        long long naive = get_fibonacci_huge_naive(n, m);
        long long fast = get_fibonacci_huge(n, m);

        std::cout << naive << std::endl;
        std::cout << fast << std::endl;

        if (naive != fast) {
            std::cout << "ERR" << std::endl;
            break;
        }
    }
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge(n, m) << '\n';
}
