#include <iostream>

using namespace std;

class Values {
private:
	int m_min, m_max;
public:
	Values(int min, int max): m_min{min}, m_max{max} {}

	int getMin() { return m_min; }
	int getMax() { return m_max; }

	friend Values operator+(const Values &v1, const Values &v2);
	friend Values operator+(const Values &v, int value);
	friend Values operator+(int value, const Values &v);
};

Values operator+(const Values &v1, const Values &v2) {
	int min = v1.m_min < v2.m_min ? v1.m_min : v2.m_min;
	int max = v1.m_max > v2.m_max ? v1.m_max : v2.m_max;

	return Values(min, max);
}

Values operator+(const Values &v, int value) {
	int min = v.m_min < value ? v.m_min : value;
	int max = v.m_max > value ? v.m_max : value;

	return Values(min, max);
}

Values operator+(int value, const Values &v) {
	return v + value;
}

int main(int argc, const char *argv[]) {
	Values v1(11, 14);
	Values v2(7, 10);
	Values v3(4, 13);

	Values vFinal = v1 + v2 + 6 + 9 + v3 + 17;

	cout << "Result: (" << vFinal.getMin() << ", " << vFinal.getMax() << ")\n";
	
	return 0;
}