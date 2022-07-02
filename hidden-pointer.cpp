#include <iostream>

using namespace std;

class Another {
private:
	int m_number;
public:
	Another(int number) {
		setNumber(number);
	}

	void setNumber(int num) {
		m_number = num;
	}

	int getNumber() { return m_number; }
};

// во время компиляции класс Another превратится в следующее
// example
// void setNumber(Another *const THIS, int num) {
// 	THIS -> m_number = num;
// }

class Mathem {
private:
	int m_value;
public:
	Mathem(): m_value{0} {}

	Mathem& add(int value) { m_value += value; return *this; }
	Mathem& sub(int value) { m_value -= value; return *this; }
	Mathem& mult(int value) { m_value *= value; return *this; }

	int getValue() { return m_value; }
};

int main(int argc, const char *argv[]) {
	Another another(3);
	another.setNumber(7);

	cout << "another = " << another.getNumber() << endl;

	Mathem operation;
	operation.add(10).mult(0).sub(7);

	cout << "result: " << operation.getValue() << "\n";
	
	return 0;
}