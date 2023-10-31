#include <iostream>


long long largestPrimeFactor(long long num) {
    long long largestPrime = -1;

    while (num % 2 == 0) {
        largestPrime = 2;
        num /= 2;
    }

    for (long long i = 3; i * i <= num; i += 2) {
        while (num % i == 0) {
            largestPrime = i;
            num /= i;
        }
    }

    if (num > 2) {
        largestPrime = num;
    }

    return largestPrime;
}



int main(){

    long long num = 600851475143LL;
    std::cout << largestPrimeFactor(num); 

    return 0;
}