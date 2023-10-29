#include <iostream>

int main() {
    long long a = 1;  // First Fibonacci number
    long long b = 1;  // Second Fibonacci number
    long long sum = 0; // Sum of even-valued terms

    while (b <= 4000000) {
        if (b % 2 == 0) {
            sum += b;
        }

        long long next = a + b;
        a = b;
        b = next;
    }

    std::cout << "Sum of even-valued Fibonacci terms not exceeding 4 million: " << sum << std::endl;

    return 0;
}
