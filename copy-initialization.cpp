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

	int getNumerator() { return m_numerator; }
	void setNumerator(int value) { m_numerator = value; }

	friend ostream& operator<<(ostream &out, const Drob &drob1) {
		out << drob1.m_numerator << "/" << drob1.m_denominator << '\n';
		return out;
	}
};

Drob makeNegativ(Drob &drob2) {
	drob2.setNumerator(-drob2.getNumerator());
	return drob2;
}

int main(int argc, const char *argv[]) {
	Drob sixSeven(-6, 7);
	cout << makeNegativ(sixSeven);
	
	return 0;
}