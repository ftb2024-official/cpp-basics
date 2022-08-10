#include <iostream>

using namespace std;

int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }

int main(int argc, const char *argv[]) {
	cout << "Enter a number: ";
	int a;
	cin >> a;

	cout << "Enter another number: ";
	int b;
	cin >> b;

	int op;
	do {
		cout << "Choose an operation (0 = add, 1 = subtract, 2 = multiply): ";
		cin >> op;
	} while(op < 0 || op > 2);

	int (*ptrFunc)(int, int) = nullptr;

	switch(op) {
		case 0: ptrFunc = add; break;
		case 1: ptrFunc = subtract; break;
		case 2: ptrFunc = multiply; break;
	}

	cout << "The result is: " << ptrFunc(a, b) << '\n';
	
	return 0;
}