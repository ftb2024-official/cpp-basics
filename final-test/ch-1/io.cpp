#include <iostream>

using namespace std;

int readNumber() {
	int num;

	cout << "Enter an integer: ";
	cin >> num;

	return num;
}

void writeAnswer(int result) {
	cout << "Result is: " << result << endl;
}