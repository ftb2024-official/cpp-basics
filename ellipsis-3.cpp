/*
	Функция findAverage с использованием строки-декодер
*/

#include <iostream>
#include <cstdarg>

using namespace std;

double findAverage(string decoder, ...) {
	double sum = 0;

	va_list list;
	va_start(list, decoder);

	int count = 0;

	while(1) {
		char codetype = decoder[count];
		switch(codetype) {
			default:
			
			case '\0':
				va_end(list);
				return sum / count;
			
			case 'i':
				sum += va_arg(list, int);
				count++;
				break;

			case 'd':
				sum += va_arg(list, double);
				count++;
				break;
		}
	}
}

int main() {
	cout << findAverage("iiii", 1, 2, 3, 4) << endl;
	cout << findAverage("iiiii", 1, 2, 3, 4, 5) << endl;
	cout << findAverage("ididdi", 1, 2.2, 3, 3.5, 4.5, 5) << endl;

	return 0;
}