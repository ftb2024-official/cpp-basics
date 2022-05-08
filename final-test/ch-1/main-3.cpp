#include <iostream>
#include "io.h"

using namespace std;

int main() {
	int firstNum = readNumber();
	int secondNum = readNumber();

	int result = firstNum + secondNum;

	writeAnswer(result);

	return 0;
}