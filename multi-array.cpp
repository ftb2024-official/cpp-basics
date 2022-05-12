#include <iostream>

using namespace std;

int main() {
	const int numRows = 10;
	const int numCols = 10;
	int product[numRows][numCols] = {0};

	for(int row = 1; row <= numRows; ++row) {
		for(int col = 1; col <= numCols; ++col) {
			product[row][col] = row * col;
		}
	}

	for(int row = 1; row < numRows; ++row) {
		for(int col = 1; col < numCols; ++col)
			cout << product[row][col] << "\t";

		cout << "\n";
	}

	return 0;
}