#include <iostream>

using namespace std;

void setNull(int *tempPtr) {
	tempPtr = nullptr; // присваиваем tempPtr другое значение (мы не изменяем значение, на которое указывает tempPtr)
}

int main() {
	int six = 6;
	int *ptr = &six;

	cout << *ptr << endl;

	setNull(ptr); // tempPtr получит копию ptr

	if(ptr)
		cout << *ptr << endl;
	else
		cout << "ptr is null!";

	return 0;
}