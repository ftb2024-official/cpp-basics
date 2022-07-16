#include <iostream>

using namespace std;

class Dollars {
private:
	int m_dollars;
public:
	Dollars(int dollars = 0): m_dollars{dollars} {}

	int getDollars() { return m_dollars; }
	void setDollars(int dollars) { m_dollars = dollars; }

	operator int() { return m_dollars; }
};

class Cents {
private:
	int m_cents;
public:
	Cents(int cents = 0): m_cents{cents} {}

	// conversion from Cents to Dollars
	operator Dollars() { return Dollars(m_cents / 100); }
};

void printDollars(Dollars dollar) {
	cout << dollar; // dollar is implicitly converted to int
}

int main(int argc, const char *argv[]) {
	Cents cents(700);
	printDollars(cents); // cents is implicitly converted to Dollars
	
	return 0;
}