#include <iostream>

bool isPythagoreanTriplet(int a, int b, int c) {
    if(a*a + b*b == c*c) return true;
    else return false;
}

int specialPythagoreanTriplet() {
    for(int i = 1; i < 1000; i++) {
        for(int j = 1; j < 1000; j++) {
            for(int k = 1; k < 1000; k++) {
                if(isPythagoreanTriplet(i, j, k) && i + j + k == 1000)
                 return i*j*k;
            }
        }
    }
    return -1;
}

int main() {
    std::cout << specialPythagoreanTriplet() << '\n';
    return 0;
}