#include <iostream>

using namespace std;

/* zadanie 1 */
int factorial(int value) {
	if(value < 1)
		return 1;

	return factorial(value - 1) * value;
}

/* zadanie 2 */
int sumNumbers(int value) {
	if(value < 10)
		return value;
	else
		return sumNumbers(value / 10) + value % 10;
}

/* zadanie 3 */
void decToBin(int value) {
	if(value == 0)
		return;

	decToBin(value / 2);

	cout << value % 2;
}

int main() {
	cout << "Enter an integer: ";
	int n;
	cin >> n;

	cout << "Factorial of " << n << " = " << factorial(n);

	return 0;
}