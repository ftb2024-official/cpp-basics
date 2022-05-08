#include <iostream>

using namespace std;

int main() {
	cout << "Input a keyboard character: ";

	char ch;
	cin >> ch;

	cout << ch << " has following ASCII code " << static_cast<int>(ch) << endl;

	return 0;
}