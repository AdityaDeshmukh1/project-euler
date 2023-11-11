#include <iostream>

int gcd(int a, int b){
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int lcm(int n){
    // lcm = a*b/gcd(a, b)
    int ans = 1;
    for (int i = 1; i < n - 1; i++){
        ans = (ans * (i+1))/gcd(ans, i + 1);
    }
    return ans;
}

int main(){
    int val = lcm(20);
    std::cout << val << '\n';

    return 0;
}