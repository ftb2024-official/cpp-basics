#include <iostream>

using namespace std;

int main() {
	int *ptr = new int;
	*ptr = 7;

	cout << ptr << endl;
	cout << sizeof(ptr) << endl;
	cout << sizeof(*ptr) << endl;
	cout << *ptr << endl;

	return 0;
}