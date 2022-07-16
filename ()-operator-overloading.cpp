// перегрузка оператора () осуществляется через метод класса
#include <iostream>
#include <cassert>

using namespace std;

class Matrix {
private:
	double data[5][5];
public:
	Matrix() {
		for(int row = 0; row < 5; ++row)
			for(int col = 0; col < 5; ++col)
				data[row][col] = 0.0;
	}

	double& operator()(int row, int col);
	const double& operator()(int row, int col) const;
	void operator()();
};

double& Matrix::operator()(int row, int col) {
	assert(row >= 0 && row < 5);
	assert(col >= 0 && col < 5);
	
	return data[row][col];
}

const double& Matrix::operator()(int row, int col) const {
	assert(row >= 0 && row < 5);
	assert(col >= 0 && col < 5);
	
	return data[row][col];
}

void Matrix::operator()() {
	for(int row = 0; row < 5; ++row)
		for(int col = 0; col < 5; ++col)
			data[row][col] = 0.0;
}

int main(int argc, const char *argv[]) {
	Matrix matrix;

	matrix(2, 3) = 3.7;
	matrix();
	cout << matrix(2, 3) << endl;
	
	return 0;
}