#include <iostream>

using namespace std;

int main() {
	// int value = 7;

	// int *ptr = &value;
	// int **ptrptr = &ptr;

	// cout << **ptrptr << endl;

	// двумерные динамически выделенные массивы
	int **array = new int*[15]; // выделяем массив из 15 указателей типа int - это наши строки
	for(int count = 0; count < 15; ++count)
		array[count] = new int[7]; // это наши столбцы

	return 0;
}