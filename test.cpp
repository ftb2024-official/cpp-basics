#include <iostream>

using namespace std;

int& doubleValue(int a) {
	int value = a * 2;

	return value;
}

int main() {
	cout << doubleValue(5);

	return 0;
}