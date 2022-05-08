#include <iostream>

using namespace std;

int main() {
	int x = 5, y = 5;

	cout << x << " " << y << endl; // 5 5
	cout << "Prefix: " << ++x << " " << --y << endl; // Prefix: 6 4
	cout << x << " " << y << endl; // 6 4
	cout << "Postfix: " << x++ << " " << y-- << endl; // Postfix: 6 4
	cout << x << " " << y << endl; // 7 3

	return 0;
}