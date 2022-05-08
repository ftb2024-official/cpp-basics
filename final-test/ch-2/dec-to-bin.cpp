#include <iostream>

using namespace std;

int printAndDecrementBit(int x, int pow) {
	// проверяем является ли 'x' больше определенного числа, умноженного на 2 и выводим бит
	if(x >= pow) {
		cout << "1";
	} else {
		cout << "0";
	}

	// если 'x' больше, чем число умноженное на 2, то вычитаем его из значения
	if(x >= pow) {
		return x - pow;
	} else {
		return x;
	}
}

int main() {
	cout << "Enter an integer between 0 and 255: ";
	int x;
	cin >> x;

	x = printAndDecrementBit(x, 128);
	x = printAndDecrementBit(x, 64);
	x = printAndDecrementBit(x, 32);
	x = printAndDecrementBit(x, 16);

	cout << " ";

	x = printAndDecrementBit(x, 8);
	x = printAndDecrementBit(x, 4);
	x = printAndDecrementBit(x, 2);
	x = printAndDecrementBit(x, 1);

	return 0;
}