#include <iostream>

using namespace std;

double getValue() {
	while(true) {
		cout << "Enter a double value: ";
		double a;
		cin >> a;

		// проверка на предыдущее извлечение
		if(cin.fail()) { // если предыдущее извлечение оказалось неудачным
			cin.clear(); // возвращаем 'cin' в 'обычный' режим работы
			cin.ignore(32767, '\n'); // удаляем до 32767 символов из входного буфера вплоть до появления символа '\n'

			cout << "Oops. Invalid input! Please try again!\n";
		
		} else // если все хорошо, то возвращаем 'a'
			cin.ignore(32767, '\n');
			
			return a;
	}
}

char getOperator() {
	while(true) {
		cout << "Enter one of the following: +, -, *, or /: ";
		char sym;
		cin >> sym;
		cin.ignore(32767, '\n'); // удаляем до 32767 символов из входного буфера вплоть до появления символа '\n'

		// выполняем проверку значений
		if(sym == '+' || sym == '-' || sym == '*' || sym == '/')
			return sym;
		else
			cout << "Oops. Invalid input! Please try again!\n";
	}
}

void printResult(double a, char sym, double b) {
	switch(sym) {
		case '+': cout << a << " + " << b << " is " << a + b << endl; break;
		case '-': cout << a << " - " << b << " is " << a - b << endl; break;
		case '*': cout << a << " * " << b << " is " << a * b << endl; break;
		case '/': cout << a << " / " << b << " is " << a / b << endl; break;
		default: cout << "Smth went wrong: printResult() got an invalid operator!";
	}
}

int main() {
	double a = getValue();
	char sym = getOperator();
	double b = getValue();

	printResult(a, sym, '+');

	return 0;
}
