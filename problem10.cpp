#include <bits/stdc++.h>

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

int main(){
    long long ans = 0;
    std::vector<int> primes = sieveOfEratosthenes(2000000);
    for (long long num : primes){
        ans = ans + num;
    } 
    std::cout << ans;
}