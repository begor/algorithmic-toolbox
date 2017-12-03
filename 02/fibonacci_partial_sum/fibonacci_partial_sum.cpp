#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
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

int fibonacci_sum(long long n, int m) {
    // Using solution for previos problem
    long long period = get_pisano_period(m);
    
    int previous = 0;
    int current  = 1;

    for (int i = 1; i < (n + 2) % period; ++i) {
        long long next = (previous + current) % m;


        previous = current;
        current = next;
    }

    return current - 1;
}

int get_fibonacci_last_digit(int n) {
    // Using solution for previos problem 
    if (n <= 1) {
        return n;
    }

    int prev_last_digit = 0;
    int curr_last_digit = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = prev_last_digit;
        prev_last_digit = curr_last_digit;
        curr_last_digit = (tmp_previous + curr_last_digit) % 10;
    }

    return curr_last_digit % 10;
}

long long get_fibonacci_partial_sum(long long from, long long to) {
    if (from == to) {
        long long with_pisano = to % 60;

        return get_fibonacci_last_digit(with_pisano); // 60 is Pisano period fo 10
    }
    
    return (fibonacci_sum(to, 100) - fibonacci_sum(from - 1, 10)) % 10;
}

void test() {
    while (true) {
        long long from = rand() % 10 + 2;
        long long to = rand() % 10 + 2;

        if (from > to) {
            continue;
        }

        std::cout << from  << ".." << to << '\n';

        int naive = get_fibonacci_partial_sum_naive(from, to);

        std::cout << naive << '\n';

        int fast = get_fibonacci_partial_sum(from, to);
        
        std::cout << fast << '\n';

        if (naive != fast) {
            std::cout << "ERR" << '\n';
            break;
        }
    }
}

int main() {
    long long from, to;
    // test();
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum(from, to) << '\n';
}
