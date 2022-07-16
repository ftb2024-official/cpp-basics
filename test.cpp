#include <iostream>

using namespace std;

class Average {
private:
	int32_t m_total = 0;
	int8_t m_numbers = 0;
public:
	Average() {}

	friend ostream& operator<<(ostream &out, const Average &avg) {
		out << static_cast<double>(avg.m_total) / avg.m_numbers;
		return out;
	}

	Average& operator+=(int num) {
		m_total += num;
		++m_numbers;
		return *this;
	}
};

int main(int argc, const char *argv[]) {
	Average avg;

	avg += 5;
	cout << avg << '\n'; // 5 / 1 = 5

	avg += 9;
	cout << avg << '\n'; // (5 + 9) / 2 = 7

	avg += 19;
	cout << avg << '\n'; // (5 + 9 + 19) / 3 = 11

	avg += -9;
	cout << avg << '\n'; // (5 + 9 + 19 - 9) / 4 = 6

	(avg += 7) += 11;
	cout << avg << '\n'; // (5 + 9 + 19 - 9 + 7 + 11) / 6 = 7

	Average copy = avg;
	cout << copy << '\n';
	
	return 0;
}