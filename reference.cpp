/*
	Ссылка - тип переменной в языке С++, который работает как псевдоним другого объекта или значения. Типы: ссылки на неконстантные значения, ссылки на константные значения, ссылки r-value.
*/

#include <iostream>

using namespace std;

void changeInput(int &ref) {
	ref *= ref;
}

int main() {
	cout << "Enter an integer: ";
	int num;
	cin >> num;

	changeInput(num);

	cout << "Your input: " << num << ", right ;)" << endl;

	return 0;
}