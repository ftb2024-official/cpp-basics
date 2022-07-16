#include <iostream>
#include <string>

using namespace std;

class Car {
private:
	string m_company, m_model;
public:
	Car(string company, string model): m_company{company}, m_model{model} {}

	friend bool operator==(const Car &c1, const Car &c2);
	friend bool operator!=(const Car &c1, const Car &c2);
};

bool operator==(const Car &c1, const Car &c2) {
	return (c1.m_company == c2.m_company && c1.m_model == c2.m_model);
}

bool operator!=(const Car &c1, const Car &c2) {
	return !(c1.m_company == c2.m_company && c1.m_model == c2.m_model);
}

class Dollars {
private:
	int m_dollars;
public:
	Dollars(int dollars): m_dollars{dollars} {}

	friend bool operator>(const Dollars &d1, const Dollars &d2);
	friend bool operator>=(const Dollars &d1, const Dollars &d2);
	friend bool operator<(const Dollars &d1, const Dollars &d2);
	friend bool operator<=(const Dollars &d1, const Dollars &d2);
};

bool operator>(const Dollars &d1, const Dollars &d2) {
	return (d1.m_dollars > d2.m_dollars);
}
bool operator>=(const Dollars &d1, const Dollars &d2) {
	return (d1.m_dollars >= d2.m_dollars);
}
bool operator<(const Dollars &d1, const Dollars &d2) {
	return (d1.m_dollars < d2.m_dollars);
}
bool operator<=(const Dollars &d1, const Dollars &d2) {
	return (d1.m_dollars <= d2.m_dollars);
}

int main(int argc, const char *argv[]) {
	Car mustang("Ford", "Mustang");
	Car ferrari("Ferrari", "F40");

	if(mustang == ferrari)
		cout << "Mustang and Ferrari are the same\n";
	else
		cout << "Mustang and Ferrari aren't the same\n";
	
	Dollars seven(7);
	Dollars eleven(11);

	if(seven > eleven)
		cout << "Seven dollars are greater than eleven dollars\n";
	if(seven >= eleven)
		cout << "Seven dollars are greater than or equal to eleven dollars\n";
	if(seven < eleven)
		cout << "Seven dollars are smaller than eleven dollars\n";
	if(seven <= eleven)
		cout << "Seven dollars are smaller than or equal to eleven dollars\n";

	return 0;
}