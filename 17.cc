#include <iostream>
#include <vector>

std::string translateToEnglish(int number) {
    std::vector<std::string> ones = {"zero", "one", "two", "three", "four", "five", "six",
        "seven", "eight", "nine", "ten", "eleven", "twelve","thirteen", "fourteen",
        "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    std::vector<std::string> tens = {"", "", "twenty", "thirty", "forty", "fifty", "sixty",
        "seventy", "eighty", "ninety"};

    if (0 <= number && number < 20)
        return ones[number];
    else if (20 <= number && number <= 90 && number % 10 == 0)
        return tens[number / 10];
    else if (20 < number && number < 100)
        return tens[number / 10] + "-" + ones[number % 10];
    else if (100 <= number && number <= 900 && number % 100 == 0)
        return ones[number / 100] + " hundred";
    else if (100 <= number && number < 1000)
        return ones[number / 100] + " hundred and " + translateToEnglish(number % 100);
    else if (number == 1000)
        return "One thousand";
    else
        return "Invalid Input";
}

int calculateTotalLetters(const std::string& englishNumber) {
	std::string newString = "";
	for(char letter : englishNumber) {
		if(letter != ' ' && letter != '-')
			newString += letter;
	}
	return newString.size();
}


int main() {
    int counter = 0;
    for(int i = 1; i <= 1000; i++) {
    	counter += calculateTotalLetters(translateToEnglish(i));
    }
    std::cout << counter << '\n';
    return 0;
}
