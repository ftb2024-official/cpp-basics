/* --- Передача функций в качестве аргументов другим функциям ---*/

#include <iostream>
#include <algorithm>

using namespace std;

// третьим параметром является пользовательский выбор выполнения сортировки
void selectionSort(int *arr, int size, bool (*comparisonPtrFunc)(int, int)) {
	// перебираем каждый элемент массива
	for(int startIndex = 0; startIndex < size; ++startIndex) {
		// bestIndex - это индекс наименьшего/наибольшего элемента, который мы обнаружили до этого момента
		int bestIndex = startIndex;

		// ищем наименьший/наибольший элемент среди оставшихся в массиве (начинаем со startIndex + 1)
		for(int currentIndex = startIndex + 1; currentIndex < size; ++currentIndex) {
			// если текущий элемент меньше/больше нашего предыдущего найденного наименьшего/наибольшего элемента
			if(comparisonPtrFunc(arr[bestIndex], arr[currentIndex])) // сравнение выполняется здесь
				// то это наш новый наименьший/наибольший элемент в этой итерации
				bestIndex = currentIndex;
		}

		// меняем местами наш стартовый элемент с найденным наименьшим/наибольшим элементом
		swap(arr[startIndex], arr[bestIndex]);
	}
}

// функция сравнения, выполняющая сортировку в порядке возрастания
bool ascending(int a, int b) {
	return a > b; // меняем местами, если первый элемент больше второго
}

// функция сравнения, выполняющая сортировку в порядке убывания
bool descending(int a, int b) {
	return a < b; // меняем местами, если второй элемент больше первого
}

// функция выводит значения массива
void printArr(int *array, int size) {
	for(int index = 0; index < size; ++index)https://ravesli.com/urok-104-ukazateli-na-funktsii/#toc-3
		cout << array[index] << " ";

	cout << "\n";
}

bool evensFirstAsc(int a, int b) {
	// если "a" - чётное число, а "b" - нечётное, то "a" идет первым (обмен местами не требуется)
	if((a % 2 == 0) && !(b % 2 == 0))
		return false;

	// если "a" - нечётное число, а "b" - чётное, то "b" идет первым (обмен местами требуется)
	if(!(a % 2 == 0) && (b % 2 == 0))
		return true;

	return ascending(a, b);
}

bool oddsFirstAsc(int a, int b) {
	if((a % 2 != 0) && !(b % 2 != 0))
		return false;

	if(!(a % 2 != 0) && (b % 2 != 0))
		return true;

	return ascending(a, b);
}

bool evensFirstDesc(int a, int b) {
	// если "a" - чётное число, а "b" - нечётное, то "a" идет первым (обмен местами не требуется)
	if((a % 2 == 0) && !(b % 2 == 0))
		return false;

	// если "a" - нечётное число, а "b" - чётное, то "b" идет первым (обмен местами требуется)
	if(!(a % 2 == 0) && (b % 2 == 0))
		return true;

	return descending(a, b);
}

bool oddsFirstDesc(int a, int b) {
	if((a % 2 != 0) && !(b % 2 != 0))
		return false;

	if(!(a % 2 != 0) && (b % 2 != 0))
		return true;

	return descending(a, b);
}

int main() {
	int array[10] = {4, 8, 5, 0, 6, 2, 1, 3, 9, 7};

	// сортируем массив в порядке убывания, используя функцию descending()
	selectionSort(array, 10, evensFirstAsc);
	printArr(array, 10);

	// сортируем массив в порядке возрастания, используя функцию ascending()
	selectionSort(array, 10, evensFirstDesc);
	printArr(array, 10);

	return 0;
}
