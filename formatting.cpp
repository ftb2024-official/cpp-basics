#include <iostream>

using namespace std;

int add(int, int);

int main() {
	cout << "3 + 4 + 5 = " << add(3, 4) << endl;

	return 0;
}

int add(int a, int b, int c) {
	return a + b + c;
}