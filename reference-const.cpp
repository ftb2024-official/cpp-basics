#include <iostream>

using namespace std;

void fn(const int &ref) {
	cout << ref;
}

int main() {
	// // инициализация ссылок на константы
	// int a = 7;
	// const int &ref1 = a; // ок: а - это неконстантное l-value

	// const int b = 11;
	// const int &ref2 = b; // ок: b - это константное l-value

	// const int &ref3 = 13; // ок: 13 - это r-value

	// /* ------- */
	// int value = 7;
	// const int &ref4 = value;

	// value = 11; // ok: value - это не константа
	// ref4 = 12; // нельзя: ref - это константа

	// // ссылки r-values
	// const int &ref = 3 + 4;
	// cout << ref;

	// константные ссылки в качестве параметров функции
	int x = 7;
	fn(x);

	const int y = 2;
	fn(y);

	fn(5);

	fn(x + y);

	return 0;
}