#include <iostream>
#include <cmath>
using namespace std;

#define SIZE 1000000

bool isSumOfPowers(int a) {
	int originalNum = a, sum = 0;
	while(a > 0) {
		sum = sum + pow((a % 10), 5);
		a = a/10; 
	}

	if(sum == originalNum) return true;
	else return false;
}

int allNums(int n) {
	int sum = 0;
	for(int i = 2; i < n; i++) {
		if(isSumOfPowers(i)) sum += i;
	}
	return sum;
}

int main() {
	cout << allNums(SIZE) << endl;
	return 0;
}