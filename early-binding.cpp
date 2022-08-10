#include <iostream>

using namespace std;

int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }

int main(int argc, const char *argv[]) {
	int a;
	cout << "Enter a number: ";
	cin >> a;

	int b;
	cout << "Enter another number: ";
	cin >> b;

	int op;
	do {
		cout << "Enter an operation (0 = add, 1 = subtract, 2 = multiply): ";
		cin >> op;
	} while(op < 0 || op > 2);

	int result = 0;
	switch(op) {
		case 0: result = add(a, b); break;
		case 1: result = subtract(a, b); break;
		case 2: result = multiply(a, b); break;
	}

	cout << "The answer is: " << result << '\n';
	
	return 0;
}