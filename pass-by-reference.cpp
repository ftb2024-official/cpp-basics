#include <iostream>
#include <math.h>

using namespace std;

// void foo(int &value) {
// 	value = 11;
// }

void getSinCos(double degrees, double &sinOut, double &cosOut) {
	const double pi = 3.14159;
	double radians = degrees * pi / 180.0;

	sinOut = sin(radians);
	cosOut = cos(radians);
}

int main() {
	// int a = 3;
	
	// cout << "value = " << a << endl;
	// foo(a);
	// cout << "value = " << a << endl;

	// возврат сразу нескольких значений
	double sin(0.0);
	double cos(0.0);

	// функция getSinCos() возвратит sin и cos в переменные sin и cos
	getSinCos(30.0, sin, cos);

	cout << "The sin is: " << sin << endl;
	cout << "The cos is: " << cos << endl;

	return 0;
}