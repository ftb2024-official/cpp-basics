#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

int main() {
	array<int, 10> myArray = {3, 1, 6, 4, 7, 8, 0, 2, 5, 9};

	cout << "Initial array: ";
	for(const auto &num: myArray)
		cout << num << " ";

	// sort(myArray.begin(), myArray.end()); // сортировка массива по возрастанию
	sort(myArray.rbegin(), myArray.rend()); // сортировка массива по убыванию

	cout << "\nSorted array: ";
	for(const auto &num: myArray)
		cout << num << " ";

	return 0;
}