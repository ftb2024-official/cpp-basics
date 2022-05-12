#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	const int length = 9;
	int array[length] = {7, 5, 6, 4, 9, 8, 2, 1, 3};

	cout << "Initial Array: ";
	for(int index = 0; index < length; ++index) {
		cout << array[index] << " ";
	}
	cout << "\n";
	
	for(int iteration = 0; iteration < length - 1; ++iteration) {
		// последний элемент будет отсортирован в каждой последующей итерации цикла
		int endOfArrayIndex = length - iteration;

		// были ли выполнены замены в этой итерации
		bool swapped = false;

		for(int currentIndex = 0; currentIndex < endOfArrayIndex - 1; ++currentIndex) {
			if(array[currentIndex] > array[currentIndex + 1]) {
				swap(array[currentIndex], array[currentIndex + 1]);
				swapped = true;
			}
		}

		if(!swapped) {
			cout << "Early termination on " << iteration + 1 << "th iteration\n";
			break;
		}
	}

	cout << "Sorted Array: ";
	for(int index = 0; index < length; ++index) {
		cout << array[index] << " ";
	}

	return 0;
}