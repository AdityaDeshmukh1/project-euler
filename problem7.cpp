#include <bits/stdc++.h>
#include <iostream>

std::vector<int> sieveOfEratosthenes(int limit){
    std::vector<bool> isPrime(limit + 1, true);
    isPrime[0] = isPrime[1] = false;

    for(int p = 2; p*p <= limit; ++p){
        if (isPrime[p]){
            for (int i = p*p; i <= limit; i += p ){
                isPrime[i] = false;
            }
        }
    }

    std::vector<int> primes;
    for(int num = 2; num <= limit; ++num){
        if (isPrime[num]){
            primes.push_back(num);
        }
    }

    return primes;
}

int nthPrime(int n) {
    const int LIMIT = 200000;  // Adjust the limit based on the expected range of nth primes
    std::vector<int> primes = sieveOfEratosthenes(LIMIT);

    if (n > 0 && n <= primes.size()) {
        return primes[n - 1];  // Return the nth prime number
    } else {
        // If n is larger than the primes found within the limit, you may need to extend the limit.
        return -1;  // Error: nth prime not found within the given limit
    }
}

int main(){

    std::cout << nthPrime(10001);
    return 0;
}