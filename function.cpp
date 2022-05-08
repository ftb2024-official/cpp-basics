#include <iostream>

using namespace std;

void doMath(int a) {
	int b = 5;
	cout << "doMath: a = " << a << " and b = " << b << endl; // a = 6 && b = 5

	a = 4;
	cout << "doMath: a = " << a << " and b = " << b << endl; // a = 4 && b = 5
}

int main() {
	int a = 6;
	int b = 7;

	cout << "main: a = " << a << " and b = " << b << endl; // a = 6 && b = 7

	doMath(a);
	cout << "main: a = " << a << " and b = " << b << endl; // a = 6 && b = 7

	return 0;
}