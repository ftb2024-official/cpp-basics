#include <iostream>
#include <array>

using namespace std;

// возвращаем ссылку на элемент массива по индексу index
int& getElement(array<int, 20> &arr, int index) {
	// мы знаем, что array[index] не уничтожится, когда мы будем возвращать данные в caller (так как caller сам передал этот array в функцию)
	// так что не должно быть никаких проблем с возвратом по ссылке
	return arr[index];
}

int main() {
	array<int, 20> integerArray;

	// присваиваем элементу массива под индексом 15 значение 7
	getElement(integerArray, 15) = 7;

	cout << integerArray[15];

	return 0;
}