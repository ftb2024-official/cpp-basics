#include <iostream>

using namespace std;

int readNumber();
void writeAnswer(int);

int main() {
	int firstNum = readNumber();
	int secondNum = readNumber();

	int result = firstNum + secondNum;

	writeAnswer(result);

	return 0;
}