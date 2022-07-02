#include <iostream>
#include <cassert>

using namespace std;

class Massiv {
private:
	int *m_array;
	int m_length;
public:
	Massiv(int length) {
		assert(length > 0);

		m_array = new int[length];
		m_length = length;
	}
	~Massiv() { delete[] m_array; }

	void setValue(int index, int value) { m_array[index] = value; }

	int getValue(int index) { return m_array[index]; }

	int getLength() { return m_length; }
};

int main(int argc, const char *argv[]) {
	Massiv arr(15);

	for(int count = 0; count < arr.getLength(); ++count) {
		arr.setValue(count, count + 2);
	}

	cout << "The value of element 7 is: " << arr.getValue(7) << endl;
	
	return 0;
}
