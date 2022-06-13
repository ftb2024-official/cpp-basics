/*
	Функция findAverage с использованием контрольного значения -1
*/

#include <iostream>
#include <cstdarg>

using namespace std;

double findAverage(int first, ...) {
	// обработка первого значения
	double sum = first;

	// получаем доступ к эллипсису через va_list, поэтому объявляем переменную этого типа
	va_list list;

	// инициализируем va_list, используя va_start; первый параметр - это список, который нужно инициализировать
	// второй параметр - последний параметр, который не является эллипсисом
	va_start(list, first);

	int count = 1;

	while(1) {
		// используем va_arg для получения параметров из эллипсиса
		// первый параметр - это va_list, который мы используем
		// второй параметр - это ожидаемый тип параметров
		int arg = va_arg(list, int);

		if(arg == -1)
			break;

		sum += arg;
		count++;
	}

	// выполняем очистку va_list, когда уже сделали всё необходимое
	va_end(list);

	return sum / count;
}

int main() {
	cout << findAverage(1, 2, 3, 4, -1) << "\n";
	cout << findAverage(10, 20, 30, 40, 50) << "\n";

	return 0;
}