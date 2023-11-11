#include <cmath>
#include <iostream>
#include <bits/stdc++.h>

int sumOfSquares(int n){
    int ans = 0;
    for (int i = 1; i <= n; i++){
        ans += std::pow(i, 2);
    }
    return ans;
}

int squareOfSum(int n){
    int ans = 0;
    for (int i = 1; i <= n; i++){
        ans += i;
    }
    return std::pow(ans, 2);
}

int main(){
    int final = squareOfSum(100) - sumOfSquares(100) ;
    std::cout << final;

    return 0;
}