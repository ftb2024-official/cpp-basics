#include <iostream>

using namespace std;

struct FractNumber {
	int numerator;
	int denominator;
};

double multiply(FractNumber fn1, FractNumber fn2) {
	int numerator = fn1.numerator * fn2.numerator;
	int denominator = fn1.denominator * fn2.denominator;
	double result = static_cast<double>(numerator) / denominator;

	return result;
}

int main() {
	FractNumber fract1;
	FractNumber fract2;

	cout << "First numerator: ";
	cin >> fract1.numerator;
	cout << "First denominator: ";
	cin >> fract1.denominator;

	cout << "Second numerator: ";
	cin >> fract2.numerator;
	cout << "Second denominator: ";
	cin >> fract2.denominator;

	cout << fract1.numerator << "/" << fract1.denominator << " * " << fract2.numerator << "/" << fract2.denominator << " = " << multiply(fract1, fract2) << endl;

	// cout << static_cast<double>(2) / 5 << endl;

	return 0;
}