// Перегрузка функций - возможность определять несколько функций с одним и тем же именем, но с разными параметрами.

#include <iostream>

using namespace std;

int multiply(int a, int b) {
	return a * b;
}

double multiply(double a, double b) {
	return a * b;
}

int multiply(int a, int b, int c) {
	return a * c + b;
}

int main() {
	cout << multiply(2, 3) << endl;
	cout << multiply(2.3, 4.5) << endl;
	cout << multiply(1, 2, 3) << endl;

	return 0;
}