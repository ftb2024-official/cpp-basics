#include <iostream>

using namespace std;

void passValue(int value) {
	value = 87;
}

void passArray(int array[]) {
	array[0] = 10;
	array[1] = 8;
	array[2] = 6;
	array[3] = 4;
	array[4] = 1;
}

int main() {
	int value = 1;
	cout << "before passValue(): " << value << endl;
	passValue(value);
	cout << "after passValue(): " << value << endl;

	int array[] {1, 4, 6, 8, 10};
	cout << "before passArray(): " << array[0] << " " << array[1] << " " << array[2] << " " << array[3] << " " << array[4] << endl;
	passArray(array);
	cout << "after passArray(): " << array[0] << " " << array[1] << " " << array[2] << " " << array[3] << " " << array[4] << endl;

	return 0;
}
