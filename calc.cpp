#include <iostream>

using namespace std;

int getUserInput() {
	int userInput;

	cout << "Enter an integer: ";
	cin >> userInput;

	return userInput;
}

int getMathOp() {
	int operation;

	cout << "Enter operator you want(1 = +; 2 = -; 3 = *; 4 = /): ";
	cin >> operation;

	return operation;
}

int calculateResult(int input1, int op, int input2) {
	if(op == 1) {
		return input1 + input2;
	} else if(op == 2) {
		return input1 - input2;
	} else if(op == 3) {
		return input1 * input2;
	} else if(op == 4) {
		return input1 / input2;
	} else {
		return -1;
	}
}

void printResult(int result) {
	cout << "Result is: " << result << endl;
}

int main() {
	int input1 = getUserInput();
	int op = getMathOp();
	int input2 = getUserInput();

	int result = calculateResult(input1, op, input2);

	printResult(result);

	return 0;
}