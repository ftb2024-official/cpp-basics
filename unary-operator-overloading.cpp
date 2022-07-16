#include <iostream>

using namespace std;

class Something {
private:
	double m_a, m_b, m_c;
public:
	Something(double a = 0.0, double b = 0.0, double c = 0.0): m_a{a}, m_b{b}, m_c{c} {}

	Something operator-() const {
		return Something(-m_a, -m_b, -m_c);
	}

	bool operator!() const {
		return (m_a == 0 && m_b == 0 && m_c == 0.0);
	}

	double getA() { return m_a; }
	double getB() { return m_b; }
	double getC() { return m_c; }
};

int main(int argc, const char *argv[]) {
	Something smth(1, 2, 3);

	if(!smth)
		cout << "Smth is null!\n";
	else
		cout << "Smth isn't null!\n";
	
	return 0;
}