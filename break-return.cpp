/*
	Оператор break завершает работу switch или цикла, а выполнение кода продолжается с первого стейтмента, который находится сразу же после этого switch или цикла.

	Оператор return завершает выполнение всей функции, в которой находится цикл, а выполнение продолжается в точке после вызова функции.
*/
#include <iostream>

using namespace std;

int breakOrReturn() {
	while(true) {
		cout << "Enter 'b' to break or 'r' to return: ";
		char br;
		cin >> br;

		// выполнение кода продолжится с первого стейтмента после цикла
		if(br == 'b')
			break;
		// выполнение return приведет к тому, что управление сразу возвратится в caller (в этом случае в функцию main())
		if(br == 'r')
			return 1;
	}

	// использование оператора break приведет к тому, что выполнение цикла продолжится здесь
	cout << "We broke out of the loop\n";

	return 0;
}

int main() {
	int returnedValue = breakOrReturn();

	cout << "Function 'breakOrReturn' returned: " << returnedValue << endl;

	return 0;
}