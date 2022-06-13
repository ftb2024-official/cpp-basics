#include <iostream>
#include <functional>

using namespace std;

int boo() {
	return 7;
}

/* --- Присваивание функции указателю на функции --- */
// int foo();
// double doo();
// int moo(int a, double b, bool c);

/* --- Вызов функции через указатель на функцию ---*/
int foo(int a) {
	return a;
}

int main() {
	// cout << reinterpret_cast<void*>(boo) << endl; // конвертация функции boo в указатель типа void

	/* --- Присваивание функции указателю на функции --- */
	// int (*funcPtr1)() = foo;
	// int (*funcPtr2)() = doo; // error
	// double (*funcPtr3)() = doo;
	// funcPtr1 = moo; // error
	// int (*funcPtr4)(int, double, bool) = moo;

	/* --- Вызов функции через указатель на функцию ---*/
	int (*funcPtr)(int) = foo; // function<int(int)> funcPtr = foo;
	cout << (*funcPtr)(11) << endl; // явное разыменование указателя на функцию
	cout << funcPtr(7) << endl; // неявное разыменование указателя на функцию

	return 0;
}
