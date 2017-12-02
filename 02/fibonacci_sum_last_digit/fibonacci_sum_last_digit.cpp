#include <iostream>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

long long get_pisano_period(long long m) {
    // Using solution for previos problem
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


int fibonacci_sum(long long n) {
    // Sum(N) = Fib(N+2) - F(2)
    
    // Also: 
    // Fib(N+2) % 10 == Fib(N+2 % period) % 10, where period is Pisano period for 10
    
    long long period = get_pisano_period(10);
    
    int previous = 0;
    int current  = 1;

    for (int i = 1; i < (n + 2) % period; ++i) {
        long long next = (previous + current) % 10;

        // Suppose Fi-1 = 45 and Fi = 55, so their sum is 100.
        // 100 % 10 = 0, but this is not enough for us, we should carry overflow.  
        if (next == 0) {
            next = 10;
        }

        previous = current;
        current = next;
    }

    return current - 1;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum(n) << std::endl;
}
