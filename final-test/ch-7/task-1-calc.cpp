#include <iostream>
#include <string>

using namespace std;

int getInteger() {
	cout << "Enter an integer: ";
	int a;
	cin >> a;

	return a;
}

char getOperation() {
	char op;
	cout << "Choose one of the operations(+, -, * or /): ";
	
	do {
		cin >> op;
	} while(op != '+' && op != '-' && op != '*' && op != '/');

	return op;
}

int add(int a, int b) {
	return a + b;
}

int subtract(int a, int b) {
	return a - b;
}

int multiply(int a, int b) {
	return a * b;
}

int divide(int a, int b) {
	return a / b;
}

typedef int(*arithmeticFunc)(int, int);

arithmeticFunc getArithmeticFunc(char op) {
	switch(op) {
		case '+': return add;
		case '-': return subtract;
		case '*': return multiply;
		case '/': return divide;
		default: return add;
	}
}

int main() {
	int a = getInteger();
	char op = getOperation();
	int b = getInteger();

	arithmeticFunc func = getArithmeticFunc(op);

	cout << a << " " << op << " " << b << " = " << func(a, b) << endl;


	return 0;
}