#include <iostream>
#include "add.h"
#define NAME "KHOJIAKBAR"

using namespace std;

int main() {
	cout << "Hi, my name is " << NAME << endl;
	cout << "3 + 4 = " << add(3, 4) << endl;
	cout << "3 - 4 = " << sub(3, 4) << endl;
	cout << "3 * 4 = " << multiply(3, 4) << endl;
	cout << "12 / 4 = " << divide(3, 4) << endl;

	return 0;
}