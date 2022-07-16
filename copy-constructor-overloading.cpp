#include <iostream>
#include <cassert>

using namespace std;

class Drob {
private:
	int m_numerator, m_denominator;

	// конструктор копирования
	Drob(const Drob &drob): m_numerator{drob.m_numerator}, m_denominator{drob.m_denominator} {
		cout << "Copy Constructor worked here\n";
	}
public:
	// конструктор по умолчанию
	Drob(int numerator = 0, int denominator = 1): m_numerator{numerator}, m_denominator{denominator} {
		assert(denominator != 0);
	}

	friend ostream& operator<<(ostream &out, const Drob &d1);
};

ostream& operator<<(ostream &out, const Drob &d1) {
	out << d1.m_numerator << "/" << d1.m_denominator << '\n';
	return out;
}

int main(int argc, const char *argv[]) {
	Drob drCopy(Drob(4, 3));

	cout << drCopy;
	
	return 0;
}