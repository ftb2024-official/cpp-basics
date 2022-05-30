#include <iostream>

using namespace std;

void boo(int x) {
	cout << "x = " << x << endl;

	x = 10;

	cout << "x = " << x << endl;
}

int main() {
	int x = 7;
	cout << "main x = " << x << endl;

	boo(x);

	cout << "main x = " << x << endl;

	return 0;
}