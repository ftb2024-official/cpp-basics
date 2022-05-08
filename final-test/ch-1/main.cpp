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

int main() {
	int firstNum = readNumber();
	int secondNum = readNumber();

	int result = firstNum + secondNum;

	writeAnswer(result);

	return 0;
}