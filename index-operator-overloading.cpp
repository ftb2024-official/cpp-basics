#include <iostream>

using namespace std;

class IntArray {
private:
	int m_array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
public:
	int& operator[](const int index);
	const int& operator[](const int index) const;
};

int& IntArray::operator[](const int index) { return m_array[index]; }

const int& IntArray::operator[](const int index) const { return m_array[index]; }

int main(int argc, const char *argv[]) {
	IntArray array;
	array[4] = 7;
	cout << array[4] << endl;

	const IntArray cArray;
	// cArray[4] = 11;
	cout << cArray[4] << endl;
	
	return 0;
}