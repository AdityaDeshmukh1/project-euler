//Super slow Bruteforce, implement memoization for this

#include <iostream>

long long nextCollatzTerm(long long n) {
    long long nextTerm = n%2 == 0 ? n/2 : 3*n + 1;
    return nextTerm;
}

int main() {
    int max = 0;
    int startingNum = 0;

    for(long long i = 1; i < 1000000; i++) {
        long long n = i;
        int counter = 0;

        while(n != 1) {
            n = nextCollatzTerm(n);
            counter++;
            std::cout << n << std::endl;
        }

        if(counter > max) {
            max = counter;
            startingNum = i;
        }
    }



    std::cout << "The starting number is: " << startingNum << std::endl;
    std::cout << "The length of the chain is: " << max << std::endl;
    return 0;
}