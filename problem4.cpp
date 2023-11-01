#include <iostream>

bool isPalindrome(int num) {
    int r, sum = 0, temp;
    temp = num;
    while (num > 0) {
        r = num % 10;
        sum = (sum * 10) + r;
        num = num / 10;
    }
    return temp == sum;
}

int largestPalindrome(int num1, int num2) {
    int largest = 0;
    for (int i = num1; i > 0; i--) {
        for (int j = num2; j > 0; j--) {
            int product = i * j;
            if (product > largest && isPalindrome(product)) {
                largest = product;
            }
        }
    }
    return largest;
}

int main() {
    int result = largestPalindrome(999, 999);
    std::cout << "Largest Palindrome: " << result << '\n';

    return 0;
}
