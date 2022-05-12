#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	const int length = 6;
	int array[length] = {30, 60, 20, 50, 40, 10};

	cout << "Initial Array: ";

	for(int index = 0; index < length; ++index) {
		cout << array[index] << " ";
	}

	cout << "\n";

	// перебираем каждый элемент массива (кроме последнего, он уже будет отсортирован к тому времени, когда мы до него доберемся)
	for(int startIndex = 0; startIndex < length - 1; ++startIndex) {
		// в переменной (smallestIndex) хранится индекс наименьшего значения, которое мы нашли в этой итерации.
		// начинаем с того, что наименьший элемент в этой итерации - это первый элемент (индекс 0)
		int largestIndex = startIndex;

		// ищем элемент поменьше в остальной части массива
		for(int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex) {
			// если мы нашли элемент, который меньше нашего наименьшего элемента
			if(array[currentIndex] > array[largestIndex])
				// то запоминаем его
				largestIndex = currentIndex;
		}

		swap(array[startIndex], array[largestIndex]);

		for(int index = 0; index < length; ++index) {
			cout << "\t" << array[index] << " ";
		}

		cout << "\n";
	}

	cout << "Sorted Array: ";

	for(int index = 0; index < length; ++index) {
		cout << array[index] << " ";
	}

	return 0;
}