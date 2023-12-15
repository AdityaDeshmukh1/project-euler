#include <iostream>
#include <cmath>

int triangleNumber(int n) {
    return (n * (n + 1)) / 2;
}

int countDivisors(int n) {
    int count = 1;  // Initialize count to 1 for the number itself

    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            int exponent = 0;
            while (n % i == 0) {
                n /= i;
                ++exponent;
            }
            count *= (exponent + 1);  // Increment the exponent and multiply
        }
    }

    // If n is a prime number greater than 1
    if (n > 1) {
        count *= 2;
    }

    return count;
}

int main() {
    const int NUM_OF_DIVISORS = 500;
    int n = 1;

    while (countDivisors(triangleNumber(n)) <= NUM_OF_DIVISORS) {
        n++;
    }

    std::cout << "The first triangle number with over " << NUM_OF_DIVISORS << " divisors is: " << triangleNumber(n) << std::endl;

    return 0;
}
