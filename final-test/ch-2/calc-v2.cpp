#include <iostream>

using namespace std;

void calc(double n1, double n2, char op) {
	double result;

	if(op == 43) {
		result = n1 + n2;
	} else if(op == 45) {
		result = n1 - n2;
	} else if(op == 42) {
		result = n1 * n2;
	} else if(op == 47) {
		result = n1 / n2;
	}

	cout << n1 << " " << op << " " << n2 << " = " << result << endl;
}

int main() {
	cout << "Enter the first double value: ";
	double first;
	cin >> first;

	cout << "Enter the second double value: ";
	double second;
	cin >> second;

	cout << "Enter one of the following: +, -, *, or /: ";
	char op;
	cin >> op;

	calc(first, second, op);

	return 0;
}