#include <iostream>

using namespace std;

class Dollars {
private:
	int m_dollars;
public:
	Dollars(int dollars): m_dollars{dollars} {}

	int getDollars() { return m_dollars; }

	// Dollars + int
	Dollars operator+(int value);
};

Dollars Dollars::operator+(int value) {
	return Dollars(m_dollars + value);
}

int main(int argc, const char *argv[]) {
	Dollars d1(3);
	Dollars d2 = d1 + 11;
	cout << "I have " << d2.getDollars() << " dollars\n";
	
	return 0;
}