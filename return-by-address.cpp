#include <iostream>

using namespace std;

int* allocateArray(int size) {
	return new int[size];
}

int main() {
	int *array = allocateArray(20);

	delete[] array;

	return 0;
}