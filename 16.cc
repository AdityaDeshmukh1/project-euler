#include <iostream>
#include <vector>

std::vector<int> dub(std::vector<int> nums) {
	std::vector<int> result = {};
	int carry = 0;
	int temp = 0;

	for(int i = static_cast<int>(nums.size()) - 1; i >= 0; i-- ) {
		temp = nums[i]*2 + carry;
		if(temp >= 10) carry = 1;
		else carry =0;

		result.insert(result.begin(), temp%10);
	}

	if(carry) result.insert(result.begin(), carry);

	return result;
}

int main() {
	std::vector<int> curr = {1};
	int sum = 0;

	for(size_t i = 0; i < 1000; i++) {
		curr = dub(curr);
	}

	for(int digit : curr) sum += digit;
	std::cout << sum << '\n';
	return 0;
}