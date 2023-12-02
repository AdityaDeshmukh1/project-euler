#include <bits/stdc++.h>

const int ROWS = 20;
const int COLS = 20;
int grid[ROWS][COLS];

int readFile() {
	std::ifstream inputFile("input.txt");
	std::string line;
	
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			 if (!(inputFile >> grid[i][j])) {
                std::cerr << "Error reading from file." << std::endl;
                return 1;
            }
		}
	}

	inputFile.close();
	return 0;
}

int maxProduct(int x, int y, int dx, int dy){
	int product = 1;
	for (int i = 0; i < 4; ++i) {
		product *= grid[x + (i * dx)][y + (i * dy)];
	}
	return product;
}

int maxGridProduct() {
	int maxProduct1 = 0;

	for (int i = 0; i < ROWS; ++i) {
		for (int j = 0; j < COLS; ++j) {
			// Horizontal
			if (j + 3 < COLS) 
				maxProduct1 = std::max(maxProduct1, maxProduct(i, j, 0, 1));
			if (i + 3 < ROWS)
				maxProduct1 = std::max(maxProduct1, maxProduct(i, j, 1, 0));
			if (i + 3 < ROWS && j + 3 < COLS)
				maxProduct1 = std::max(maxProduct1, maxProduct(i, j, 1, 1));
			if (i + 3 < ROWS && j - 3 >= 0)
				maxProduct1 = std::max(maxProduct1, maxProduct(i, j, 1, -1));
		}
	}
	return maxProduct1;
}

int main() {
	readFile();
	std::cout << maxGridProduct() << std::endl;

	return 0;
}