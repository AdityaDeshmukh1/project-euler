#include <iostream>
#include <unordered_map>

int findRecurringCycleLength(int numerator, int denominator) {
    std::unordered_map<int, int> remainderIndexMap;
    int remainder = numerator % denominator;
    int index = 0;

    while (remainder != 0 && remainderIndexMap.find(remainder) == remainderIndexMap.end()) {
        remainderIndexMap[remainder] = index;
        remainder = (remainder * 10) % denominator;
        index++;
    }

    if (remainder == 0) {
        return 0;  
    } else {
        int previousIndex = remainderIndexMap[remainder];
        return index - previousIndex;  
    }
}

int main() {
    int maxLength = 0;
    int maxNum = 0;
    for(int i = 1; i < 100000; i++) {
    	int cycleLength = findRecurringCycleLength(1, i);
    	if(cycleLength > maxLength) { 
    		maxLength = cycleLength;
    		maxNum = i;
    		}
    }
    std::cout << "The max length is : " << maxLength << " and the max number is : " << maxNum << std::endl;

    return 0;
}
