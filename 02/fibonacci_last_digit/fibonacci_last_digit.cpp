#include <iostream>
#include <cstdlib>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

int get_fibonacci_last_digit(int n) { 
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

void test() {
    while (true) {
        int n = rand() % 20 + 2;

        std::cout << n << '\n';

        int naive = get_fibonacci_last_digit_naive(n);

        std::cout << naive << '\n';

        int fast = get_fibonacci_last_digit(n);
        
        std::cout << fast << '\n';

        if (naive != fast) {
            std::cout << "ERR" << '\n';
            break;
        }
    }
}

int main() {
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit(n);
    std::cout << c << '\n';
}
