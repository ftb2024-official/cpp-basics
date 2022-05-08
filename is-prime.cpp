#include <iostream>

using namespace std;

int main() {
	cout << "Enter an integer less than 10: ";
	int digit;
	cin >> digit;

	if(digit == 2 or digit == 3 or digit == 5 or digit == 7) {
		cout << "The given digit is PRIME";
	} else {
		cout << "The given digit is NOT PRIME";
	}

	return 0;
}