/*
	array - это массив, в котором мы проводим поиски.
	target - это искомое значение.
	min - это индекс минимальной границы массива, в котором мы осуществляем поиск.
	max - это индекс максимальной границы массива, в котором мы осуществляем поиск.
	Функция binarySearch() должна возвращать индекс искомого значения, если он обнаружен. В противном случае, возвращаем -1
*/
#include <iostream>

using namespace std;

int binarySearch(int *array, int target, int min, int max) {
	while(min <= max) {
		int middlePoint = min + ((max - min) / 2);

		if(array[middlePoint] > target)
			max = middlePoint - 1;
		else if(array[middlePoint] < target)
			min = middlePoint + 1;
		else
			return middlePoint;
	}

	return -1;
}

int main() {
	int arr[] = {4, 7, 9, 13, 15, 19, 22, 24, 28, 33, 37, 41, 43, 47, 50};
	int maxIndex = sizeof(arr) / sizeof(arr[0]) - 1;
	
	cout << "Enter a number: ";
	int num;
	cin >> num;

	int index = binarySearch(arr, num, 0, maxIndex);

	if(index >= 0)
		cout << "Good! Your value " << num << " is on position " << index << " in array!\n";
	else
		cout << "Fail! Your value " << num << " isn't in array!\n";

	return 0;
}