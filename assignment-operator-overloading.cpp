// перегрузка оператора присваивания выполняется через метод класса
#include <iostream>
#include <cassert>

using namespace std;

class Drob {
private:
	int m_numerator, m_denominator;
public:
	Drob(int numerator = 0, int denominator = 1): m_numerator{numerator}, m_denominator{denominator} {
		assert(denominator != 0);
	}

	Drob(const Drob &drob): m_numerator{drob.m_numerator}, m_denominator{drob.m_denominator} {
		cout << "Copy constructor worked here\n";
	}

	Drob& operator=(const Drob &drob1) {
		m_numerator = drob1.m_numerator;
		m_denominator = drob1.m_denominator;
		return *this;
	}

	friend ostream& operator<<(ostream &out, const Drob &drob2) {
		out << drob2.m_numerator << "/" << drob2.m_denominator << '\n';
		return out;
	}
};

int main(int argc, const char *argv[]) {
	Drob d1(6, 7);
	Drob d2(8, 3);
	Drob d3(10, 4);

	d1 = d2 = d3;

	cout << d1;
	
	return 0;
}