#include <iostream>

using namespace std;

int getInteger();

int main() {
	int x = getInteger();
	int y = getInteger();

	cout << x << " + " << y << " = " << x + y;

	return 0;
}