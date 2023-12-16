#include <iostream>
#include <fstream>
#include <vector>
#include <string>

std::string addLargeNumbers(const std::vector<std::string>& numbers) {
    int carry = 0;
    std::string result;

    for (int i = 49; i >= 0; --i) {
        int sum = carry;

        for (const std::string& num : numbers) {
            sum += num[i] - '0';
        }

        result.insert(result.begin(), '0' + (sum % 10));
        carry = sum / 10;
    }

    while (carry > 0) {
        result.insert(result.begin(), '0' + (carry % 10));
        carry /= 10;
    }

    return result;
}

int main() {
    std::ifstream inputFile("input.txt");

    std::vector<std::string> numbers;
    std::string line;

    while (std::getline(inputFile, line)) {
        numbers.push_back(line);
    }

    inputFile.close();
    std::string sum = addLargeNumbers(numbers);
    std::cout << "The first ten digits of the sum are: " << sum.substr(0, 10) << std::endl;

    return 0;
}
